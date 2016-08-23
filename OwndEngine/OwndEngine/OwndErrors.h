#pragma once
#include <stdexcept>
#include <string>
#include <glm/integer.hpp>

namespace OWND {
	class GeneralError : public std::runtime_error {
	public:
		GeneralError(const std::string& errorMessage);
	};

	class InitError : public GeneralError {
	public:
		InitError(const std::string& errorMessage);
		InitError(const std::string& errorMessage, glm::int8 errorNumber);
		
		const glm::int8 getErrorNumber() const { return m_errorNumber; }
	private:
		glm::int8 m_errorNumber = -1;
	};
}
