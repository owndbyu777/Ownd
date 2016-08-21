#include "OwndEngine.h"

#include <SDL/SDL.h>
#include <GL/glew.h>

namespace OWND {
	extern bool init() {
		//Init all SDL systems
		SDL_Init(SDL_INIT_EVERYTHING);

		//Tell SDL that we want a double buffered window
		// so we don't get any flickering
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		return true;
	}
}