rm -rf build/
mkdir build/
cd build/
echo "### Starting CMake... ###"
cmake ..
echo "### CMake OK. ###"
echo "### Starting make... ###"
make
echo "### make OK. ###"
echo "### executing program ###"
./my_shared_pointer_test