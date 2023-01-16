cmake_minimum_required(VERSION 3.12.0)

set(ANALYTICS_TARGET foundation)
include(sources.cmake)

add_library(${ANALYTICS_TARGET} ${ANALYTICS_SOURCES})

target_include_directories(${ANALYTICS_TARGET}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${COMMON_INCLUDE_DIR}"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_compile_features(${ANALYTICS_TARGET} PUBLIC cxx_std_17)

target_link_libraries(${FOUNDATION_TARGET}
    PUBLIC
        asenum
    PRIVATE
        plog::plog
        asio
        fmt
        curl
)

add_subdirectory(tests)
set_target_properties(foundation PROPERTIES FOLDER foundation)
