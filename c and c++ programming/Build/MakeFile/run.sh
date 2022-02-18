if [ -z "$1" ]
then
    echo -e "\033[91musage $0 <build|clean>\033[0m"
elif [ $1 == "clean" ]
then
   make clean
elif [ $1 == "build" ]
then
    make
else
  echo -e "\033[91musage $0 <build|clean>\033[0m"
fi