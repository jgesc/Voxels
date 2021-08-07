#pragma once

#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "Remotery.h"

using namespace std;

#define LOG(msg) cout << msg << endl;

#define PROFILE_CPU(name) rmt_ScopedCPUSample(name, 1)
#define PROFILE_GPU(name) rmt_ScopedOpenGLSample(name)
