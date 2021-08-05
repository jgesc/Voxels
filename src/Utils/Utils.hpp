#pragma once

#define SIGMOD(a, b) ((b + (a%b)) % b)
#define SIGDIV(a, b) (a / b - (a<0))
