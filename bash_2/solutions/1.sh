#!/usr/bin/env bash
declare -A requests_per_day

while read line; do
    if [[ $line == \#* ]]; then
        continue
    fi 

    fields=($line)

    date=${fields[0]}
    method=${fields[3]}
       
    if [[ $method == "GET" ]]; then
        requests_per_day[$date]=$((requests_per_day[$date] + 1))
    fi
done < logfile.txt 

for date in $(echo "${!requests_per_day[@]}" | tr ' ' '\n' | sort -n); do
    echo -e "${date}\t${requests_per_day[${date}]}"
done

