#include "OwndErrors.h"
#include <iostream>

namespace OWND {
	InitError::InitError(const std::string& errorMessage) : std::runtime_error(errorMessage) {
		std::cout << "An init error occured (no number): " << errorMessage << "\n";
	}

	InitError::InitError(const std::string& errorMessage, glm::int8 errorNumber) : std::runtime_error(errorMessage) {
		std::cout << "An init error occured (" << errorNumber << "): " << errorMessage << "\n";
	}
}