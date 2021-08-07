#pragma once

// #define ENABLE_PROFILER


#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "Remotery.h"

using namespace std;

#define LOG(msg) cout << msg << endl;

#ifdef ENABLE_PROFILER
  #define PROFILE_CPU(name) rmt_ScopedCPUSample(name, 1)
  #define PROFILE_GPU(name) rmt_ScopedOpenGLSample(name)
#else
  #define PROFILE_CPU(name)
  #define PROFILE_GPU(name)
#endif
