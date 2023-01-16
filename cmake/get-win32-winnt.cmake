# define WIN32 macro version
# param version: output for Windows version, for example 0x0601 for Windows 7 SP1
macro(get_win32_winnt version)

    if (WIN32 AND CMAKE_SYSTEM_VERSION)
        set(ver ${CMAKE_SYSTEM_VERSION})
        string(REPLACE "." "" ver ${ver})
        string(REGEX REPLACE "([0-9])" "0\\1" ver ${ver})

        set(${version} "0x${ver}")
    endif()

endmacro(get_win32_winnt)
