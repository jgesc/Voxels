#pragma once

#include "Elements/Crosshair.hpp"

class InterfaceRender
{
private:
  InterfaceRender();
public:
  static Crosshair * crosshair; // TODO: move crosshair to interface manager
  static void renderInterface();
};
