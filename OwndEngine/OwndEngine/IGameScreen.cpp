#include "IGameScreen.h"

namespace OWND {

	IGameScreen::IGameScreen() {
	}


	IGameScreen::~IGameScreen() {
	}

	glm::int8 IGameScreen::init() {
		m_screenState = ScreenState::RUNNING;
		return 0;
	}

}

