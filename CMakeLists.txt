cmake_minimum_required(VERSION 3.31)

project(cmakeTest VERSION 1.0)

# Define the target and the source file for it
add_executable(main src/main.cpp)

# Set specific directory for the output file
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../")


# Setting C++ version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adding configuration file
configure_file(TutorialConfig.h.in TutorialConfig.h)




# Including directories
# Need to include header (.h) file locations for libraries aswell
# Example here is the Utility library
target_include_directories(main PUBLIC
                             "${PROJECT_BINARY_DIR}"
                             "${PROJECT_SOURCE_DIR}/libraries/Utility"
                             "${PROJECT_SOURCE_DIR}/libraries/stack"
                             )



# Adding libraries

add_subdirectory(libraries/Utility)
add_subdirectory(libraries/stack)
target_link_libraries(main PUBLIC
                    # Libraries
                    Utility
                    stack
                    )