cmake_minimum_required(VERSION 3.12)
project(Master_Clients)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the necessary source and header files
set(SOURCES
    main.cpp
    Source/DataBase.cpp
    Headers/DataBase.hpp
    Source/Tools.cpp
    Headers/Tools.hpp
    Source/Tables.cpp
    Source/Interface.cpp

)

# Add executable target
add_executable(Master_Clients ${SOURCES})

# Include necessary headers
target_include_directories(Master_Clients PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Headers)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Set compiler flags if needed
# target_compile_options(Master_Clients PRIVATE <flags>)
