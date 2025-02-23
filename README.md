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