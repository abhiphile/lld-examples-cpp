cmake_minimum_required(VERSION 3.10)
project(UrlShortener)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(url_shortener
    src/main.cpp
    src/urlShortener.cpp
)
