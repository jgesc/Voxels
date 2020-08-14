#include "DefaultBlockRender.hpp"

void DefaultBlockRender::render(std::vector<float> * vertices, Chunk *chunk,
  uint_fast8_t lx, uint_fast8_t ly, uint_fast8_t lz, unsigned int id)
{
  if(id == 0) return;

  // Left face
  if(chunk->getBlockId(lx - 1, ly, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz,
      tl[0], tl[1],
      (float)lx, (float)ly + 1, (float)lz,
      bl[0], bl[1],
      (float)lx, (float)ly, (float)lz + 1,
      tr[0], tr[1],
      (float)lx, (float)ly + 1, (float)lz,
      bl[0], bl[1],
      (float)lx, (float)ly + 1, (float)lz + 1,
      br[0], br[1],
      (float)lx, (float)ly, (float)lz + 1,
      tr[0], tr[1]
    } );

  // Right face
  if(chunk->getBlockId(lx + 1, ly, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx + 1, (float)ly, (float)lz,
      tr[0], tr[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      tl[0], tl[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      br[0], br[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      br[0], br[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      tl[0], tl[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      bl[0], bl[1]
    } );

  // Top face
  if(chunk->getBlockId(lx, ly + 1, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly + 1, (float)lz,
      bl[0], bl[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      tl[0], tl[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      tr[0], tr[1],
      (float)lx, (float)ly + 1, (float)lz,
      bl[0], bl[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      tr[0], tr[1],
      (float)lx, (float)ly + 1, (float)lz + 1,
      br[0], br[1]
    } );

  // Bottom face
  if(chunk->getBlockId(lx, ly - 1, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz,
      bl[0], bl[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      tr[0], tr[1],
      (float)lx + 1, (float)ly, (float)lz,
      tl[0], tl[1],
      (float)lx, (float)ly, (float)lz,
      bl[0], bl[1],
      (float)lx, (float)ly, (float)lz + 1,
      br[0], br[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      tr[0], tr[1]
    } );

  // Back face
  if(chunk->getBlockId(lx, ly, lz - 1) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz,
      tr[0], tr[1],
      (float)lx + 1, (float)ly, (float)lz,
      tl[0], tl[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      bl[0], bl[1],
      (float)lx, (float)ly, (float)lz,
      tr[0], tr[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      bl[0], bl[1],
      (float)lx, (float)ly + 1, (float)lz,
      br[0], br[1]
    } );

  // Front face
  if(chunk->getBlockId(lx, ly, lz + 1) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz + 1,
      tl[0], tl[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      br[0], br[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      bl[0], bl[1],
      (float)lx, (float)ly, (float)lz + 1,
      tl[0], tl[1],
      (float)lx, (float)ly + 1, (float)lz + 1,
      tr[0], tr[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      br[0], br[1]
    } );
}

DefaultBlockRender::DefaultBlockRender(unsigned int atlasx, unsigned int atlasy)
  : atlasx(atlasx), atlasy(atlasy)
{
  this->tl[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * atlasx;
  this->bl[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * atlasx;
  this->tr[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * (atlasx + 1);
  this->br[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * (atlasx + 1);

  this->tl[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * atlasy;
  this->bl[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * (atlasy + 1);
  this->tr[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * atlasy;
  this->br[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * (atlasy + 1);
}
