#pragma once

#include"basicClasses.h"
#include"Labirint.h"
#include"LabirintOptions.h"
#include"Main_Menu.h"


class Application {
private:

	bool initFlag = true;
	Menu* menu;
	RenderWindow window;
	int current = 0;

	MainMenu* mainmenu;
	LabirintOption* labirintOption;
	Labirint* labirint;


	Texture textureMainFon;
	Font fontMain;


	void changeMenu();

public:
	Application();
	void work();
	~Application();
};
