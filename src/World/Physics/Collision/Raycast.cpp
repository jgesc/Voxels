#include "Raycast.hpp"

float intbound(float s, float ds) {
  // Find the smallest positive t such that s+t*ds is an integer.
  // TODO: may be possible to make it more efficient?
  float r = round(s) - s;
  if(signbit(ds) == signbit(r)) return r / ds; // Does not work when r == 0.0
  else return (r < 0.0 ? r+1 : r-1) / ds;
}

void Raycast::intersectBlock(World * world, glm::vec3 from, glm::vec3 towards,
  float range, BlockCollision * out)
{
  PROFILE_CPU(RaycastIntersect);
  out->reset();

  // Cube containing origin point.
  int64_t x = floor(from.x);
  int64_t y = floor(from.y);
  int64_t z = floor(from.z);
  // Break out direction vector.
  float dx = towards.x;
  float dy = towards.y;
  float dz = towards.z;
  if (dx == 0 && dy == 0 && dz == 0)
    return;
  // Direction to increment x,y,z when stepping.
  int_fast8_t stepX = dx > 0 ? 1 : dx < 0 ? -1 : 0;
  int_fast8_t stepY = dy > 0 ? 1 : dy < 0 ? -1 : 0;
  int_fast8_t stepZ = dz > 0 ? 1 : dz < 0 ? -1 : 0;
  // See description above. The initial values depend on the fractional
  // part of the origin.
  float tMaxX = intbound(from.x, dx);
  float tMaxY = intbound(from.y, dy);
  float tMaxZ = intbound(from.z, dz);
  // The change in t when taking a step (always positive).
  float tDeltaX = dx != 0 ? stepX/dx : 0;
  float tDeltaY = dy != 0 ? stepY/dy : 0;
  float tDeltaZ = dz != 0 ? stepZ/dz : 0;

  while (true) {
    Block * hitBlock = world->getBlock(x, y, z);
    if(hitBlock && hitBlock->getId() != 0)
    {
      out->set(world, hitBlock, x, y, z);
      return;
    }

    // tMaxX stores the t-value at which we cross a cube boundary along the
    // X axis, and similarly for Y and Z. Therefore, choosing the least tMax
    // chooses the closest cube boundary. Only the first case of the four
    // has been commented in detail.
    if (tMaxX < tMaxY) {
      if (tMaxX < tMaxZ) {
        if (tMaxX > range) return;
        // Update which cube we are now in.
        x += stepX;
        // Adjust tMaxX to the next X-oriented boundary crossing.
        tMaxX += tDeltaX;
      } else {
        if (tMaxZ > range) return;
        z += stepZ;
        tMaxZ += tDeltaZ;
      }
    } else {
      if (tMaxY < tMaxZ) {
        if (tMaxY > range) return;
        y += stepY;
        tMaxY += tDeltaY;
      } else {
        // Identical to the second case, repeated for simplicity in
        // the conditionals.
        if (tMaxZ > range) return;
        z += stepZ;
        tMaxZ += tDeltaZ;
      }
    }
  }
}
