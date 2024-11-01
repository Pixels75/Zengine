#version 410 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoords;

out vec2 v_texCoords;

void main() {
    gl_Position = position;
    v_texCoords = texCoords;
}