#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>

#include "primitive.hpp"
#include "common.hpp"
#include "ray.hpp"


class Scene : public Hittable {
public:
    Scene() : Hittable() {}
    bool hit(const Raybaser::Ray *ray, RayHit* hit) const;

    void add(Hittable* object) {
        this->_objects.push_back(object);
    }
    void clear() {
        this->_objects.clear();
    }
    
private:
    std::vector<> _objects;
};