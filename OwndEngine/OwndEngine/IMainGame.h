#pragma once

#include "Window.h"
#include "IGameScreen.h"

#include <memory>

namespace OWND {
	class IMainGame {
	public:
		glm::int8 init();

		void run();
		void update();
		void onSDLEvent();

	private:
		Window m_window;
		std::unique_ptr<IGameScreen> m_currentScreen = nullptr;

		bool m_isRunning = false;


	};
}

