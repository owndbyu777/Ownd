#include "Window.h"

#include "OwndErrors.h"
#include "OwndConversions.h"

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>

namespace OWND {
	glm::int8 Window::create(std::string windowName, glm::uint16 screenWidth, glm::uint16 screenHeight, glm::uint32 currentWindowFlags) {
		try {
			Uint32 flags = SDL_WINDOW_OPENGL;

			m_screenWidth = screenWidth;
			m_screenHeight = screenHeight;

			if (currentWindowFlags & WF_INVISIBLE) flags |= SDL_WINDOW_HIDDEN;

			if (currentWindowFlags & WF_FULLSCREEN) flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

			if (currentWindowFlags & WF_BORDERLESS) flags |= SDL_WINDOW_BORDERLESS;

			//Create the window
			m_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, static_cast<int>(screenWidth), static_cast<int>(screenHeight), static_cast<Uint32>(flags));
			if (m_sdlWindow == nullptr) {
				throw new InitError("SDL Window could not be created. " + static_cast<std::string>(SDL_GetError()), 0);
			}

			//Set up our OpenGL Context
			SDL_GLContext glContext = SDL_GL_CreateContext(m_sdlWindow);
			if (glContext == nullptr) {
				throw new InitError("SDL GL Context could not be created. " + static_cast<std::string>(SDL_GetError()), 1);
			}

			//Set up glew
			glewExperimental = true;
			GLenum error = glewInit();
			if (error != GLEW_OK) {
				throw new InitError("Could not initialize glew. Error num: " + intToString(static_cast<int>(error)), 2);
			}

			//std::cout << "*** OpenGL Version: " << glGetString(GL_VERSION) << " ***\n" << "To note: This progrm was made for OpenGL version 3.0 and up.\n";


			//Set background color to grey
			glClearColor(0.5f, 0.5f, 0.5f, 1.f);

			//Set VSYNC, up to the user, depends if you're worried about screen tearing
			SDL_GL_SetSwapInterval(0);

			//Enable alpha blend
			//glEnable(m_blendType);
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		} catch (InitError* e) {
			std::cout << "An init error occured while creating a window (" << e->getErrorNumber() << ": " << e->what() << "\n";
			return e->getErrorNumber();
		}
		
		return 0;
	}
	void Window::swapBuffer() {
		//Swap our buffer and draw everything
		SDL_GL_SwapWindow(m_sdlWindow);
	}
}