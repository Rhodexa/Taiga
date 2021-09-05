#pragma once
#include <iostream>
#include <string>
#include "glstuff.h"

namespace logpush {
	void quit() {
		system("pause");
		SDL_Quit();
	}

	void fail(std::string err) {
		std::cout << err << std::endl;
		quit();
	}

	void end(std::string err) {
		std::cout << err << ": " << SDL_GetError() << std::endl;
		quit();
	}	
}