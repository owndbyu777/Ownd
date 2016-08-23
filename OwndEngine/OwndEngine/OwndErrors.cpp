#include "OwndErrors.h"
#include <iostream>

namespace OWND {
	GeneralError::GeneralError(const std::string& errorMessage) : std::runtime_error(errorMessage) {
	}

	InitError::InitError(const std::string& errorMessage) : GeneralError(errorMessage) {
	}

	InitError::InitError(const std::string& errorMessage, glm::int8 errorNumber) : GeneralError(errorMessage) {
	}
}