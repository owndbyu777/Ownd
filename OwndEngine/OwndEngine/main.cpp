#include "IMainGame.h"

#include <iostream>

int main(int argc, char** argv) {
	OWND::IMainGame app;
	app.run();

	int a;
	std::cin >> a;
	return 0;
}