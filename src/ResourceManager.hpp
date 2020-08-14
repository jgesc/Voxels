#pragma once

#include <vector>
#include <fstream>

#include "Debugging/Logger.hpp"
#include "Vendor/stb_image.h"

#define RESOURCE_PATH "./Resources/"

class ResourceManager
{
public:
  static std::ifstream getResourceStream(std::string path);
private:
  ResourceManager() {} // Static class
};
