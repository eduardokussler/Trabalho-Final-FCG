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
bool collisionProjectileFireball(glm::vec4 Projectilepos, glm::vec4 Fireballpos, float raio);
bool CollisionPlayerDragon(glm::vec4 Playerpos, glm::vec3 player_size, glm::vec4 bbox_min_dragon, glm::vec4 bbox_max_dragon);