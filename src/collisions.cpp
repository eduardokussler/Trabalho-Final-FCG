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
// Fonte: https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection#point_vs._aabb
bool CollisionPlayerDragon(glm::vec4 Playerpos, glm::vec3 player_size, glm::vec4 bbox_min_dragon, glm::vec4 bbox_max_dragon){

    glm::vec3 player_half_size = glm::vec3(player_size.x / 2, player_size.y / 2, player_size.z / 2);

    bool collision_x = (Playerpos.x + player_half_size.x >= bbox_min_dragon.x && bbox_max_dragon.x >= Playerpos.x);
    bool collision_y = (Playerpos.y + player_half_size.y >= bbox_min_dragon.y && bbox_max_dragon.y >= Playerpos.y);
    bool collision_z = (Playerpos.z + player_half_size.z >= bbox_min_dragon.z && bbox_max_dragon.z >= Playerpos.z);

    return collision_x && collision_y && collision_z;

}


// Colisao Projetil-Dragao
// Fonte: https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection#point_vs._aabb
bool collisionProjectileDragon(glm::vec4 bbox_min_dragon, glm::vec4 bbox_max_dragon, glm::vec4 Projectilepos){
    bool collision_x = (Projectilepos.x >= bbox_min_dragon.x && bbox_max_dragon.x >= Projectilepos.x);
    bool collision_y = (Projectilepos.y >= bbox_min_dragon.y && bbox_max_dragon.y >= Projectilepos.y);
    bool collision_z = (Projectilepos.z >= bbox_min_dragon.z && bbox_max_dragon.z >= Projectilepos.z);

    return collision_x && collision_y && collision_z;
}





