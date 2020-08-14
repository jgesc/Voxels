#include "ResourceManager.hpp"

using namespace std;

ifstream ResourceManager::getResourceStream(string path)
{
  ifstream stream = ifstream(RESOURCE_PATH + path);
  if(stream.fail()) {
    LOG("Error opening resource: " + path);
    throw 0;
  }
  LOG("Loaded resource: " + path);
  return stream;
}
