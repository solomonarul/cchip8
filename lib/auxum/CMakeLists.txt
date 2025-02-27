cmake_minimum_required(VERSION 3.19)

project(auxum)

file(
    GLOB_RECURSE
    ${PROJECT_NAME}_SRC
        "src/*.c"
)

file(
    GLOB_RECURSE
    ${PROJECT_NAME}_TEST_SRC
        "test/*.c"
)

add_library(
    ${PROJECT_NAME}
    ${${PROJECT_NAME}_SRC}
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        "inc/"
    PRIVATE
        "inc/auxum"
)

target_compile_definitions(
    ${PROJECT_NAME}
    PRIVATE
        BUILD_TYPE_${CMAKE_BUILD_PLATFORM}
)

set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY C_STANDARD 23
)

if(CMAKE_BUILD_PLATFORM MATCHES "WINDOWS")
find_package(SDL3 REQUIRED PATHS ${SDL3_PATH})
else()
find_package(SDL3 REQUIRED)
endif()
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
        SDL3::SDL3
)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
add_executable(
    ${PROJECT_NAME}_test
    ${${PROJECT_NAME}_TEST_SRC}
)

if(MSVC)
    target_compile_options(${PROJECT_NAME}_test PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME}_test PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

target_link_libraries(
    ${PROJECT_NAME}_test
    PUBLIC
        ${PROJECT_NAME}
)

target_compile_definitions(
    ${PROJECT_NAME}_test
    PRIVATE
        BUILD_TYPE_${CMAKE_BUILD_PLATFORM}
)

set_property(
    TARGET ${PROJECT_NAME}_test
    PROPERTY C_STANDARD 23
)
endif()

