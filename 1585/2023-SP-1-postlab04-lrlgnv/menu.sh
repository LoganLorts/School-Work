#!/bin/bash

for file in *; do
    if [[ -f "$file"]]; then
        echo "v) View " "$file"
        echo "e) Edit" "$file"
        echo "c) Compile" "$file"
        echo "x) Execute" "$file"
        echo "q) Quit" "$file"
        read input
        case "$input" in
        v)
            less "$file"
            ;;
        e)
            nano "$file"
            ;;
        c)
            g++ "$file"
            ;;
        x)
            execute "$file"
            ;;
        q)
            exit
            ;;
        *)
            echo "INVALID RESPONSE"
            echo 
            echo "skipping this file"
            ;;
        esac
    fi
done


