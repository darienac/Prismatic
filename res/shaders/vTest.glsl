#version 330

in vec3 aVertex;

out vec3 vVertex;

void main() {
	vVertex = aVertex;
	gl_Position = vec4(aVertex, 1.0);
}