#pragma once
#include"basicClasses.h"

class Application;

class MainMenu :public Menu{

private:
	
	Text start;
	Text exit;
	Texture * textureFon;
	Sprite fon;
	Font *myfont;
	

public:
	MainMenu(Texture* texture, Font* font, bool& initFlag);

	void virtual draw( RenderWindow& window) override;
	int virtual logic(Event event, RenderWindow& window) override;

	friend class Application;
};

