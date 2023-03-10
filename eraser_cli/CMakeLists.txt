# ---- Project header ----
set(ERASER_CLI_TARGET eraser_cli)
project(${ERASER_CLI_TARGET} CXX)

# ---- Frameworks and components ----
find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS program_options REQUIRED)

# ---- Target ----
# Load APPCLI_SOURCES
include(sources.cmake)

# Create the application target
add_executable(${ERASER_CLI_TARGET} ${ERASER_CLI_SOURCES})

# ---- Global properties ----

# ---- Cross-compiler options ----
# Set C++17 as the standard
target_compile_features(${ERASER_CLI_TARGET} PUBLIC cxx_std_17)

# ---- System-specific options ----

# ---- Include directories ----
target_include_directories(${ERASER_CLI_TARGET}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        ${CMAKE_SOURCE_DIR}/plog/include
        ${CMAKE_SOURCE_DIR}/eraser/include
        ${CMAKE_SOURCE_DIR}/winapi-helpers/include
        ${Boost_INCLUDE_DIRS}
)

# ---- Library dependencies ----
target_link_libraries(${ERASER_CLI_TARGET}
    PRIVATE
        ${Boost_LIBRARIES}
        eraser
)

# ---- Enable testing ----
# We use Boost Test, so include it only if Boost root is known
add_subdirectory(test/functional)


# ---- Additional build steps ----

# ---- Install rules ----
