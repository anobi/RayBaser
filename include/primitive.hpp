#pragma once

#include <glm/glm.hpp>

class Primitive {
protected:
public:
    virtual bool Hit(glm::fvec3 ray_position, glm::fvec3 ray_direction) {}
    glm::fvec3 get_position() { return this->position; }
    glm::fvec3 get_color() { return this->color; }

protected:
    glm::fvec3 position = glm::fvec3(0.0f);
    glm::fvec3 color = glm::fvec3(1.0f, 0.0f, 0.5f);
};

class Sphere : public Primitive {
public:
    Sphere() : Primitive() {}
    Sphere(float radius) { this->radius = radius; }
    Sphere(glm::fvec3 position, glm::fvec3 color, float radius) {
        this->position = position;
        this->color = color;
        this->radius = radius;
    }

    bool Hit(glm::fvec3 ray_position, glm::fvec3 ray_direction) {
        glm::fvec3 oc = ray_position - this->position;
        auto a = glm::dot(ray_direction, ray_direction);
        auto b = 2.0f * glm::dot(oc, ray_direction);
        auto c = glm::dot(oc, oc) - this->radius*this->radius;
        auto discriminant = b*b - 4*a*c;
        return discriminant >= 0;
    }

    void set_radius(float radius) { this->radius = radius; }
    float get_radius(float radius) { this->radius = radius; }
    
private:
    float radius = 1.0f;
};