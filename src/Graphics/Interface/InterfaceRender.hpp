#pragma once

#include "Elements/Crosshair.hpp"
#include "Elements/InterfaceText.hpp"
#include "../../Player/PlayerController.hpp"

class InterfaceRender
{
private:
  InterfaceRender();
public:
  static Crosshair * crosshair; // TODO: move to interface manager
  static InterfaceText * text;
  static void renderInterface();
};
