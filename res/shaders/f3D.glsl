#version 330

uniform sampler2D textureDiffuse;

uniform uint uColorChannel;
uniform vec3 uPlayerPos;

uniform vec3 uLightPosition;
uniform vec3 uLightColor;
uniform vec3 uAmbientLightColor;
uniform vec3 uViewPosition;

uniform vec3 uAmbientColor;
uniform vec3 uDiffuseColor;
uniform vec3 uSpecularColor;
uniform vec3 uEmissiveColor;

uniform float uOpacity;

in vec3 vVertex;
in vec3 vPosition;
in vec3 vNormal;
in vec2 vTexCoord;

out vec4 fragColor;

const float ambientStrength = 1.0;
const float diffuseStrength = 1.0;
const float specularStrength = 1.0;
const float reflectStrength = 0.0;
const float emissiveStrength = 1.0;
const float shininess = 2.0;

void main() {
    vec4 texColor = vec4(uDiffuseColor, 1.0) * texture(textureDiffuse, vTexCoord);

    vec3 normal = normalize(vNormal);
    vec3 lightDirection = normalize(uLightPosition - vPosition);

    vec3 viewDirection = normalize(uViewPosition - vPosition);
    vec3 reflectLightDirection = reflect(-lightDirection, normal);
    // vec3 reflectViewDirection = reflect(-viewDirection, normal);

    vec3 ambientColor = ambientStrength * texColor.rgb;
    vec3 diffuseColor = diffuseStrength * max(0.0, dot(normal, lightDirection)) * texColor.rgb;
    vec3 specularColor = specularStrength * pow(max(dot(viewDirection, reflectLightDirection), 0.0), shininess) * uSpecularColor;
    vec3 emissiveColor = emissiveStrength * uEmissiveColor * texture(textureDiffuse, vTexCoord).rgb;
    // vec3 reflectColor = reflectStrength * texture(textureReflect, reflectViewDirection.xy).rgb;
    vec3 reflectColor = vec3(0.0, 0.0, 0.0);

    if (vPosition.y < uPlayerPos.y && (vPosition.x - uPlayerPos.x)*(vPosition.x - uPlayerPos.x)+(vPosition.z - uPlayerPos.z)*(vPosition.z - uPlayerPos.z) < 1.0) {
        diffuseColor *= 0.5;
        specularColor = vec3(0.0, 0.0, 0.0);
    }

    fragColor = vec4(ambientColor * uAmbientLightColor + (diffuseColor + specularColor + reflectColor) * uLightColor + emissiveColor, texColor.a * uOpacity);
    if (uColorChannel == 1u) {
        fragColor.r = fragColor.g;
    }
    if (uColorChannel == 2u) {
        fragColor.r = fragColor.b;
    }
    // fragColor = vec4(normal + vec3(0.5, 0.5, 0.5), 1.0);

	// fragColor = vec4((vec2(1.0, 1.0) + vVertex.xy) * 0.5, 1.0, 1.0);
	// fragColor = vec4(vTexCoord, 1.0, 1.0);
	// fragColor = vec4(texture(textureDiffuse, vTexCoord).rgb, 1.0);
}