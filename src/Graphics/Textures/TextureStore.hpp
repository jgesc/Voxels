#pragma once

#include "../../World/Block.hpp"
#include "Texture.hpp"

class TextureStore
{
private:
  static bool initialized;
  static TextureStore * I;

  TextureStore();
public:
  static TextureStore * getInstance() {return TextureStore::I;}
  static void initialize();

  // Textures
  const Texture blockAtlas;
};
