#pragma once
#include <string>

namespace logpush {
	extern void quit();
	extern void fail(std::string err);
	extern void end(std::string err);
}