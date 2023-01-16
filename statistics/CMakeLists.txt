cmake_minimum_required(VERSION 3.12.0)

set(STATISTICS_TARGET statistics)
include(sources.cmake)

add_library(${STATISTICS_TARGET} ${STATISTICS_SOURCES})

target_include_directories(${STATISTICS_TARGET}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${COMMON_INCLUDE_DIR}"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_compile_features(${STATISTICS_TARGET} PUBLIC cxx_std_17)

target_link_libraries(${STATISTICS_TARGET}
    PUBLIC
        asenum
    PRIVATE
        plog::plog
        asio
        fmt
        curl
)

add_subdirectory(tests)
set_target_properties({$STATISTICS_TARGET} PROPERTIES FOLDER libraries)
