set -e
make resources
make -j$(nproc)
cd bin
./main
