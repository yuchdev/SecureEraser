cmake_minimum_required(VERSION 3.12.0)
set(APPCLI_TARGET appcli)

include(sources.cmake)

add_executable(APPCLI_TARGET APPCLI_SOURCES)
add_executable(APPCLI_TARGET::exe ALIAS APPCLI_TARGET)

set_property(TARGET {$APPCLI_TARGET} PROPERTY OUTPUT_NAME appcli)
target_compile_features({$APPCLI_TARGET} PRIVATE cxx_std_17)
