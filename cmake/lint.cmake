cmake_minimum_required(VERSION 3.14)

# This function creates custom target for each of targets passed with the name ${target_name}_cppcheck
# It can be added as a dependency to the target to be checked like that:
# add_dependencies(${target_name}_cppcheck ${target_name})
function(run_cppcheck target include_dirs sources)
    set(include_flags "")
    foreach(dir ${include_dirs})
        set(include_flags "${include_flags} -I${dir}")
    endforeach()

    add_custom_command(
            OUTPUT ${target}.xml
            COMMAND cppcheck ${include_flags} ${sources} --xml-version=2 2> ${target}.xml
            DEPENDS ${sources}
            COMMENT "Running CppCheck on ${target} with include directories ${include_dirs} and sources ${sources}"
    )

    add_custom_target(${target}_cppcheck ALL DEPENDS ${target}.xml)
endfunction()
