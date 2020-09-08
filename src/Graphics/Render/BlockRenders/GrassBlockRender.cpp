#include "GrassBlockRender.hpp"

void GrassBlockRender::render(std::vector<float> * vertices, Chunk *chunk,
  uint_fast8_t lx, uint_fast8_t ly, uint_fast8_t lz, unsigned int id)
{
  if(id == 0) return;

  // Left face
  if(chunk->getBlockId(lx - 1, ly, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz,
      bl[0], bl[1],
      (float)lx, (float)ly + 1, (float)lz,
      tl[0], tl[1],
      (float)lx, (float)ly, (float)lz + 1,
      br[0], br[1],
      (float)lx, (float)ly + 1, (float)lz,
      tl[0], tl[1],
      (float)lx, (float)ly + 1, (float)lz + 1,
      tr[0], tr[1],
      (float)lx, (float)ly, (float)lz + 1,
      br[0], br[1]
    } );

  // Right face
  if(chunk->getBlockId(lx + 1, ly, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx + 1, (float)ly, (float)lz,
      bl[0], bl[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      br[0], br[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      tl[0], tl[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      tl[0], tl[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      br[0], br[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      tr[0], tr[1]
    } );

  // Top face
  if(chunk->getBlockId(lx, ly + 1, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly + 1, (float)lz,
      tbl[0], tbl[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      ttl[0], ttl[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      ttr[0], ttr[1],
      (float)lx, (float)ly + 1, (float)lz,
      tbl[0], tbl[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      ttr[0], ttr[1],
      (float)lx, (float)ly + 1, (float)lz + 1,
      tbr[0], tbr[1]
    } );

  // Bottom face
  if(chunk->getBlockId(lx, ly - 1, lz) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz,
      bbl[0], bbl[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      btr[0], btr[1],
      (float)lx + 1, (float)ly, (float)lz,
      btl[0], btl[1],
      (float)lx, (float)ly, (float)lz,
      bbl[0], bbl[1],
      (float)lx, (float)ly, (float)lz + 1,
      bbr[0], bbr[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      btr[0], btr[1]
    } );

  // Back face
  if(chunk->getBlockId(lx, ly, lz - 1) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz,
      bl[0], bl[1],
      (float)lx + 1, (float)ly, (float)lz,
      br[0], br[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      tr[0], tr[1],
      (float)lx, (float)ly, (float)lz,
      bl[0], bl[1],
      (float)lx + 1, (float)ly + 1, (float)lz,
      tr[0], tr[1],
      (float)lx, (float)ly + 1, (float)lz,
      tl[0], tl[1]
    } );

  // Front face
  if(chunk->getBlockId(lx, ly, lz + 1) == 0)
    vertices->insert(vertices->end(), {
      (float)lx, (float)ly, (float)lz + 1,
      bl[0], bl[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      tr[0], tr[1],
      (float)lx + 1, (float)ly, (float)lz + 1,
      br[0], br[1],
      (float)lx, (float)ly, (float)lz + 1,
      bl[0], bl[1],
      (float)lx, (float)ly + 1, (float)lz + 1,
      tl[0], tl[1],
      (float)lx + 1, (float)ly + 1, (float)lz + 1,
      tr[0], tr[1]
    } );
}

GrassBlockRender::GrassBlockRender(unsigned int satlasx, unsigned int satlasy,
  unsigned int tatlasx, unsigned int tatlasy, unsigned int batlasx, unsigned int batlasy)
  : satlasx(satlasx), satlasy(satlasy), tatlasx(tatlasx), tatlasy(tatlasy),
  batlasx(batlasx), batlasy(batlasy)
{
  this->tl[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * satlasx;
  this->bl[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * satlasx;
  this->tr[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * (satlasx + 1);
  this->br[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * (satlasx + 1);

  this->tl[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * satlasy;
  this->bl[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * (satlasy + 1);
  this->tr[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * satlasy;
  this->br[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * (satlasy + 1);


  this->ttl[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * tatlasx;
  this->tbl[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * tatlasx;
  this->ttr[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * (tatlasx + 1);
  this->tbr[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * (tatlasx + 1);

  this->ttl[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * tatlasy;
  this->tbl[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * (tatlasy + 1);
  this->ttr[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * tatlasy;
  this->tbr[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * (tatlasy + 1);


  this->btl[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * batlasx;
  this->bbl[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * batlasx;
  this->btr[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * (batlasx + 1);
  this->bbr[0] = 1 / ((float)BLOCK_ATLAST_SIZE) * (batlasx + 1);

  this->btl[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * batlasy;
  this->bbl[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * (batlasy + 1);
  this->btr[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * batlasy;
  this->bbr[1] = 1 / ((float)BLOCK_ATLAST_SIZE) * (batlasy + 1);
}
