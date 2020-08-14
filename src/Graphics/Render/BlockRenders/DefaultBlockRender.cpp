#include "DefaultBlockRender.hpp"

void DefaultBlockRender::render(std::vector<float> * vertices, Chunk *chunk,
  uint_fast8_t lx, uint_fast8_t ly, uint_fast8_t lz, unsigned int id)
{
  if(id == 0) return;

  // Left face
  if(chunk->getBlockId(lx - 1, ly, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz,
      (float)lx, (float)ly + 1, (float)lz,
      (float)lx, (float)ly, (float)lz + 1,
      (float)lx, (float)ly + 1, (float)lz,
      (float)lx, (float)ly + 1, (float)lz + 1,
      (float)lx, (float)ly, (float)lz + 1
    } );

  // Right face
  if(chunk->getBlockId(lx + 1, ly, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx + 1, (float)ly, (float)lz,
      (float)lx + 1, (float)ly, (float)lz + 1,
      (float)lx + 1, (float)ly + 1, (float)lz,
      (float)lx + 1, (float)ly + 1, (float)lz,
      (float)lx + 1, (float)ly, (float)lz + 1,
      (float)lx + 1, (float)ly + 1, (float)lz + 1
    } );

  // Top face
  if(chunk->getBlockId(lx, ly + 1, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly + 1, (float)lz,
      (float)lx + 1, (float)ly + 1, (float)lz,
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      (float)lx, (float)ly + 1, (float)lz,
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      (float)lx, (float)ly + 1, (float)lz + 1
    } );

  // Bottom face
  if(chunk->getBlockId(lx, ly - 1, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz,
      (float)lx + 1, (float)ly, (float)lz + 1,
      (float)lx + 1, (float)ly, (float)lz,
      (float)lx, (float)ly, (float)lz,
      (float)lx, (float)ly, (float)lz + 1,
      (float)lx + 1, (float)ly, (float)lz + 1
    } );

  // Back face
  if(chunk->getBlockId(lx, ly, lz - 1) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz,
      (float)lx + 1, (float)ly, (float)lz,
      (float)lx + 1, (float)ly + 1, (float)lz,
      (float)lx, (float)ly, (float)lz,
      (float)lx + 1, (float)ly + 1, (float)lz,
      (float)lx, (float)ly + 1, (float)lz
    } );

  // Front face
  if(chunk->getBlockId(lx, ly, lz + 1) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz + 1,
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      (float)lx + 1, (float)ly, (float)lz + 1,
      (float)lx, (float)ly, (float)lz + 1,
      (float)lx, (float)ly + 1, (float)lz + 1,
      (float)lx + 1, (float)ly + 1, (float)lz + 1
    } );
}
