set(APPCLI_TARGET appcli)
project(${APPCLI_TARGET} CXX)

include(sources.cmake)
add_executable(${APPCLI_TARGET} ${APPCLI_SOURCES})

set_property(TARGET ${APPCLI_TARGET} PROPERTY OUTPUT_NAME appcli)
target_compile_features(${APPCLI_TARGET} PRIVATE cxx_std_17)
