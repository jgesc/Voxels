#pragma once

#include <glm/glm.hpp>

#include "../../Block.hpp"
#include "../../Chunk.hpp"
#include "../../Region.hpp"
#include "../../World.hpp"
#include "BlockCollision.hpp"

class Raycast
{
public:
  void intersectBlock(World * world, glm::vec3 from, glm::vec3 towards,
    float range, BlockCollision * out);
private:
  Raycast() {}
};
