#pragma once

#include <fstream>

#include "Debugging/Logger.hpp"

class ResourceManager
{
public:
  static std::ifstream getResourceStream(std::string path);
private:
  ResourceManager() {} // Static class
};
