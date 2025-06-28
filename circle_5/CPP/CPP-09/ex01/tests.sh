#!/bin/bash

BINARY=./RPN
TMP_OUT=tmp_output.txt
TMP_EXPECTED=tmp_expected.txt

GREEN="\033[1;32m"
RED="\033[1;31m"
NC="\033[0m"

declare -A tests

# Basic Operations
tests["3 4 +"]="7"
tests["5 2 -"]="3"
tests["6 3 *"]="18"
tests["8 4 /"]="2"

# Mixed Operations
tests["4 2 + 3 -"]="3"
tests["3 5 * 2 /"]="7.5"
tests["7 3 + 5 2 - *"]="30"
tests["9 3 / 4 2 + *"]="18"

# Complex Expressions
tests["2 3 4 * +"]="14"
tests["5 1 2 + 4 * + 3 -"]="14"
tests["9 5 3 + 2 * +"]="25"
tests["4 2 5 * + 1 3 - /"]="-7"

# Edge Cases
tests["1"]="1"
tests["0 5 *"]="0"
tests["5 0 /"]="Error"
tests["1 2 3 +"]="Error"
tests["+"]="Error"
tests["1 +"]="Error"

# Multi-digit Handling (Should fail)
tests["10 2 +"]="Error"
tests["123 45 +"]="Error"

# Invalid Expressions
tests["1 2 &"]="Error"
tests["a b +"]="Error"
tests[" "]=$'Error'
tests["1 2 + 3"]="Error"
tests["(1 + 1)"]="Error"

# Example Tests from Subject
tests["8 9 * 9 - 9 - 9 - 4 - 1 +"]="42"
tests["7 7 * 7 -"]="42"
tests["1 2 * 2 / 2 * 2 4 - +"]="0"

# Floating Point Results
tests["5 2 /"]="2.5"
tests["1 2 / 4 *"]="2"

tests["9 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 *"]="362880"

total=0
passed=0

echo -e "${GREEN}Running RPN tests...${NC}"

for input in "${!tests[@]}"; do
	((total++))
	expected="${tests[$input]}"

	echo "$expected" > "$TMP_EXPECTED"
	
	if [[ "$input" == " " ]]; then
		$BINARY "" > "$TMP_OUT" 2>&1
	else
		$BINARY "$input" > "$TMP_OUT" 2>&1
	fi
	
	if [[ "$expected" == "Error" ]]; then
		if grep -qi "Error" "$TMP_OUT"; then
			echo -e "[${GREEN}PASS${NC}] \"$input\""
			((passed++))
		else
			echo -e "[${RED}FAIL${NC}] \"$input\""
			echo "Expected error but got:"
			cat "$TMP_OUT"
		fi
	else
		if diff -q "$TMP_EXPECTED" "$TMP_OUT" > /dev/null; then
			echo -e "[${GREEN}PASS${NC}] \"$input\""
			((passed++))
		else
			echo -e "[${RED}FAIL${NC}] \"$input\""
			echo "Expected: $expected"
			echo "Got:	  $(cat $TMP_OUT)"
		fi
	fi
done

rm -f "$TMP_OUT" "$TMP_EXPECTED"

echo -e "\nResult: ${GREEN}$passed${NC}/$total passed."
