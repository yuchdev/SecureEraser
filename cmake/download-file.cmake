# Download file
# param url: URL for the file to download
# param filename: save file as filename
function(download_file url filename)

    if(NOT EXISTS ${filename})
        file(DOWNLOAD ${url} ${filename} TIMEOUT 60)
    endif()

endfunction(download_file)
