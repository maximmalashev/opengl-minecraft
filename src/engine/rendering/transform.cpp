#include "transform.h"

#include <glm/gtc/matrix_transform.hpp>

namespace engine {

    glm::mat4x4 Transform::CalculateMatrix()
    {
        glm::mat4x4 transform = glm::mat4x4(1.0f);

        transform = glm::translate(transform, position);
        transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        transform = glm::scale(transform, scale);

        return transform;
    }

}
