#include "ResourceManager.hpp"

using namespace std;

ifstream ResourceManager::getResourceStream(string path)
{
  ifstream stream = ifstream(path);
  if(stream.fail()) {
    // TODO: File does not exist code here
    throw 0;
  }
  return stream;
}
