#include "ResourceManager.hpp"

using namespace std;

ifstream ResourceManager::getResourceStream(string path)
{
  ifstream stream = ifstream("./Resources/" + path);
  if(stream.fail()) {
    // TODO: File does not exist
    throw 0;
  }
  LOG("Loaded resource: " + path);
  return stream;
}
