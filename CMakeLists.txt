cmake_minimum_required(VERSION 3.3)
project(httpclientlib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        http_client_utils.hpp
        http_client_utils.cpp
        http_client.hpp
        http_client.cpp
        http_header.cpp
        new_line.hpp
        new_line.cpp
        )

include_directories(/usr/local/opt/openssl/include)

add_library(httpclientlib STATIC ${SOURCE_FILES})

target_link_libraries(httpclientlib tcpclientlib ssl crypto pthread stdc++)

target_include_directories(httpclientlib PUBLIC .)
