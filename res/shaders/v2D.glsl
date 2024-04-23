#version 330

in vec2 aVertex;

out vec2 vTexCoord;

void main() {
	vTexCoord = aVertex*0.5 + vec2(0.5, 0.5);

	gl_Position = vec4(aVertex, 1.0, 1.0);
}