#pragma once

#include "InterfaceRender.hpp"

#define MAX_DEPTH 1000
#define DEPTH_TOP MAX_DEPTH
#define DEPTH_BOTTOM 0

class InterfaceManager
{
private:
  InterfaceManager();
  static uint32_t currentDepth = DEPTH_BOTTOM;
};
