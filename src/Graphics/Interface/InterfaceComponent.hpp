#pragma once

class InterfaceComponent
{
private:
  InterfaceComponent * parent;
  uint32_t depth;
public:
  InterfaceComponent(InterfaceComponent * parent) :
    parent(parent), depth(parent->getDepth()+1) {}
  uint32_t getDepth() {return depth;}
  virtual void render() = 0;
};
