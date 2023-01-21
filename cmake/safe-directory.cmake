# Add the project as a safe directory by calling 'git --add safe.directory'
# If none arguments passed, adds root directory as default 
# param DIR: directory to add as safe
function(safe_directory)
    set(DIR ${CMAKE_SOURCE_DIR})
    if(NOT "${ARGV0}" STREQUAL "")
        set(DIR "${ARGV0}")
    endif()
    execute_process(COMMAND git config --global --add safe.directory ${DIR})
endfunction()
