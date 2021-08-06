#include "Text.hpp"

std::vector<float> Text::generateVertexInfo(float size, float hoff, float voff)
{
  // TODO: do not use screen size or font size constants
  const uint16_t SCR_WIDTH = GraphicsManager::getWindowWidth();
  const uint16_t SCR_HEIGHT = GraphicsManager::getWindowHeight();

  const uint8_t CHAR_PIX_WIDTH = 4;
  const uint8_t CHAR_PIX_HEIGHT = 8;

  const uint8_t FONT_ATLAS_WIDTH = 16;
  const uint8_t FONT_ATLAS_HEIGHT = 8;

  // Character separation
  const float CHAR_SEP_H = 0.25;
  const float CHAR_SEP_V = 0.25;

  // Calculate texture character size
  float ctWidth = 1.0 / FONT_ATLAS_WIDTH;
  float ctHeight = 1.0 / FONT_ATLAS_HEIGHT;

  // Calculate screen character size
  float csWidth = 2.0 / SCR_WIDTH * CHAR_PIX_WIDTH * size;
  float csHeight = 2.0 / SCR_HEIGHT * CHAR_PIX_HEIGHT * size;

  // Calculate screen character separation size
  float hSep = CHAR_SEP_H * csWidth;
  float vSep = CHAR_SEP_V * csHeight;

  std::vector<float> verts;
  // Initialize position variables
  float x = hoff;
  float y = voff;

  // Iterate string
  for (std::string::iterator c = this->content.begin();
    c != this->content.end(); c++)
  {
    if(*c == '\n')
    {
      x = hoff;
      y -= vSep + csHeight;
      continue;
    }
    else
    {
      // Calculate character position in atlas
      uint8_t fRow = *c / FONT_ATLAS_WIDTH;
      uint8_t fCol = *c % FONT_ATLAS_WIDTH;
      // Calculate vertex position in atlas texture
      float u = fCol * ctWidth;
      float v = (fRow+1) * ctHeight;

      verts.insert(verts.end(), {
        /// TOP-LEFT TRIANGLE
        x, y, u, v, // Bot-Left
        x, y+csHeight, u, v-ctHeight, // Top-Left
        x+csWidth, y+csHeight, u+ctWidth, v-ctHeight, // Top-Right
        /// BOT-RIGHT TRIANGLE
        x, y, u, v, // Bot-Left
        x+csWidth, y+csHeight, u+ctWidth, v-ctHeight, // Top-Right
        x+csWidth, y, u+ctWidth, v // Bot-Right
      });
      // Increase position pointer
      x += hSep + csWidth;
    }
  }

  return verts;
}
