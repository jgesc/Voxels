#pragma once

#define SIGMOD(a, b) ((b + (a%b)) % b)
#define SIGDIV(a, b) (((a<0)+a) / b - (a<0))
