#pragma once

#include "../BlockRender.hpp"
#include "../../../Debugging/Logger.hpp"

class GrassBlockRender : public BlockRender
{
private:
  unsigned int satlasx, satlasy, tatlasx, tatlasy, batlasx, batlasy;

  float tl[2];
  float tr[2];
  float bl[2];
  float br[2];

  float ttl[2];
  float ttr[2];
  float tbl[2];
  float tbr[2];

  float btl[2];
  float btr[2];
  float bbl[2];
  float bbr[2];
public:
  void render(std::vector<float> * vertices, Chunk *chunk, uint_fast8_t lx,
    uint_fast8_t ly, uint_fast8_t lz, unsigned int id) override;
  GrassBlockRender(unsigned int satlasx, unsigned int satlasy,
    unsigned int tatlasx, unsigned int tatlasy, unsigned int batlasx, unsigned int batlasy);
};
