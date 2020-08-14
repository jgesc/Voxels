#include "TextureStore.hpp"

bool TextureStore::initialized = false;
TextureStore * TextureStore::I = NULL;

void TextureStore::initialize()
{
  if(TextureStore::initialized) return;

  TextureStore::I = new TextureStore();
  TextureStore::initialized = true;
}

TextureStore::TextureStore() :
  blockAtlas(Texture::fromResource("textures/blocks.png"))
{}
