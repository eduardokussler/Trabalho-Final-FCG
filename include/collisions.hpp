#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>
#pragma once
enum PlanoEmQualEixo {
    X = 1,
    Y = 2,
    Z = 3,
};

bool collisionPlane(PlanoEmQualEixo eixo, float planePos, glm::vec4 pos);