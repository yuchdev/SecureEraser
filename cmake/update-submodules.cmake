function(update_submodules submodules_list)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules")
        if ("${submodules_list}" STREQUAL "")
            execute_process(COMMAND git submodule update --init --remote --recursive
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        else()
            execute_process(COMMAND git submodule init ${submodules_list}
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
            execute_process(COMMAND git submodule update --recursive --remote ${submodules_list}
