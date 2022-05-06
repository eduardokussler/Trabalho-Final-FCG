// Headers da biblioteca GLM: cria��o de matrizes e vetores.
#include "collisions.hpp"


// Colisao com as paredes - atras e a esquerda do dragao ta bugado - aparece no outro canto
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

// Colisao Player-Fireball
// Fonte: https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection
bool collisionPlayerFireball(glm::vec4 Playerpos, glm::vec3 player_size, glm::vec4 Fireballpos, float raio){

    glm::vec3 bbox_max_player = glm::vec3 (Playerpos.x + player_size.x, Playerpos.y + player_size.y, Playerpos.z + player_size.z);
    glm::vec3 bbox_min_player = glm::vec3 (Playerpos.x - player_size.x, Playerpos.y - player_size.y, Playerpos.z - player_size.z);

    float x = glm::max(bbox_min_player.x, glm::min(Fireballpos.x, bbox_max_player.x));
    float y = glm::max(bbox_min_player.y, glm::min(Fireballpos.y, bbox_max_player.y));
    float z = glm::max(bbox_min_player.z, glm::min(Fireballpos.z, bbox_max_player.z));

    // this is the same as isPointInsideSphere
    glm::vec4 distance = glm::vec4(x - Fireballpos.x, y - Fireballpos.y, z - Fireballpos.z, 0.0f);
    return false;
    //return norm(distance) <= raio;
/*
    if (Playerpos.x + player_size.x >= Fireballpos.x - raio || Playerpos.x - player_size.x <= Fireballpos.x + raio){
        return true;
    }
    if (Playerpos.y - player_size.y <= Fireballpos.y + raio || Playerpos.y + player_size.y >= Fireballpos.y - raio){
        return true;
    }
    if (Playerpos.z + player_size.z >= Fireballpos.z - raio || Playerpos.z - player_size.z <= Fireballpos.z + raio){
        return true;
    }

    return false;*/

}

// Colisao Projetil-Fireball
bool collisionProjectileFireball(glm::vec4 Projectilepos, glm::vec4 Fireballpos, float raio){
    if (Projectilepos.x >= Fireballpos.x + raio || Projectilepos.x <= Fireballpos.x - raio){
        return true;
    }
    if (Projectilepos.y >= Fireballpos.y + raio || Projectilepos.y <= Fireballpos.y - raio){
        return true;
    }
    if (Projectilepos.z >= Fireballpos.z + raio || Projectilepos.z <= Fireballpos.z - raio){
        return true;
    }

    return false;

}


// Colisao Player-Dragao
bool CollisionPlayerDragon(glm::vec4 Playerpos, glm::vec3 player_size, glm::vec4 bbox_min_dragon, glm::vec4 bbox_max_dragon){

    glm::vec3 player_half_size = glm::vec3(player_size.x / 2, player_size.y / 2, player_size.z / 2);

    bool collision_x = (Playerpos.x + player_half_size.x >= bbox_min_dragon.x && bbox_max_dragon.x >= Playerpos.x);
    bool collision_y = (Playerpos.y + player_half_size.y >= bbox_min_dragon.y && bbox_max_dragon.y >= Playerpos.y);
    bool collision_z = (Playerpos.z + player_half_size.z >= bbox_min_dragon.z && bbox_max_dragon.z >= Playerpos.z);

    return collision_x && collision_y && collision_z;

}

/*
// Colisao Projetil-Dragao
bool collisionProjectileDragon(glm::vec4 bbox_min_dragon, glm::vec4 bbox_max_dragon){

}*/





