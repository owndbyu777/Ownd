#pragma once

#include "Window.h"

namespace OWND {
	class IMainGame {
	public:
		glm::int8 init();

	private:
		Window m_window;
	};
}

