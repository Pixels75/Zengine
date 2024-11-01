#version 410 core

layout(location = 0) out vec4 color;
layout(location = 1) in vec2 v_texCoords;

uniform vec4 u_Color;
uniform sampler2D s_texture;

void main() {
    color = texture(s_texture, v_texCoords);
}