// Headers da biblioteca GLM: cria��o de matrizes e vetores.
#include "collisions.hpp"

bool collisionPlane(PlanoEmQualEixo eixo, float planePos, glm::vec4 pos) {
    switch(eixo) {
        case PlanoEmQualEixo::X:
            if(planePos >= 0) {
                return pos.x >= planePos;
            } else {
                return pos.x <= planePos;
            }
            break;
        case PlanoEmQualEixo::Y:
            if(planePos >= 0) {
                return pos.y >= planePos;
            } else {
                return pos.y <= planePos;
            }
            break;
        case PlanoEmQualEixo::Z:
            if(planePos >= 0) {
                return pos.z >= planePos;
            } else {
                return pos.z <= planePos;
            }
            break;
        }

}


