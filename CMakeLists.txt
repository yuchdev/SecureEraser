cmake_minimum_required(VERSION 3.20)
include(cmake/prelude.cmake)

project(
    dsa_license_checker
    VERSION 0.1.0
    DESCRIPTION "Proof of concept of using DSA public key algorithm for software licensing"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)
include(cmake/get-win32-winnt.cmake)

# ---- Global properties ----
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ---- Install rules ----
if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Enable testing ----
include(CTest)
enable_testing()

# ---- System-specific flags ----
if(WIN32)
    get_win32_winnt(ver)
    add_definitions(-D_WIN32_WINNT=${ver})
endif()

# ---- Solution content ----
add_subdirectory(common)
add_subdirectory(appcli)
add_subdirectory(cryptography)
add_subdirectory(winapi-helpers)
