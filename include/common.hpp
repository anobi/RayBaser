#pragma once

#include <glm/glm.hpp>


// Hit cache object
struct RayHit {
    glm::fvec3 position;
    glm::fvec3 normal;
    float t;
    bool front_face;
};