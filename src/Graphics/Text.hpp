#pragma once

#include <vector>

class Text
{
private:
  std::string content;
public:
  Text(std::string content) : content(content) {};

  // Rendering utils
  std::vector<float> generateVetexInfo(float size, float voff, float hoff);
};
