#pragma once

#include <string>
#include <SDL/SDL.h>
#include <glm/integer.hpp>

namespace OWND {

	enum WindowFlags {
		WF_NONE = 0x00,
		WF_INVISIBLE = 0x01,
		WF_FULLSCREEN = 0x02,
		WF_BORDERLESS = 0x04
	};

	class Window {
	public:
		glm::int8 create(std::string windowName, glm::uint16 screenWidth, glm::uint16 screenHeight, glm::uint32 currentWindowFlags);
		void swapBuffer();
	private:
		SDL_Window* m_sdlWindow = nullptr;
		glm::uint16 m_screenWidth = 0, m_screenHeight = 0;

		glm::int32 m_blendType = 0;
	};
}
