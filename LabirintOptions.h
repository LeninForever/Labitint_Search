#pragma once
#include"basicClasses.h"

class Application;

class LabirintOption :public Menu {
private:

	bool inActiveSize = false;
	bool inActiveCreate = false;
	//bool inputX = true;

	bool startEnterX = false;
	//	bool startEnterY = false;

	int sizeX = 0;
	int sizeY = 0;

	Text textLabirintOptions;
	Text textChooseRandom;
	Text textUserCreate;
	Text textBack;

	Text textSizeX;
	//	Text textSizeY;

	Text textEnterX;
	//Text textEnterY;

	Text textCreate;


	RectangleShape rectFrameX;
	//	RectangleShape rectFrameY;
	RectangleShape cursor;

	RectangleShape rectNode_1;
	//RectangleShape rectNode_2;

	Image imageFrame;
	Image imageActiveFrame;

	Texture* textureFon = nullptr;
	Texture textureFrame;
	Texture textureActiveFrame;

	sf::Clock timer;
	float time = 0;


	short choice = 0;

	Sprite spriteFon;


	Font* myfont = nullptr;




public:
	LabirintOption(Texture* texture, Font* font, bool& initFlag);


	virtual void draw(RenderWindow& window) override;
	virtual int logic(Event event, RenderWindow& window) override;


	
	//void backToMainMenu();

	friend class Application;

};