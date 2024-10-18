cmake_minimum_required(VERSION 3.29)
project(Zengine)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(GLFW_DIR ${PROJECT_SOURCE_DIR}/deps/GLFW)
set(GLEW_DIR ${PROJECT_SOURCE_DIR}/deps/GLEW/2.2.0_1)
set(SOURCE_FILES src/main.cpp
        src/window.cpp
        src/window.h
        src/shader.cpp
        src/shader.h
        src/buffer_object.cpp
        src/buffer_object.h)

include_directories(${GLFW_DIR}/include ${GLEW_DIR}/include)

add_compile_definitions(GLEW_STATIC)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        "-framework CoreFoundation"
        "-framework CoreGraphics"
        "-framework IOKit"
        "-framework AppKit"
        "-framework OpenGL"
        ${GLFW_DIR}/lib/libglfw3.a
        ${GLEW_DIR}/lib/libGLEW.a)