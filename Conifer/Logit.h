#pragma once
#include <iostream>
#include <string>
#include "glstuff.h"

namespace logpush {
	void quit() {
		system("pause");
		//SDL_Quit();
		glfwTerminate();
	}

	void fail(std::string err) {
		std::cout << err << std::endl;
		quit();
	}

	void end(std::string err) {
		std::cout << err << ": " << glfwGetError(NULL) << std::endl;
		quit();
	}	
}