cmake_minimum_required(VERSION 3.20)

project(example-clr-linking-cmake
        VERSION 0.0.1
        DESCRIPTION "Example showing how to link CLR projects"
        HOMEPAGE_URL "https://github.com/PhantomGrazzler/example-clr-linking-cmake"
        LANGUAGES CXX CSharp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_DOTNET_TARGET_FRAMEWORK_VERSION "4.8")

# Enable folders for IDEs.
set_property(GLOBAL PROPERTY USE_FOLDERS YES)

# clr1 - want this to link to clr2
add_library(clr1 SHARED)
target_sources(clr1
    PRIVATE clr1/clr1.hpp
            clr1/clr1.cpp
)
set_target_properties(clr1 PROPERTIES
    COMMON_LANGUAGE_RUNTIME ""
    VS_DOTNET_REFERENCES "System"
    VS_DOTNET_REFERENCE_clr2 "Debug/clr2.dll"
)

# clr2
add_library(clr2 SHARED)
target_sources(clr2
    PRIVATE clr2/clr2.hpp
            clr2/clr2.cpp
)
set_target_properties(clr2 PROPERTIES
    COMMON_LANGUAGE_RUNTIME ""
    VS_DOTNET_REFERENCES "System"
)

# An external C# console application that uses clr1
include_external_msproject(ConsoleApp "${CMAKE_CURRENT_SOURCE_DIR}/ConsoleApp/ConsoleApp.csproj")
