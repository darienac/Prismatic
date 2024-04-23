#version 330

uniform mat4 uInverseViewProjectionMatrix;
uniform vec3 uViewPosition;
uniform vec3 uLightPosition;

in vec2 aVertex;

out vec2 vTexCoord;
out vec4 vRay;
out vec3 vLightDirection;

void main() {
	vTexCoord = aVertex*0.5 + vec2(0.5, 0.5);
	vRay = uInverseViewProjectionMatrix * vec4(aVertex, 1.0, 1.0);
	vLightDirection = uLightPosition - uViewPosition;

	gl_Position = vec4(aVertex, 1.0, 1.0);
}