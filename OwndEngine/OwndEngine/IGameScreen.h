#pragma once

#include <glm/integer.hpp>

namespace OWND {

	enum class ScreenState {
		NONE,
		RUNNING,
		EXIT_APPLICATION
	};

	class IGameScreen {
	public:
		IGameScreen();
		~IGameScreen();

		glm::int8 init();

		ScreenState getScreenState() const { return m_screenState; }
		void setScreenState(ScreenState s) { m_screenState = s; }

	private:
		ScreenState m_screenState;
	};


}

