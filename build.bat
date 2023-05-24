mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make  
del CMakeCache.txt /Q
rmdir CMakeFiles /s /Q
del cmake_install.cmake /Q
del Makefile /Q