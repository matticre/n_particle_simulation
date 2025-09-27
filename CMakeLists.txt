# The minimum version of CMake required to build this project.
# We recommend using a recent version.
cmake_minimum_required(VERSION 3.10)

# Define the project name. This is used for creating the build files and executable name.
project(ParticleSimulation VERSION 1.0)

# Set the C++ standard to C++17. You can change this to a different version if needed.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the include directories. The 'inc' directory contains the header files.
# CMake will search for headers in this path.
# The 'src' directory is typically where the source files are, so it's good practice
# to include it as well, although for this simple case it's not strictly necessary.
include_directories(
    inc
    src
)

# Define the source files for the executable.
# The 'src' directory contains all the .cpp files.
# The 'main.cpp' file is the entry point for the application.
set(SOURCE_FILES
    src/main.cpp
    src/Particle.cpp
    src/Vector3D.cpp
    src/OdeSolver.cpp
)


# Flags for GCC and Clang compilers
    add_compile_options(
        # Enable all common warnings
        -Wall
        # Enable extra, less-common warnings
        -Wextra
        # Treat all warnings as errors, forcing clean builds
        -Werror
        # Enforce strict adherence to the C++ standard
        -Wpedantic
        
        # Enable additional warnings for specific issues
        -Wshadow            # Warn if a local variable shadows another variable
        -Wunused            # Warn about unused variables/functions
        -Wcast-align        # Warn when a pointer is cast to a type with a stricter alignment
        -Wnull-dereference  # Warn when a null pointer is dereferenced
        -Wconversion        # Warn about implicit type conversions that might lose data
        -Wsign-conversion   # Warn about conversions that change signedness
        -Wold-style-cast    # Warn about C-style casts
        -Woverloaded-virtual # Warn when 'virtual' functions are hidden
        -Wredundant-decls   # Warn if declarations are repeated
        -Wformat=2          # Enforce type checking for format strings
        -Wimplicit-fallthrough # Warn about switch cases that fall through
        -Wzero-as-null-pointer-constant # Warn about `0` used as `nullptr`
    )

# Adding external libraries to link
find_package(SFML COMPONENTS graphics window system REQUIRED)


# Add the executable. The first argument is the name of the executable to be created.
# The following arguments are the source files that will be compiled and linked.
add_executable(ParticleSimulation ${SOURCE_FILES})


target_link_libraries(ParticleSimulation sfml-graphics)

# Optionally, you can set the output directory for the executable.
# This places the executable inside the 'bin' directory.
set_target_properties(ParticleSimulation PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
