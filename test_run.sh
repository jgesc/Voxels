set -e
make resources
make -j4
cd bin
./main
