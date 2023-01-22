## File Secure Eraser

### Build

Generate CMake config files, and run build using the active toolset (MSVC for Windows, Ninja for Linux)

### Windows

```
cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug
```

### Windows with specific system version

```
cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_SYSTEM_VERSION=6.1
```

### Windows with custom Boost location

```
cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug -DBOOST_ROOT=C:/boost
```

### Windows with DLL configuration

```
cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON
```

### Windows with custom submodules list

```
cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug -DUSE_MODULES="winapi-helpers eraser plog"
```

### Linux

```
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
```

### Build using active toolchain
```
cmake --build . --config Debug --parallel 2 --verbose
```

### Clean rebuild using active toolchain
```
cmake --build . --clean-first --config Debug --parallel 2 --verbose
```

### Using with Conan
```
python -m conan install . --profile conan/profiles/windows_msvc_16_release
call activate.bat
cmake ..  -DCMAKE_BUILD_TYPE=Release -DCMAKE_MODULE_PATH=%CD:\=/%
cmake --build . --config Release
call deactivate.bat
```
