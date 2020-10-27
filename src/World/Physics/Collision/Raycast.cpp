#include "Raycast.hpp"
#include "../../../Debugging/Logger.hpp"

#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a) (((a)<0) ? -(a) : (a))
#define ZSGN(a) (((a)<0) ? -1 : (a)>0 ? 1 : 0)


void Raycast::intersectBlock(World * world, glm::vec3 from, glm::vec3 towards,
  float range, BlockCollision * out)
{
    // 3D Bresenham implementation
    // TODO: replace World::getBlock() call with something more efficient

    int x1 = from.x;
    int y1 = from.y;
    int z1 = from.z;

    glm::vec3 dest = from + towards * range;
    int x2 = dest.x;
    int y2 = dest.y;
    int z2 = dest.z;

    int xd, yd, zd;
    int x, y, z;
    int ax, ay, az;
    int sx, sy, sz;
    int dx, dy, dz;

    dx = x2 - x1;
    dy = y2 - y1;
    dz = z2 - z1;

    ax = ABS(dx) << 1;
    ay = ABS(dy) << 1;
    az = ABS(dz) << 1;

    sx = ZSGN(dx);
    sy = ZSGN(dy);
    sz = ZSGN(dz);

    x = x1;
    y = y1;
    z = z1;

    if (ax >= MAX(ay, az))            /* x dominant */
    {
      yd = ay - (ax >> 1);
      zd = az - (ax >> 1);
      for (;;)
      {
        Block * hitBlock = world->getBlock(x, y, z);
        if(hitBlock)
          LOG("HIT");
        if (x == x2)
        {
          return;
        }

        if (yd >= 0)
        {
          y += sy;
          yd -= ax;
        }

        if (zd >= 0)
        {
          z += sz;
          zd -= ax;
        }

        x += sx;
        yd += ay;
        zd += az;
      }
    }
    else if (ay >= MAX(ax, az))            /* y dominant */
    {
      xd = ax - (ay >> 1);
      zd = az - (ay >> 1);
      for (;;)
      {
        Block * hitBlock = world->getBlock(x, y, z);
        if(hitBlock)
          LOG("HIT");
        if (y == y2)
        {
          return;
        }

        if (xd >= 0)
        {
          x += sx;
          xd -= ay;
        }

        if (zd >= 0)
        {
          z += sz;
          zd -= ay;
        }

        y += sy;
        xd += ax;
        zd += az;
      }
    }
    else if (az >= MAX(ax, ay))            /* z dominant */
    {
      xd = ax - (az >> 1);
      yd = ay - (az >> 1);
      for (;;)
      {
        Block * hitBlock = world->getBlock(x, y, z);
        if(hitBlock)
          LOG("HIT");
        if (z == z2)
        {
          return;
        }

        if (xd >= 0)
        {
          x += sx;
          xd -= az;
        }

        if (yd >= 0)
        {
          y += sy;
          yd -= az;
        }

        z += sz;
        xd += ax;
        yd += ay;
      }
    }
}
