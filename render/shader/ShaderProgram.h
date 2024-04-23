//
// Created by dacma on 2/21/2024.
//

#ifndef CS455GAME_SHADERPROGRAM_H
#define CS455GAME_SHADERPROGRAM_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../util/ResourceReader.h"
#include "../model/Texture.h"


class ShaderProgram {
private:
    GLuint programId;
    GLuint vertexShaderId;
    GLuint fragmentShaderId;

    GLuint createShader(const std::string& code, GLenum shaderType) const;
protected:

public:
    ShaderProgram();
    ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);

    void createVertexShader(const std::string& filePath);
    void createFragmentShader(const std::string& filePath);

    virtual void link();

    virtual void bind();
    static void unbind();

    void bindTexture(const Texture& texture);

    GLuint getProgramId() const;

    virtual ~ShaderProgram();
};




#endif //CS455GAME_SHADERPROGRAM_H
