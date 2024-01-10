cmake_minimum_required(VERSION 3.14)

project(jisho_lib LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENSSL_ROOT_DIR D:/openssl/)

find_package(OpenSSL REQUIRED)

if (OpenSSL_FOUND)
    message("open ssl found")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Network)

FILE(GLOB_RECURSE SOURCES src/*.cpp headers/*.h headers/utils/*.h)

add_library(jisho_lib STATIC
${SOURCES}
)

add_subdirectory(tests)

target_link_libraries(jisho_lib Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network
    OpenSSL::SSL OpenSSL::Crypto)

target_include_directories(jisho_lib PUBLIC headers)
