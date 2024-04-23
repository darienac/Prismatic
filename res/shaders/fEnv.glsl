#version 330

uniform sampler2D envMap;

uniform uint uColorChannel;
uniform vec3 uLightPosition;
uniform vec3 uLightColor;

in vec2 vTexCoord;
in vec4 vRay;
in vec3 vLightDirection;

out vec4 fragColor;

void main() {
    // fragColor = vec4(vRay.xyz, 1.0);
    // fragColor = vec4(vLightDirection.xyz, 1.0);
    fragColor = texture(envMap, vTexCoord);
    fragColor += vec4(uLightColor, 1.0) * 10.0 * max(0.0, pow(dot(normalize(vRay.xyz), normalize(vLightDirection)), 1000.0));
    if (uColorChannel == 1u) {
        fragColor.r = fragColor.g;
    }
    if (uColorChannel == 2u) {
        fragColor.r = fragColor.b;
    }
}