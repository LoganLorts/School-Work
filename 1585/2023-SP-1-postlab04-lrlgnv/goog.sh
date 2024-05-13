#!/bin/bash

if (( "$#" != 2 )); then
  echo "Usage: goog.sh WORD WEBSITE"
else
  wget -O "index.html" -q  "$2"
  num=$(cat "index.html" | grep -o "$1" | wc -l)
  echo "${1}: ${num}"
  rm index.html
  exit "$num"
fi
