#include "src/Resources/ResourceManager.hpp"
#include <cstdio>
#include <iostream>

int main(void)
{
	std::ifstream filestream = ResourceManager::getResourceStream(".gietignore");
	std::cout << filestream.rdbuf();
	return 0;
};
