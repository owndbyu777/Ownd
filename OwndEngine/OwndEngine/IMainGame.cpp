#include "IMainGame.h"
#include "OwndEngine.h"

namespace OWND {
	glm::int8 IMainGame::init() {
		OWND::init();

		m_window.create("TEST", 600, 400, WF_NONE);

		return 0;
	}
}