#version 330

uniform sampler2D textureR;
uniform sampler2D textureG;
uniform sampler2D textureB;

uniform uint uColor1;
uniform uint uColor2;
uniform uint uAnimFrames;

in vec2 vTexCoord;

out vec4 fragColor;

void main() {
    fragColor = vec4(texture(textureR, vTexCoord).r, texture(textureG, vTexCoord).r, texture(textureB, vTexCoord).r, 1.0);
    if ((vTexCoord.x - 0.5)*(vTexCoord.x - 0.5)+(vTexCoord.y - 0.5)*(vTexCoord.y - 0.5) < (float(uAnimFrames) / 80.0)) {
        fragColor.r = ((uColor2 & 1u) > 0u) ? fragColor.r : 0.0;
        fragColor.g = ((uColor2 & 2u) > 0u) ? fragColor.g : 0.0;
        fragColor.b = ((uColor2 & 4u) > 0u) ? fragColor.b : 0.0;
    } else {
        fragColor.r = ((uColor1 & 1u) > 0u) ? fragColor.r : 0.0;
        fragColor.g = ((uColor1 & 2u) > 0u) ? fragColor.g : 0.0;
        fragColor.b = ((uColor1 & 4u) > 0u) ? fragColor.b : 0.0;
    }
    // fragColor = vec4(1.0, 1.0, 0.0, 1.0);
}