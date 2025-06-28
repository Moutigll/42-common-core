#!/bin/bash

GREEN="\033[1;32m"
RED="\033[1;31m"
RESET="\033[0m"

generate_random_list() {
	count=$1
	list=""
	for ((i = 0; i < count; i++)); do
		num=$((RANDOM % 10000))
		list="$list $num"
	done
	echo "$list"
}

check_sorted_output() {
	output="$1"
	after_line=$(echo "$output" | grep '^After:' | cut -d':' -f2)
	# Check if sorted
	prev=-1
	for n in $after_line; do
		if [ "$prev" -gt "$n" ]; then
			echo -e "${RED}Not sorted${RESET}"
			return 1
		fi
		prev=$n
	done
	echo -e "${GREEN}Sorted${RESET}"
	return 0
}

count=0
while [ $count -lt 10 ]; do
	if [ $count -lt 3 ]; then
		size=$((3000 + RANDOM % 2000)) # at least 3 lists > 3000
	else
		size=$((RANDOM % 3000 + 10)) # other lists between 10 and 3000
	fi

	args=$(generate_random_list "$size")
	output=$(./PmergeMe $args 2>/dev/null)

	status=$(check_sorted_output "$output")
	vector_time=$(echo "$output" | grep 'vector')
deque_time=$(echo "$output" | grep 'deque')

	echo "#$((count + 1)): $status"
	echo "    $vector_time"
	echo "    $deque_time"
	echo

	((count++))
done
