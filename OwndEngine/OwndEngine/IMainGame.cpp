#include "IMainGame.h"
#include "OwndEngine.h"
#include "OwndErrors.h"

namespace OWND {
	glm::int8 IMainGame::init() {
		OWND::init();

		if (m_window.create("TEST", 600, 400, WF_NONE) != 0) {
			return 1;
		}

		m_currentScreen = std::make_unique<IGameScreen>(IGameScreen());
		m_currentScreen->init();

		return 0;
	}

	void IMainGame::run() {
		if (init() != 0) return;

		m_isRunning = true;
		while (m_isRunning) {
			update();

			if (m_isRunning) {
				m_window.swapBuffer();
			}
		}
	}

	void IMainGame::update() {
		switch (m_currentScreen->getScreenState()) {
			case ScreenState::RUNNING:
				SDL_Event evnt;
				while (SDL_PollEvent(&evnt)) {
					switch (evnt.type) {
						case SDL_QUIT:
							m_currentScreen->setScreenState(ScreenState::EXIT_APPLICATION);
							break;
					}
				}
				break;
			case ScreenState::EXIT_APPLICATION:
				m_isRunning = false;
				SDL_Quit();
				break;
		}
	}

	void IMainGame::onSDLEvent() {

	}
}