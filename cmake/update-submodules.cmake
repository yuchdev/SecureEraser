function(update_submodules submodules_list)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules")
        if ("${submodules_list}" STREQUAL "")
            execute_process(COMMAND git submodule update --init --recursive
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        else()
            execute_process(COMMAND git submodule init ${submodules_list}
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
            execute_process(COMMAND git submodule update --recursive ${submodules_list}
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        endif()
    else()
        message(WARNING ".gitmodules file not found in ${CMAKE_CURRENT_SOURCE_DIR}.")
    endif()
endfunction()
