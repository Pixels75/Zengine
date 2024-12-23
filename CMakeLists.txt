cmake_minimum_required(VERSION 3.29)
project(Zengine)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(GLFW_DIR ${PROJECT_SOURCE_DIR}/deps/GLFW)
set(GLEW_DIR ${PROJECT_SOURCE_DIR}/deps/GLEW/2.2.0_1)
set(SOURCE_FILES src/App.cpp
        src/Window.cpp
        src/Window.h
        src/Shader.cpp
        src/Shader.h
        src/Objects/BufferObject.cpp
        src/Objects/BufferObject.h
        src/Objects/VertexArrayObject.cpp
        src/Objects/VertexArrayObject.h
        src/Renderer.cpp
        src/Renderer.h
        src/Objects/VertexBufferLayout.cpp
        src/Objects/VertexBufferLayout.h
        deps/stb_image/stb_image.cpp
        deps/stb_image/stb_image.h
        src/Texture.cpp
        src/Texture.h)

include_directories(${GLFW_DIR}/include ${GLEW_DIR}/include deps/stb_image)

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