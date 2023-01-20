# ---- Project header ----
cmake_minimum_required(VERSION 3.20)
include(cmake/prelude.cmake)

project(
    secure_eraser
    VERSION 1.0.0
    DESCRIPTION "Secure file eraser for NTFS/exFAT file systems"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)
include(cmake/get-win32-winnt.cmake)

# ---- Global properties ----
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# ---- Cross-compiler options ----

# ---- System-specific options ----
if(WIN32)
    get_win32_winnt(ver)
    add_definitions(-D_WIN32_WINNT=${ver})
endif()

# ---- Solution content ----
add_subdirectory(winapi-helpers)
add_subdirectory(eraser)
add_subdirectory(appcli)

# ---- Enable testing ----
include(CTest)
enable_testing()

# ---- Install rules ----
if(NOT CMAKE_SKIP_INSTALL_RULES)
    include(cmake/install-rules.cmake)
endif()
