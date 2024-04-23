//
// Created by dacma on 3/18/2024.
//

#include "Shader3D.h"

Shader3D::Shader3D(const std::string &vertexShader, const std::string &fragmentShader) : ShaderProgram(vertexShader, fragmentShader) {}

void Shader3D::link() {
    ShaderProgram::link();

    aVertex = glGetAttribLocation(getProgramId(), "aVertex");
    glEnableVertexAttribArray(aVertex);
    aTexCoord = glGetAttribLocation(getProgramId(), "aTexCoord");
    glEnableVertexAttribArray(aTexCoord);
    aNormal = glGetAttribLocation(getProgramId(), "aNormal");
    glEnableVertexAttribArray(aNormal);

    textureDiffuse = glGetUniformLocation(getProgramId(), "textureDiffuse");

    uColorChannel = glGetUniformLocation(getProgramId(), "uColorChannel");
    uPlayerPos = glGetUniformLocation(getProgramId(), "uPlayerPos");

    uViewProjectionMatrix = glGetUniformLocation(getProgramId(), "uViewProjectionMatrix");
    uModelMatrix = glGetUniformLocation(getProgramId(), "uModelMatrix");
    uNormalMatrix = glGetUniformLocation(getProgramId(), "uNormalMatrix");

    uLightPosition = glGetUniformLocation(getProgramId(), "uLightPosition");
    uLightColor = glGetUniformLocation(getProgramId(), "uLightColor");
    uAmbientLightColor = glGetUniformLocation(getProgramId(), "uAmbientLightColor");
    uViewPosition = glGetUniformLocation(getProgramId(), "uViewPosition");

    uAmbientColor = glGetUniformLocation(getProgramId(), "uAmbientColor");
    uDiffuseColor = glGetUniformLocation(getProgramId(), "uDiffuseColor");
    uSpecularColor = glGetUniformLocation(getProgramId(), "uSpecularColor");
    uEmissiveColor = glGetUniformLocation(getProgramId(), "uEmissiveColor");

    uOpacity = glGetUniformLocation(getProgramId(), "uOpacity");
}

void Shader3D::bind() {
    ShaderProgram::bind();
}

void Shader3D::loadCamera(Camera* camera, const glm::mat4& cameraDistortMatrix, const glm::mat4& modelMatrix) const {
    glm::mat4 viewProjectionMatrix = cameraDistortMatrix * camera->getViewProjectionMatrix() * modelMatrix;
    glm::mat4 normalMatrix = glm::transpose(glm::inverse(modelMatrix));
    glUniformMatrix4fv(uViewProjectionMatrix, 1, GL_FALSE, &viewProjectionMatrix[0][0]);
    glUniformMatrix4fv(uModelMatrix, 1, GL_FALSE, &modelMatrix[0][0]);
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, &normalMatrix[0][0]);
    glUniform3fv(uViewPosition, 1, &camera->getPos()[0]);
}

void Shader3D::loadMesh(Mesh *mesh) {
    mesh->bind(aVertex, aTexCoord, aNormal);
    if (mesh->getMaterial() != nullptr) {
        loadMaterial(mesh->getMaterial());
    }
}

void Shader3D::loadMaterial(Material *material) {
    if (material->opacity < 1.0f) {
        glDisable(GL_CULL_FACE);
    } else {
        glEnable(GL_CULL_FACE);
    }

    // Setup uniform values
    glUniform3fv(uAmbientColor, 1, &material->ambient[0]);
    glUniform3fv(uDiffuseColor, 1, &material->diffuse[0]);
    glUniform3fv(uDiffuseColor, 1, &material->diffuse[0]);
    glUniform3fv(uSpecularColor, 1, &material->specular[0]);
    glUniform3fv(uEmissiveColor, 1, &material->emissive[0]);

    glUniform1f(uOpacity, material->opacity);

    glUniform1i(textureDiffuse, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, material->texture->getTextureId());
}

void Shader3D::loadEnvironment(Environment *env) {
    glUniform3fv(uLightPosition, 1, &env->lightPos[0]);
    glUniform3fv(uLightColor, 1, &env->lightColor[0]);
    glUniform3fv(uAmbientLightColor, 1, &env->ambientLightColor[0]);
}

void Shader3D::setSceneProps(uint8_t colorChannel, const glm::vec3& playerPos) {
    glUniform1ui(uColorChannel, colorChannel);
    glUniform3fv(uPlayerPos, 1, &playerPos[0]);
}

void Shader3D::drawModel(Model *model) {
    for (Mesh* mesh : model->getMeshes()) {
        loadMesh(mesh);
        mesh->draw();
    }
}
