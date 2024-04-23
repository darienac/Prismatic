//
// Created by dacma on 4/3/2024.
//

#include "Shader2D.h"

Shader2D::Shader2D(const std::string &vertexShader, const std::string &fragmentShader) : ShaderProgram(vertexShader, fragmentShader) {}

void Shader2D::link() {
    ShaderProgram::link();

    const GLfloat quadVertices[] = {
        -1.0f, -1.0f,
        1.0f, -1.0f,
        -1.0f, 1.0f,
        1.0f, 1.0f
    };
    const GLint quadFaces[] = {
            0, 1, 2,
            2, 1, 3
    };
    glGenBuffers(1, &verticesBuffer);
    glGenBuffers(1, &facesBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, facesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadFaces), quadFaces, GL_STATIC_DRAW);

    aVertex = glGetAttribLocation(getProgramId(), "aVertex");
    glEnableVertexAttribArray(aVertex);

    textureR = glGetUniformLocation(getProgramId(), "textureR");
    textureG = glGetUniformLocation(getProgramId(), "textureG");
    textureB = glGetUniformLocation(getProgramId(), "textureB");

    uColor1 = glGetUniformLocation(getProgramId(), "uColor1");
    uColor2 = glGetUniformLocation(getProgramId(), "uColor2");
    uAnimFrames = glGetUniformLocation(getProgramId(), "uAnimFrames");

    // bind one time stuff
    ShaderProgram::bind();
    glUniform1i(textureR, 0);
    glUniform1i(textureG, 1);
    glUniform1i(textureB, 2);
}

void Shader2D::draw() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, facesBuffer);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr); // 6 for a quad
}

void Shader2D::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
    glVertexAttribPointer(aVertex, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

    ShaderProgram::bind();
}

void Shader2D::loadTextures(Texture *r, Texture *g, Texture *b) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, r->getTextureId());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, g->getTextureId());
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, b->getTextureId());
}

void Shader2D::setColorTransitionState(bool *colorOld, bool *colorNew, uint8_t animFrames) {
    uint8_t color1 = colorOld[0] + (colorOld[1] << 1) + (colorOld[2] << 2);
    uint8_t color2 = colorNew[0] + (colorNew[1] << 1) + (colorNew[2] << 2);
    glUniform1ui(uColor1, color1);
    glUniform1ui(uColor2, color2);
    glUniform1ui(uAnimFrames, animFrames);
}
