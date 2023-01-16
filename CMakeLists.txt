cmake_minimum_required(VERSION 3.20)

include(cmake/prelude.cmake)

project(
    cpp-template
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)
include(cmake/get-win32-winnt.cmake)

# ---- Declare executable ----
add_executable(cpp-template_exe src/main.cpp)
add_executable(cpp-template::exe ALIAS cpp-template_exe)

set_property(TARGET cpp-template_exe PROPERTY OUTPUT_NAME cpp-template)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

target_compile_features(cpp-template_exe PRIVATE cxx_std_17)

# ---- Install rules ----
if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

include(CTest)
enable_testing()

if(WIN32)
    get_win32_winnt(ver)
    add_definitions(-D_WIN32_WINNT=${ver})
endif()

add_subdirectory(common)
add_subdirectory(appcli)
add_subdirectory(analytics)
add_subdirectory(statistics)
