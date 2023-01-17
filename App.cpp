#include"Application.h"
#define DIAGONALPATH 14

Application::Application() {

	mainmenu = nullptr;
	labirintOption = nullptr;
	labirint = nullptr;
	menu = nullptr;

	if (!fontMain.loadFromFile("Amatic_SC.ttf")) {
		initFlag = false;
		return;
	}
	if (!textureMainFon.loadFromFile("textures\\fon.jpg")) {
		initFlag = false;
		return;
	}
	window.create(VideoMode(Screen_Width, Screen_Height), "Labirint", Style::Titlebar);
	window.setFramerateLimit(30);


	mainmenu = new MainMenu(&textureMainFon, &fontMain, initFlag);
	labirintOption = new LabirintOption(&textureMainFon, &fontMain, initFlag);
	labirint = new Labirint(&fontMain, initFlag);

	menu = mainmenu;



}
Application::~Application() {
	delete mainmenu;
	delete labirintOption;

	if (labirint->myLabirint != nullptr) {

		for (int i = 0; i < labirint->sizeX; i++)
			delete[] labirint->myLabirint[i];

		delete[] labirint->myLabirint;
	}

	delete labirint;

}





void Application::changeMenu() {


	switch (current)
	{
	case 1: {
		menu = mainmenu;
		break;
	}
	case 2: {
		menu = labirintOption;
		break;
	}
	case 3: {

		menu = labirint;
		break;

	}
	}


}
void Application::work() {

	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();


			current = menu->logic(event, window);

			if (current != 0) {
				changeMenu();

				if (current == 3) {
					labirint->setSize(labirintOption->sizeX, labirintOption->sizeY);
					labirint->createLabirint(labirintOption->choice);
				}

			}

		}

		menu->draw(window);

	}

}


void Node::calculateLengthFromStart(const Node* node) {

	if (prev == nullptr) {
		lengthpathFromStart = 0;
		return;
	}

	int costpath = 0;



	if ((node->posInArray.x == this->posInArray.x) || (node->posInArray.y == this->posInArray.y))
		costpath = 10;

	else costpath = DIAGONALPATH;

	if (this->state == BARRIER)
		costpath *= 8;

	lengthpathFromStart = node->lengthpathFromStart + costpath;


}

void Node::calculateHeuristic(const intPoint& point) {

	//if (state == BARRIER)
	heuristicpath = (abs(point.x - posInArray.x) + abs(point.y - posInArray.y)) * 10;
	//heuristicpath = (abs(point.x - posInArray.x) + abs(point.y - posInArray.y)) * 80;
//heuristicpath = std::max(abs(point.x - posInArray.x), abs(point.y - posInArray.y)) * 80;
//else
	//heuristicpath = (abs(point.x - posInArray.x) + abs(point.y - posInArray.y)) * 10;
//heuristicpath = std::max(abs(point.x - posInArray.x), abs(point.y - posInArray.y)) * 10;
}