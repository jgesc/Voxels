#pragma once

#include <bitset>
#include <cstdint>

#define MAX_BLOCK_ID 255
#define WORLD_COORD int64_t

class Block
{
private:
  uint32_t id;
  uint32_t metadata;
  void * entblock;
public:
  // Constructor
  Block() : id(0), metadata(0), entblock(NULL) {};

  // Setters
  void setId(uint32_t id) {this->id = id;}
  void setMetadata(uint32_t metadata) {this->metadata = metadata;}
  void setEntblock(void * entblock) {this->entblock = entblock;}

  // Getters
  inline uint32_t getId() {return this->id;}
  inline uint32_t getMetadata() {return this->metadata;}
  inline void * getEntblock() {return this->entblock;}

  // Utils
  inline void clear() {this->id = 0; this->metadata = 0; this->entblock = NULL;}
};
