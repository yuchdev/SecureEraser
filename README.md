## File Secure Eraser

### Build

Generate CMake config files, and run build using the active toolset (MSVC for Windows, Ninja for Linux)

### Windows

```
cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_SYSTEM_VERSION=6.1
```

### Windows with DLL configuration

```
cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_SYSTEM_VERSION=10 -DBUILD_SHARED_LIBS=ON
```

### Windows with custom submodules list

```
cd cm	 -DCMAKE_SYSTEM_VERSION=10 -DUSE_MODULES="winapi-helpers;eraser;plog"
```

### Linux

```
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
```

### Build using active toolchain
```
cmake --build . --clean-first --config Debug --parallel 4 --verbose
```

### Using with Conan
```
python -m conan install . --profile conan/profiles/windows_msvc_16_release
call activate.bat
cmake ..  -DCMAKE_BUILD_TYPE=Release -DCMAKE_MODULE_PATH=%CD:\=/%
cmake --build . --config Release
call deactivate.bat
```
