#include "primitive.hpp"

bool Sphere::hit(const Raybaser::Ray *ray, RayHit* hit) const {
        glm::fvec3 oc = ray->position - this->position;
        auto a = glm::length2(ray->direction);
        auto half_b = glm::dot(oc, ray->direction);
        auto c = glm::length2(oc) - this->radius*this->radius;

        auto discriminant = half_b*half_b - a*c;
        if (discriminant < 0.0f ) return false;

        auto sd = sqrt(discriminant);
        auto root = (-half_b - sd) / a;
        if (root <= ray->t_min || ray->t_max <= root) {
            root = (-half_b + sd) / a;
            if (root <= ray->t_min || ray->t_max <= root) {
                return false;
            }
        }

        hit->t = root;
        hit->position = ray->position_at(root);
        // hit->normal = (hit->position - this->position) / this->radius;

        glm::fvec3 outward_normal = (hit->position - this->position) / this->radius;
        auto is_front_face_hit = glm::dot(ray->direction, outward_normal) < 0;
        hit->front_face = is_front_face_hit;
        hit->normal = is_front_face_hit ? outward_normal : -outward_normal;

        return true;
    }
