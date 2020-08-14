#include "DefaultBlockRender.hpp"

void DefaultBlockRender::render(std::vector<float> * vertices, Chunk *chunk,
  uint_fast8_t lx, uint_fast8_t ly, uint_fast8_t lz, unsigned int id)
{
  if(id == 0) return;

  // Left face
  vertices->insert(vertices->end(), {
    (float)lx, (float)ly, (float)lz,
    (float)lx, (float)ly + 1, (float)lz,
    (float)lx, (float)ly, (float)lz + 1,
    (float)lx, (float)ly + 1, (float)lz,
    (float)lx, (float)ly + 1, (float)lz + 1,
    (float)lx, (float)ly, (float)lz + 1
  } );

  // Right face
  vertices->insert(vertices->end(), {
    (float)lx + 1, (float)ly, (float)lz,
    (float)lx + 1, (float)ly, (float)lz + 1,
    (float)lx + 1, (float)ly + 1, (float)lz,
    (float)lx + 1, (float)ly + 1, (float)lz,
    (float)lx + 1, (float)ly, (float)lz + 1,
    (float)lx + 1, (float)ly + 1, (float)lz + 1
  } );

  // Top face
  vertices->insert(vertices->end(), {
    (float)lx, (float)ly + 1, (float)lz,
    (float)lx + 1, (float)ly + 1, (float)lz,
    (float)lx + 1, (float)ly + 1, (float)lz + 1,
    (float)lx, (float)ly + 1, (float)lz,
    (float)lx + 1, (float)ly + 1, (float)lz + 1,
    (float)lx, (float)ly + 1, (float)lz + 1
  } );

  // Bottom face
  vertices->insert(vertices->end(), {
    (float)lx, (float)ly, (float)lz,
    (float)lx + 1, (float)ly, (float)lz + 1,
    (float)lx + 1, (float)ly, (float)lz,
    (float)lx, (float)ly, (float)lz,
    (float)lx, (float)ly, (float)lz + 1,
    (float)lx + 1, (float)ly, (float)lz + 1
  } );

  // Back face
  vertices->insert(vertices->end(), {
    (float)lx, (float)ly, (float)lz,
    (float)lx + 1, (float)ly, (float)lz,
    (float)lx + 1, (float)ly + 1, (float)lz,
    (float)lx, (float)ly, (float)lz,
    (float)lx + 1, (float)ly + 1, (float)lz,
    (float)lx, (float)ly + 1, (float)lz
  } );

  // Front face
  vertices->insert(vertices->end(), {
    (float)lx, (float)ly, (float)lz + 1,
    (float)lx + 1, (float)ly + 1, (float)lz + 1,
    (float)lx + 1, (float)ly, (float)lz + 1,
    (float)lx, (float)ly, (float)lz + 1,
    (float)lx, (float)ly + 1, (float)lz + 1,
    (float)lx + 1, (float)ly + 1, (float)lz + 1
  } );
}
