#pragma once

#include <glm/glm.hpp>

namespace Raybaser {
    class Ray {
    public:
        Ray() {}
        Ray(const glm::fvec3 origin, const glm::fvec3 direction) {
            this->_direction = direction; 
            this->_origin = origin;
        }

        glm::fvec3 get_origin() const { return this->_origin; }
        glm::fvec3 get_direction() const { return this->_direction; }
        glm::fvec3 get_position_at(float t) const { 
            return this->_origin + t * this->_direction;
        }

    private:
        glm::fvec3 _origin;
        glm::fvec3 _direction;
    };
}