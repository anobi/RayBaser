#pragma once

#include <glm/glm.hpp>

namespace Raybaser {
    struct Ray {
        float t_min = 0.0f;
        float t_max = 1000.0f;
        glm::fvec3 origin;
        glm::fvec3 direction;
        glm::fvec3 position;
        glm::fvec3 position_at(const float t) const {
            return this->origin + t * this->direction;
        }
    };
}
