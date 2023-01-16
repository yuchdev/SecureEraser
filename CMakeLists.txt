cmake_minimum_required(VERSION 3.14)

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

# ---- Developer mode ----
if(NOT cpp-template_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of cpp-template"
  )
endif()

include(cmake/dev-mode.cmake)
include(CTest)
enable_testing()

if(WIN32)
    get_win32_winnt(ver)
    add_definitions(-D_WIN32_WINNT=${ver})
endif()
