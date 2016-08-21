#include "IMainGame.h"

#include <iostream>

int main(int argc, char** argv) {
	OWND::IMainGame app;
	app.init();

	int a;
	std::cin >> a;
	return 0;
}