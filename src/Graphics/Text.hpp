#pragma once

#include <vector>
#include "GraphicsManager.hpp"

class Text
{
private:
  std::string content;
public:
  Text(std::string content) : content(content) {};

  // Rendering utils
  std::vector<float> generateVertexInfo(float size, float voff, float hoff);
};
