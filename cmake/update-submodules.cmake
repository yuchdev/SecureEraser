# Update solution submodules
# Usage: update_submodules("winapi-helpers;eraser;plog")
# of update_submodules() for all submodules in .gitmodules
function(update_submodules)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules")
        if (NOT ARGC)
            execute_process(COMMAND git submodule update --init --recursive
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        else()
            set(USE_MODULES "${ARGV}")
            string(REPLACE " " ";" USE_MODULES "${USE_MODULES}")
            execute_process(COMMAND git submodule init ${USE_MODULES}
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
            execute_process(COMMAND git submodule update --recursive ${USE_MODULES}
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        endif()
    else()
        message(WARNING ".gitmodules file not found in ${CMAKE_CURRENT_SOURCE_DIR}.")
    endif()
endfunction()

# The function that calls "add_subdirectory(DIR)" only if DIR contains CMakeLists.txt
function(add_submodule DIR)
  file(GLOB files "${DIR}/*")
  if(IS_DIRECTORY ${DIR} AND files)
    add_subdirectory(${DIR})
  else()
    message( STATUS "Subdirectory " ${DIR} " not added as ${DIR}/CMakeLists.txt does not exists")
  endif()
endfunction()

