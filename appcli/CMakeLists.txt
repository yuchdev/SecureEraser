# ---- Project header ----
set(APPCLI_TARGET appcli)
project(${APPCLI_TARGET} CXX)

# ---- Frameworks and components ----
find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS program_options REQUIRED)

# ---- Target ----
# Load APPCLI_SOURCES
include(sources.cmake)

# Create the application target
add_executable(${APPCLI_TARGET} ${APPCLI_SOURCES})

# ---- Global properties ----

# ---- Cross-compiler options ----
# Set C++17 as the standard
target_compile_features(${APPCLI_TARGET} PUBLIC cxx_std_17)

# ---- System-specific options ----

# ---- Include directories ----
target_include_directories(${APPCLI_TARGET}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        ${CMAKE_SOURCE_DIR}/plog/include
        ${Boost_INCLUDE_DIRS}
)

# ---- Library dependencies ----
target_link_libraries(${APPCLI_TARGET}
    PRIVATE
        ${Boost_LIBRARIES}
        winapi_helpers
        eraser
)

# ---- Enable testing ----
# We use Boost Test, so include it only if Boost root is known
if(${BOOST_ROOT})
    add_subdirectory(test/functional_test)
endif()

# ---- Additional build steps ----

# ---- Install rules ----
