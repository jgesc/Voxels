#pragma once

#include <fstream>

class ResourceManager
{
public:
  static std::ifstream getResourceStream(std::string path);
private:
  ResourceManager() {} // Static class
};
