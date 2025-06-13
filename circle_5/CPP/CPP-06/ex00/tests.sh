#!/bin/bash

BINARY=./convert
TMP_OUT=tmp_output.txt
TMP_EXPECTED=tmp_expected.txt

GREEN="\033[1;32m"
RED="\033[1;31m"
NC="\033[0m"

declare -A tests

tests["0"]="char: Non displayable
int: 0
float: 0.0f
double: 0.0"

tests["-42"]="char: Non displayable
int: -42
float: -42.0f
double: -42.0"

tests["42"]="char: '*'
int: 42
float: 42.0f
double: 42.0"

tests["4.2"]="char: Non displayable
int: 4
float: 4.2f
double: 4.2"

tests["-4.2"]="char: Non displayable
int: -4
float: -4.2f
double: -4.2"

tests["4.2f"]="char: Non displayable
int: 4
float: 4.2f
double: 4.2"

tests["-4.2f"]="char: Non displayable
int: -4
float: -4.2f
double: -4.2"

tests["nan"]="char: impossible
int: impossible
float: nanf
double: nan"

tests["nanf"]="char: impossible
int: impossible
float: nanf
double: nan"

tests["+inf"]="char: impossible
int: impossible
float: inff
double: inf"

tests["-inf"]="char: impossible
int: impossible
float: -inff
double: -inf"

tests["+inff"]="char: impossible
int: impossible
float: inff
double: inf"

tests["-inff"]="char: impossible
int: impossible
float: -inff
double: -inf"

tests["a"]="char: 'a'
int: 97
float: 97.0f
double: 97.0"

tests["non_numeric"]="Error: Invalid literal."

tests["2147483648"]="char: Non displayable
int: impossible
float: 2147483648.0f
double: 2147483648.0"

tests["128"]="char: Non displayable
int: 128
float: 128.0f
double: 128.0"

tests["127"]="char: Non displayable
int: 127
float: 127.0f
double: 127.0"

tests["-128"]="char: Non displayable
int: -128
float: -128.0f
double: -128.0"

tests["2147483647"]="char: Non displayable
int: 2147483647
float: 2147483648.0f
double: 2147483647.0"
#float representation of 2147483647 is 2147483648.0 due to precision limits

tests["-2147483648"]="char: Non displayable
int: -2147483648
float: -2147483648.0f
double: -2147483648.0"

total=0
passed=0

echo -e "${GREEN}Running ScalarConverter tests...${NC}"

for input in "${!tests[@]}"; do
	((total++))
	expected="${tests[$input]}"

	echo "$expected" > "$TMP_EXPECTED"
	$BINARY "$input" > "$TMP_OUT" 2>&1
	if diff -q "$TMP_EXPECTED" "$TMP_OUT" > /dev/null; then
		echo -e "[${GREEN}PASS${NC}] \"$input\""
		((passed++))
	else
		echo -e "[${RED}FAIL${NC}] \"$input\""
		diff -u "$TMP_EXPECTED" "$TMP_OUT"
	fi
done

rm -f "$TMP_OUT" "$TMP_EXPECTED"

echo -e "\nResult: ${GREEN}$passed${NC}/$total passed."
