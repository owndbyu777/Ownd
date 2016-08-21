#pragma once
#include <stdexcept>
#include <string>
#include <glm/integer.hpp>

namespace OWND {
	class InitError : public std::runtime_error {
	public:
		InitError(const std::string& errorMessage);
		InitError(const std::string& errorMessage, glm::int8 errorNumber);
		
		const glm::int8 getErrorNumber() const { return m_errorNumber; }
	private:
		glm::int8 m_errorNumber;
	};
}
