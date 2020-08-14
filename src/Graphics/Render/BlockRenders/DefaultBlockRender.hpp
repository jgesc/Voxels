#include "../BlockRender.hpp"

class DefaultBlockRender : BlockRender
{
public:
  void render(std::vector<float> * vertices, Chunk *chunk, uint_fast8_t lx,
    uint_fast8_t ly, uint_fast8_t lz, unsigned int id) override;
};
