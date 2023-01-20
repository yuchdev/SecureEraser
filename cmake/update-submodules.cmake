function(update_submodules)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules")
        if (NOT ARGC)
            execute_process(COMMAND git submodule update --init --recursive
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        else()
            execute_process(COMMAND git submodule init ${ARGV}
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
            execute_process(COMMAND git submodule update --recursive ${ARGV}
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        endif()
    else()
        message(WARNING ".gitmodules file not found in ${CMAKE_CURRENT_SOURCE_DIR}.")
    endif()
endfunction()
