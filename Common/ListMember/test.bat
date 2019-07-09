@echo off
if "%1"=="Debug" (
generate_CMakeLists Debug
cmake .
msbuild /p:Configuration=Debug test.vcxproj
Debug\test
) else (
generate_CMakeLists ListMember
cmake .
)
