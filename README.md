# Cmake-Template

This is my Cmake template created from Cmake tutorials
The aim for this repo was to learn how to build Cmake projects from scratch to more understand the process

## Usage
Copy libraries, src, CmakeLists.txt, TutorialConfig.h.in
to your project you want to use this on

in `src` goes your source files
in `libraries` goes your libraries
    Make own folder for each library and add their own `CMakeLists.txt`

in CMakeLists.txt update your details for the project and add the paths to your libraries.

If you want to use shared libraries, you can delete the lines for the STATIC LIBRARIES usage.

## Output file

By default it outputs the executable file in the source, but that can be modifiable from the `CMakeLists.txt`

```
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../")
```


## Static or shared libraries
By default, static libraries are being used, remove these lines from `CMakeLists.txt` to enable shared libraries

```
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")
```

## Adding a library
1. Make a new folder for the library in the `/libraries/` folder
2. Put the library files in there
3. Make a CMakeLists.txt file in the library and add the details for it:
```
# From /libraries/Utility/CMakeLists.txt
# ---

add_library(Utility Utility.cpp)
```
4. Add a line to top CMakeLists.txt
```
# From /CMakeLists.txt
# ---

add_subdirectory(libraries/Utility)
```
5. Update the included folders to look for the library aswell
```
# From /CMakeLists.txt
# ---

target_include_directories(main PUBLIC
                             "${PROJECT_BINARY_DIR}"
                             "${PROJECT_SOURCE_DIR}/libraries/Utility"
                             )
```
6. Include the library in your sourcecode!