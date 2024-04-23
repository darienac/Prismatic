//
// Created by dacma on 2/21/2024.
//

#include "ShaderProgram.h"

GLuint ShaderProgram::createShader(const std::string &code, GLenum shaderType) const {
    GLuint shaderId = glCreateShader(shaderType);
    if (shaderId == 0) {
        std::cerr << "Error creating shader, type: " << shaderType;
    }

    const char* string = code.data();
    GLint stringLength = (GLint) code.length();
    glShaderSource(shaderId, 1, &string, &stringLength);
    glCompileShader(shaderId);

    GLint paramValue;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &paramValue);
    if (paramValue == 0) {
        char log[1024];
        glGetShaderInfoLog(shaderId, 1024, nullptr, log);
        std::cerr << "Error compiling shader code:" << std::endl << log;
    }

    glAttachShader(programId, shaderId);
    return shaderId;
}

ShaderProgram::ShaderProgram() {
    programId = glCreateProgram();
    if (programId == 0) {
        std::cerr << "Could not create shader";
    }
}

ShaderProgram::ShaderProgram(const std::string &vertexShader, const std::string &fragmentShader) {
    programId = glCreateProgram();
    if (programId == 0) {
        std::cerr << "Could not create shader";
    }

    createVertexShader(vertexShader);
    createFragmentShader(fragmentShader);
}

void ShaderProgram::createVertexShader(const std::string &filePath) {
    vertexShaderId = createShader(ResourceReader::readResource(ResourceReader::Shader, filePath), GL_VERTEX_SHADER);
}

void ShaderProgram::createFragmentShader(const std::string &filePath) {
    fragmentShaderId = createShader(ResourceReader::readResource(ResourceReader::Shader, filePath), GL_FRAGMENT_SHADER);
}

void ShaderProgram::link() {
    glLinkProgram(programId);

    GLint paramValue;
    glGetProgramiv(programId, GL_LINK_STATUS, &paramValue);
    if (paramValue == 0) {
        GLsizei length;
        GLchar infoLog[1024];
        glGetProgramInfoLog(programId, 1024, &length, infoLog);
        std::cerr << "Error linking shader code:\n" << std::string(infoLog, length);
    }

    glDetachShader(programId, vertexShaderId);
    glDetachShader(programId, fragmentShaderId);

    glValidateProgram(programId);
    glGetProgramiv(programId, GL_VALIDATE_STATUS, &paramValue);
    if (paramValue == 0) {
        GLsizei length;
        GLchar infoLog[1024];
        glGetProgramInfoLog(programId, 1024, &length, infoLog);
        std::cerr << "Error validating shader code:\n" << std::string(infoLog, length);
    }
}

void ShaderProgram::bind() {
    glUseProgram(programId);
}

void ShaderProgram::unbind() {
    glUseProgram(0);
}

void ShaderProgram::bindTexture(const Texture &texture) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture.getTextureId());
}

GLuint ShaderProgram::getProgramId() const {
    return programId;
}

ShaderProgram::~ShaderProgram() {
    unbind();
    if (getProgramId() != 0) {
        glDeleteProgram(getProgramId());
    }
}
