//
// Created by dacma on 3/14/2024.
//

#ifndef CS455GAME_TESTSHADER_H
#define CS455GAME_TESTSHADER_H


#include "ShaderProgram.h"

class TestShader : public ShaderProgram {
private:
    GLint aVertex;
    GLuint quadVerticesBuffer;
    GLuint quadFacesBuffer;
public:
    TestShader(const std::string& vertexShader, const std::string& fragmentShader);

    GLuint getQuadFacesBuffer() const;

    void link() override;
    void bind() override;
};


#endif //CS455GAME_TESTSHADER_H
