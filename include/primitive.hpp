#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>

#include "common.hpp"
#include "ray.hpp"
#include "hittable.hpp"


class Sphere : public Hittable {
public:
    Sphere() : Hittable() {}
    Sphere(float radius) { this->radius = radius; }
    Sphere(glm::fvec3 position, glm::fvec3 color, float radius) {
        this->position = position;
        this->color = color;
        this->radius = radius;
    }

    bool hit(const Raybaser::Ray *ray, RayHit* hit) const;

    void set_radius(float radius) { this->radius = radius; }
    float get_radius(float radius) { return this->radius; }
    
private:
    float radius = 1.0f;
};