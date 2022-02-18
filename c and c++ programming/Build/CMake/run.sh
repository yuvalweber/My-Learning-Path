if [ -z $1 ] || [ -z $2 ]
then
  echo -e "\033[91musage: $0 <CMakeLocation> <MakeFileOutputLocation>\033[0m"
else
  cmake -S $1 -B $2
  echo "in order to build run: make -C $2"
fi