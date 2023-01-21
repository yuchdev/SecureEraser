# ---- Project header ----
cmake_minimum_required(VERSION 3.20)
include(cmake/prelude.cmake)
include(cmake/update-submodules.cmake)

project(
    secure_eraser
    VERSION 1.0.0
    DESCRIPTION "Secure file eraser for NTFS/exFAT file systems"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)
include(cmake/get-win32-winnt.cmake)
include(cmake/safe-directory.cmake)

# Set policies and stop the script on the first error
cmake_policy(SET CMP0046 NEW)
cmake_policy(SET CMP0065 NEW)

# Call the function with the submodules list passed in as a command line parameter, e.g.
# cmake .. -DUSE_MODULES="winapi-helpers eraser plog"
if (DEFINED USE_MODULES)
    set(USE_MODULES "${USE_MODULES}")
    string(REPLACE " " ";" USE_MODULES "${USE_MODULES}")
    update_submodules("${USE_MODULES}")
else()
    # Update all submodules if the parameter is not passed in
    update_submodules()
endif()

# Declare project directory safe by calling `git --add safe.directory`
safe_directory()

# ---- Global properties ----
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

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
