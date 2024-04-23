//
// Created by dacma on 4/3/2024.
//

#ifndef CS455GAME_SHADER2D_H
#define CS455GAME_SHADER2D_H


#include "ShaderProgram.h"

class Shader2D: public ShaderProgram {
private:
    GLuint verticesBuffer, facesBuffer;

    // attributes
    GLint aVertex;

    // uniforms
    GLint textureR;
    GLint textureG;
    GLint textureB;

    GLuint uColor1;
    GLuint uColor2;
    GLuint uAnimFrames;
public:
    Shader2D(const std::string& vertexShader, const std::string& fragmentShader);

    void loadTextures(Texture* r, Texture* g, Texture* b);
    void setColorTransitionState(bool* colorOld, bool* colorNew, uint8_t animFrames);

    void draw();

    void link() override;
    void bind() override;
};


#endif //CS455GAME_SHADER2D_H
