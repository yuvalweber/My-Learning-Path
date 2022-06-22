#! /bin/bash
if [ -z $1 ]
then
  echo -e "\033[91m $0 <executable>\033[0m"
  exit 1
fi
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ../my_strace $1