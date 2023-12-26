#pragma once

#include <glm/glm.hpp>
#include "common.hpp"
#include "ray.hpp"

class Hittable {
public:
    virtual bool hit(const Raybaser::Ray *ray, RayHit* hit) const = 0;
    glm::fvec3 get_position() { return this->position; }
    glm::fvec3 get_color() { return this->color; }

protected:
    glm::fvec3 position = glm::fvec3(0.0f);
    glm::fvec3 color = glm::fvec3(1.0f, 0.0f, 0.5f);
};