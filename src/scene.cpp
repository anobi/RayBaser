#include "scene.hpp"

bool Scene::hit(const Raybaser::Ray *ray, RayHit* hit) const {
    RayHit temp_hit;
    bool hit_anything = false;
    float closest = ray->t_max;

    for (const auto& object : this->_objects) {
        if (object->hit(ray, &temp_hit)) {
            hit_anything = true;
            closest = temp_hit.t;

            hit->front_face = temp_hit.front_face;
            hit->normal = temp_hit.normal;
            hit->position = temp_hit.position;
            hit->t = temp_hit.t;
        }
    }
    return hit_anything;
};