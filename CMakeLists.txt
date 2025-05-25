cmake_minimum_required(VERSION 3.15)

project(cpp_study LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shift_app shift.cpp)

install(TARGETS shift_app
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

# Optional: set output path
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# optional: add compilation warning
if(MSVC)
    target_compile_options(shift_app PRIVATE /W4 /WX)
else()
    target_compile_options(shift_app PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# Optional: add packages, lib dependencies
# find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
# target_link_libraries(shift_app PRIVATE Qt6::Core Qt6::Widgets)
