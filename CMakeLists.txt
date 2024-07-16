cmake_minimum_required(VERSION 3.10)
project(AESEncryptionTool)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(AESEncryptionTool src/main.cpp src/cli.cpp src/aes.cpp src/file_io.cpp)

target_link_libraries(AESEncryptionTool OpenSSL::Crypto)