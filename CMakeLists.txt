cmake_minimum_required(VERSION 3.11)
project(korelib)

set(CMAKE_CXX_STANDARD 20)

option(KORELIB_ENABLE_ASSERTIONS "Enable assertions" ON)

option(KORELIB_BUILD_SHARED "Build korelib as a dynamic library" OFF)
if(KORELIB_BUILD_SHARED)
    set(KORELIB_BUILD_TYPE SHARED)
else()
    set(KORELIB_BUILD_TYPE STATIC)
endif()

include(FetchContent)

FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt.git GIT_TAG 11.1.3)
FetchContent_Declare(backward GIT_REPOSITORY https://github.com/bombela/backward-cpp GIT_TAG v1.6)

FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(backward)

add_library(korelib ${KORELIB_BUILD_TYPE}
    Source/Assertion.hpp
    Source/Delegate.hpp
    Source/RuntimeException.hpp
    Source/RuntimeException.cpp
    Source/StandardStreamWrapper.hpp
)

target_link_libraries(korelib PUBLIC
    backward
    fmt
)

target_include_directories(korelib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Source
)

if (KORELIB_ENABLE_ASSERTIONS)
    target_compile_definitions(korelib PUBLIC
        KORELIB_ENABLE_ASSERTIONS
    )
endif()
