//
// Created by dacma on 3/14/2024.
//

#include "TestShader.h"

TestShader::TestShader(const std::string& vertexShader, const std::string& fragmentShader): ShaderProgram(vertexShader, fragmentShader) {}

void TestShader::link() {
    ShaderProgram::link();

    aVertex = glGetAttribLocation(getProgramId(), "aVertex");
    glEnableVertexAttribArray(aVertex);

    const GLfloat quadVertices[] = {
            0.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            1.0f, 1.0f, 0.0f
    };
    const GLint quadFaces[] = {
            0, 1, 2,
            2, 1, 3
    };

    glGenBuffers(1, &quadVerticesBuffer);
    glGenBuffers(1, &quadFacesBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, quadVerticesBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadFacesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadFaces), quadFaces, GL_STATIC_DRAW);
}

GLuint TestShader::getQuadFacesBuffer() const {
    return quadFacesBuffer;
}

void TestShader::bind() {
    ShaderProgram::bind();

    glBindBuffer(GL_ARRAY_BUFFER, quadVerticesBuffer);
    glVertexAttribPointer(aVertex, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
}
