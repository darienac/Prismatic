//
// Created by dacma on 3/18/2024.
//

#ifndef CS455GAME_SHADER3D_H
#define CS455GAME_SHADER3D_H


#include "ShaderProgram.h"
#include "../Camera.h"
#include "../model/Mesh.h"
#include "../model/Model.h"
#include "../Environment.h"

class Shader3D: protected ShaderProgram {
private:
    // attributes
    GLint aVertex;
    GLint aTexCoord;
    GLint aNormal;

    // uniforms
    GLint textureDiffuse;

    GLint uColorChannel;
    GLint uPlayerPos;

    GLint uViewProjectionMatrix;
    GLint uModelMatrix;
    GLint uNormalMatrix;

    GLint uLightPosition;
    GLint uLightColor;
    GLint uAmbientLightColor;
    GLint uViewPosition;

    GLint uAmbientColor;
    GLint uDiffuseColor;
    GLint uSpecularColor;
    GLint uEmissiveColor;

    GLint uOpacity;
public:
    Shader3D(const std::string& vertexShader, const std::string& fragmentShader);

    void loadCamera(Camera* camera, const glm::mat4& cameraDistortMatrix, const glm::mat4& modelMatrix) const;
    void loadMesh(Mesh* mesh);
    void loadMaterial(Material* material);
    void loadEnvironment(Environment* env);
    void setSceneProps(uint8_t colorChannel, const glm::vec3& playerPos);

    void drawModel(Model *model);

    void link() override;
    void bind() override;
};


#endif //CS455GAME_SHADER3D_H
