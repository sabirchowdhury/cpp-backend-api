rmdir build
cmake -Bbuild -S . -DCMAKE_TOOLCHAIN_FILE=C:/Users/User/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --target ALL_BUILD --config Release
start build/Release/main.exe