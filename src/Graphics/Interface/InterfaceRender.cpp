#include "InterfaceRender.hpp"
Crosshair * InterfaceRender::crosshair = NULL;
InterfaceText * InterfaceRender::text = NULL;

void InterfaceRender::renderInterface()
{
  if(!InterfaceRender::crosshair) InterfaceRender::crosshair = new Crosshair();
  InterfaceRender::crosshair->render();

  if(!InterfaceRender::text)
  {
    InterfaceRender::text = new InterfaceText(Text("This is a test text"));
  }
  InterfaceRender::text->render();
}
