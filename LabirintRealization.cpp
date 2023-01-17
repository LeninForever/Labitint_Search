#include"Labirint.h"
#include<unordered_set>
Labirint::Labirint(Font* font, bool& initFlag) {

	this->font = font;;



	if (!textureOrdinaryNode.loadFromFile("textures\\freeNode.jpg"))
		initFlag = false;

	if (!textureBarrier.loadFromFile("textures\\water.jpg"))
		initFlag = false;

	if (!textureWall.loadFromFile("textures\\wall.jpg"))
		initFlag = false;

	if (!textureStart.loadFromFile("textures\\start_1.png"))
		initFlag = false;

	if (!textureFinish.loadFromFile("textures\\finish.jpg"))
		initFlag = false;

	if (!textureFon.loadFromFile("textures\\fonForLabirint.png"))
		initFlag = false;




	rectFon.setPosition(Screen_Height, 0);
	rectFon.setSize(Vector2f(Screen_Width - Screen_Height, Screen_Height));
	rectFon.setTexture(&textureFon);

	sizeX = 0;
	sizeY = 0;
	prevPoint.x = -1;



	rectStart.setTexture(&textureStart);
	rectStart.setPosition(Screen_Height + Screen_Width * 0.18f, Screen_Height * 0.25f);
	rectStart.setSize(Vector2f(Screen_Width * 0.07f, Screen_Width * 0.07f));


	rectFinish.setTexture(&textureFinish);
	rectFinish.setPosition(Screen_Height + Screen_Width * 0.18f, Screen_Height * 0.37f);
	rectFinish.setSize(Vector2f(Screen_Width * 0.07f, Screen_Width * 0.07f));


	rectFreeNode.setTexture(&textureOrdinaryNode);
	rectFreeNode.setPosition(Screen_Width * 0.86f, Screen_Height * 0.20f);
	rectFreeNode.setSize(Vector2f(Screen_Width * 0.07f, Screen_Width * 0.07f));


	rectWall.setTexture(&textureWall);
	rectWall.setPosition(Screen_Width * 0.86f, Screen_Height * 0.35f);
	rectWall.setSize(Vector2f(Screen_Width * 0.07f, Screen_Width * 0.07f));


	rectBarrier.setTexture(&textureBarrier);
	rectBarrier.setPosition(Screen_Width * 0.86f, Screen_Height * 0.49f);
	rectBarrier.setSize(Vector2f(Screen_Width * 0.07f, Screen_Width * 0.07f));



	textChoosePosition.setString(sf::String("Choose positions:"));
	textChoosePosition.setCharacterSize(Size_Font);
	textChoosePosition.setPosition(Screen_Height + Screen_Width * 0.012f, Screen_Height * 0.1f);
	textChoosePosition.setFillColor(Color(0, 0, 0));
	textChoosePosition.setFont(*font);


	textStart.setString(sf::String("Start"));
	textStart.setCharacterSize(Size_Font);
	textStart.setPosition(Screen_Height + Screen_Width * 0.055f, Screen_Height * 0.25f);
	textStart.setFillColor(Color(0, 0, 0));
	textStart.setFont(*font);


	textFinish.setString(sf::String("Finish"));
	textFinish.setCharacterSize(Size_Font);
	textFinish.setPosition(Screen_Height + Screen_Width * 0.055f, Screen_Height * 0.37f);
	textFinish.setFillColor(Color(10, 246, 242));
	textFinish.setFont(*font);


	textFindThepath.setString(sf::String("Find the path!"));
	textFindThepath.setCharacterSize(Size_Font);
	textFindThepath.setPosition(Screen_Height + Screen_Width * 0.055f, Screen_Height * 0.5f);
	textFindThepath.setFillColor(Color(10, 246, 242));
	textFindThepath.setFont(*font);


	textChooseNew.setString(sf::String("Choose new"));
	textChooseNew.setCharacterSize(Size_Font);
	textChooseNew.setPosition(Screen_Height + Screen_Width * 0.055f, Screen_Height * 0.68f);
	textChooseNew.setFillColor(Color(10, 246, 242));
	textChooseNew.setFont(*font);


	textBackToMenu.setString(sf::String("Back to Menu"));
	textBackToMenu.setCharacterSize(Size_Font);
	textBackToMenu.setPosition(Screen_Height + Screen_Width * 0.055f, Screen_Height * 0.89f);
	textBackToMenu.setFillColor(Color(10, 246, 242));
	textBackToMenu.setFont(*font);


	textOrdinary.setString(sf::String("Free node:"));
	textOrdinary.setCharacterSize(Size_Font);
	textOrdinary.setPosition(Screen_Width * 0.7f, Screen_Height * 0.20f); //0/27
	textOrdinary.setFillColor(Color(10, 246, 242));
	textOrdinary.setFont(*font);


	textWall.setString(sf::String("Wall:"));
	textWall.setCharacterSize(Size_Font);
	textWall.setPosition(Screen_Width * 0.7f, Screen_Height * 0.35f);
	textWall.setFillColor(Color(10, 246, 242));
	textWall.setFont(*font);


	textBarrier.setString(sf::String("Barrier:"));
	textBarrier.setCharacterSize(Size_Font);
	textBarrier.setPosition(Screen_Width * 0.7f, Screen_Height * 0.49f);
	textBarrier.setFillColor(Color(10, 246, 242));
	textBarrier.setFont(*font);


	textSave.setString(sf::String("Save"));
	textSave.setCharacterSize(Size_Font);
	textSave.setPosition(Screen_Width * 0.7f, Screen_Height * 0.7f);
	textSave.setFillColor(Color(255, 210, 58));
	textSave.setFont(*font);
}



void Labirint::createLabirint(short choice) {

	if (choice == 1) {

		randCreation();
	}

	if (choice == 2) {

		userCreation();
	}

}

void Labirint::draw(RenderWindow& window) {


	window.clear();
	window.draw(rectFon);

	for (int i = 0; i < sizeX; i++)
		for (int j = 0; j < sizeY; j++)
			window.draw(myLabirint[i][j].rect);


	if (prevPoint.x != -1)
		window.draw(myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect);



	switch (labirintState)
	{

	case INCREATION: {

		window.draw(textWall);
		window.draw(textBarrier);
		window.draw(textOrdinary);
		window.draw(textSave);

		window.draw(rectFreeNode);
		window.draw(rectBarrier);
		window.draw(rectWall);

		break;
	}

	case READYTOFIND: {

		window.draw(textChoosePosition);

		window.draw(textStart);
		window.draw(rectStart);


		if (wasChoosenStart) {

			window.draw(textFinish);
			window.draw(rectFinish);


			if (wasChoosenFinish)
				window.draw(textFindThepath);


			if (wasFoundThepath)
				window.draw(textChooseNew);

		}
		break;
	}

	}
	window.draw(textBackToMenu);
	window.display();

}


int Labirint::logic(Event event, RenderWindow& window) {


	Vector2f mousePos = Vector2f(sf::Mouse::getPosition(window));
	bool inLab = false;

	sf::FloatRect backToMenuRect = textBackToMenu.getGlobalBounds();

	if (backToMenuRect.contains(mousePos)) {

		textBackToMenu.setStyle(Text::Underlined);


		if (event.type == Event::MouseButtonPressed) {

			for (int i = 0; i < sizeY; i++)
				delete[] myLabirint[i];

			delete[] myLabirint;

			textBackToMenu.setStyle(Text::Regular);

			this->cursorState = NOTHING;
			this->finishPoint.x = finishPoint.y = 0;
			this->inCreation = wasChoosenFinish = wasChoosenStart = wasFoundThepath = false;
			this->labirintState = WASNTCREATE;
			path.clear();

			this->startPoint.x = startPoint.y = 0;
			this->prevPoint.x = prevPoint.y = 0;
			myLabirint = nullptr;

			return 1;

		}


	}
	else textBackToMenu.setStyle(Text::Regular);


	switch (labirintState) {


	case INCREATION: {

		FloatRect freerect = rectFreeNode.getGlobalBounds();
		FloatRect wallrect = rectWall.getGlobalBounds();
		FloatRect barrierrect = rectBarrier.getGlobalBounds();
		FloatRect saverect = textSave.getGlobalBounds();
		FloatRect backrect = textBackToMenu.getGlobalBounds();

		for (int i = 0; i < sizeX; i++)
			for (int j = 0; j < sizeY; j++) {


				sf::FloatRect rect = myLabirint[i][j].rect.getGlobalBounds();


				if (rect.contains(mousePos)) {


					if (prevPoint.x != -1) {

						myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineThickness(0);



					}
					prevPoint.x = myLabirint[i][j].posInArray.x;
					prevPoint.y = myLabirint[i][j].posInArray.y;

					myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineThickness(3);
					myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineColor(Color::Red);

					inLab = true;

					if (event.type == Event::MouseButtonPressed) {


						switch (cursorState)
						{

						case DRAWFREE: {

							myLabirint[i][j].rect.setTexture(&textureOrdinaryNode);
							myLabirint[i][j].state = FREENODE;
							break;
						}
						case DRAWBARRIER: {

							myLabirint[i][j].rect.setTexture(&textureBarrier);
							myLabirint[i][j].state = BARRIER;
							break;

						}
						case DRAWWALL: {

							myLabirint[i][j].rect.setTexture(&textureWall);
							myLabirint[i][j].state = WALL;

							break;

						}

						}

					}

					break;
				}
			}


		if ((!inLab) && (prevPoint.x != -1))
			myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineThickness(0);



		if (freerect.contains(mousePos)) {

			rectFreeNode.setOutlineThickness(2);
			rectFreeNode.setOutlineColor(Color::Cyan);
			if (event.type == Event::MouseButtonPressed) {

				cursorState = DRAWFREE;

			}

		}
		else
			rectFreeNode.setOutlineThickness(0);


		if (barrierrect.contains(mousePos)) {

			rectBarrier.setOutlineColor(Color::Cyan);
			rectBarrier.setOutlineThickness(2);

			if (event.type == Event::MouseButtonPressed) {

				cursorState = DRAWBARRIER;

			}

		}
		else
			rectBarrier.setOutlineThickness(0);


		if (wallrect.contains(mousePos)) {

			rectWall.setOutlineThickness(2);
			rectWall.setOutlineColor(Color::Cyan);

			if (event.type == Event::MouseButtonPressed) {

				cursorState = DRAWWALL;

			}

		}

		else
			rectWall.setOutlineThickness(0);


		if (saverect.contains(mousePos)) {

			textSave.setStyle(Text::Underlined);

			if (event.type == Event::MouseButtonPressed)
				labirintState = READYTOFIND;

		}
		else
			textSave.setStyle(Text::Regular);

		break;
	}


	case READYTOFIND: {

		sf::FloatRect startrect = rectStart.getGlobalBounds();
		sf::FloatRect finishrect = rectFinish.getGlobalBounds();
		sf::FloatRect findthepathrect = textFindThepath.getGlobalBounds();
		sf::FloatRect chooseNewRect = textChooseNew.getGlobalBounds();



		for (int i = 0; i < sizeX; i++)
			for (int j = 0; j < sizeY; j++) {

				sf::FloatRect rect = myLabirint[i][j].rect.getGlobalBounds();

				if (rect.contains(mousePos)) {


					if (prevPoint.x != -1) {


						myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineThickness(0);


						//myLabirint[int(prevPoint.x)][int(prevPoint.x)].rect.setOutlineThickness(0);


					}


					prevPoint.x = myLabirint[i][j].posInArray.x;
					prevPoint.y = myLabirint[i][j].posInArray.y;

					myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineThickness(3); {

						if (cursorState == NOTHING)
							myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineColor(Color::Red);

						else if (cursorState == DRAWSTART)
							myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineColor(Color::Green);
						else if (cursorState == DRAWFINISH)
							myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineColor(Color::White);
					}

					inLab = true;

					if ((event.type == Event::MouseButtonPressed) && (myLabirint[i][j].state == FREENODE)) {


						switch (cursorState)
						{

						case DRAWSTART: {

							if ((wasChoosenFinish) && (i == finishPoint.x) && (j == finishPoint.y))
								return 0;

							if (wasChoosenStart)
								myLabirint[int(startPoint.x)][int(startPoint.y)].rect.setTexture(&textureOrdinaryNode);

							myLabirint[i][j].rect.setTexture(&textureStart);

							wasChoosenStart = true;
							startPoint.x = myLabirint[i][j].posInArray.x;
							startPoint.y = myLabirint[i][j].posInArray.y;

							cursorState = NOTHING;

							break;
						}


						case DRAWFINISH: {

							if ((myLabirint[i][j].posInArray.x == startPoint.x) && (myLabirint[i][j].posInArray.y == startPoint.y))
								return 0;

							if (wasChoosenFinish)
								myLabirint[finishPoint.x][finishPoint.y].rect.setTexture(&textureOrdinaryNode);


							wasChoosenFinish = true;
							myLabirint[i][j].rect.setTexture(&textureFinish);


							finishPoint.x = myLabirint[i][j].posInArray.x;
							finishPoint.y = myLabirint[i][j].posInArray.y;
							cursorState = NOTHING;
							break;

						}

						}

					}

				}
			}


		if ((!inLab) && (prevPoint.x != -1))
			myLabirint[int(prevPoint.x)][int(prevPoint.y)].rect.setOutlineThickness(0);


		if ((startrect.contains(mousePos)) && (!wasFoundThepath)) {

			rectStart.setOutlineThickness(3);
			rectStart.setOutlineColor(Color::Cyan);

			if (event.type == Event::MouseButtonPressed) {
				cursorState = DRAWSTART;

			}
		}
		else
			rectStart.setOutlineThickness(0);


		if ((finishrect.contains(mousePos)) && (wasChoosenStart) && (!wasFoundThepath)) {

			rectFinish.setOutlineThickness(3);
			rectFinish.setOutlineColor(Color::Cyan);

			if (event.type == Event::MouseButtonPressed)
				cursorState = DRAWFINISH;
		}
		else
			rectFinish.setOutlineThickness(0);


		if ((findthepathrect.contains(mousePos)) && (wasChoosenFinish) && (!wasFoundThepath)) {

			textFindThepath.setStyle(Text::Underlined);

			if (event.type == Event::MouseButtonPressed) {
				findpath();

				if (!wasFoundThepath) {

					textFindThepath.setString("No path");
					wasFoundThepath = true;

				}
				cursorState = NOTHING;
			}
		}
		else
			textFindThepath.setStyle(Text::Regular);

		if ((chooseNewRect.contains(mousePos)) && (wasFoundThepath)) {

			textChooseNew.setStyle(Text::Underlined);

			if (event.type == Event::MouseButtonPressed)
			{

				for (int i = 0; i < sizeX; i++)
					for (int j = 0; j < sizeY; j++) {

						myLabirint[i][j].closet = 0;
						myLabirint[i][j].heuristicpath = 0;
						myLabirint[i][j].lengthpathFromStart = 0;
						myLabirint[i][j].prev = nullptr;
						myLabirint[i][j].weightNode = 0;

						if ((i == startPoint.x) && (j == startPoint.y)) {

							myLabirint[i][j].rect.setTexture(&textureOrdinaryNode);

							startPoint.x = 1;
							startPoint.y = 0;


						}
						else if ((i == finishPoint.x) && (j == finishPoint.y)) {

							myLabirint[i][j].rect.setTexture(&textureOrdinaryNode);

							finishPoint.x = 0;
							finishPoint.y = 0;

						}
						myLabirint[i][j].rect.setFillColor(Color::White);

					}
				wasChoosenStart = false;
				wasChoosenFinish = false;
				wasFoundThepath = false;
				textFindThepath.setString("Find the path!");
				path.clear();
			}

		}
		else textChooseNew.setStyle(Text::Regular);
		break;
	}
	}



	return 0;

}

void Labirint::randCreation() {

	sizeX = sizeY = rand() % 31 + 20;


	myLabirint = new Node * [sizeX];

	for (int i = 0; i < sizeX; i++) {
		myLabirint[i] = new Node[sizeX];
	}

	sizeOfEveryNode = float(Labirint_Width) / float(sizeX);

	for (int i = 0; i < sizeX; i++)
		for (int j = 0; j < sizeY; j++) {

			myLabirint[i][j].posInArray.x = i;
			myLabirint[i][j].posInArray.y = j;


			myLabirint[i][j].pos.y = i * sizeOfEveryNode;
			myLabirint[i][j].pos.x = j * sizeOfEveryNode;




			int randFactor = rand() % 100;


			if (randFactor < 50) {

				myLabirint[i][j].state = FREENODE;
				myLabirint[i][j].rect.setTexture(&textureOrdinaryNode);
				myLabirint[i][j].rect.setPosition(Vector2f(myLabirint[i][j].pos.x, myLabirint[i][j].pos.y));
				myLabirint[i][j].rect.setSize(Vector2f(sizeOfEveryNode, sizeOfEveryNode));
			}

			else if ((randFactor > 50) && (randFactor < 60)) {

				myLabirint[i][j].state = BARRIER;
				myLabirint[i][j].rect.setTexture(&textureBarrier);
				myLabirint[i][j].rect.setPosition(Vector2f(myLabirint[i][j].pos.x, myLabirint[i][j].pos.y));
				myLabirint[i][j].rect.setSize(Vector2f(sizeOfEveryNode, sizeOfEveryNode));

			}
			else {
				myLabirint[i][j].rect.setTexture(&textureWall);
				myLabirint[i][j].rect.setPosition(Vector2f(myLabirint[i][j].pos.x, myLabirint[i][j].pos.y));
				myLabirint[i][j].rect.setSize(Vector2f(sizeOfEveryNode, sizeOfEveryNode));
				myLabirint[i][j].state = WALL;
			}
		}



	labirintState = READYTOFIND;

}
void Labirint::userCreation() {

	sizeY = sizeX;

	myLabirint = new Node * [sizeX];

	for (int i = 0; i < sizeX; i++) {
		myLabirint[i] = new Node[sizeX];
	}

	sizeOfEveryNode = float(Labirint_Width) / float(sizeX);


	for (int i = 0; i < sizeX; i++)
		for (int j = 0; j < sizeY; j++) {

			myLabirint[i][j].posInArray.x = i;
			myLabirint[i][j].posInArray.y = j;


			myLabirint[i][j].pos.y = i * sizeOfEveryNode;
			myLabirint[i][j].pos.x = j * sizeOfEveryNode;

			myLabirint[i][j].state = FREENODE;
			myLabirint[i][j].rect.setTexture(&textureOrdinaryNode);
			myLabirint[i][j].rect.setPosition(Vector2f(myLabirint[i][j].pos.x, myLabirint[i][j].pos.y));
			myLabirint[i][j].rect.setSize(Vector2f(sizeOfEveryNode, sizeOfEveryNode));

		}

	labirintState = INCREATION;

}



bool Labirint::findpath() {

	std::priority_queue <Node*, std::vector<Node*>, CustomCompare> open;
	std::unordered_set<Node*, std::vector<Node*>, EqualCompare> closed;

	
	Node* start = &myLabirint[startPoint.x][startPoint.y];
	Node* finish = &myLabirint[finishPoint.x][finishPoint.y];

	start->lengthpathFromStart = 0;
	start->calculateHeuristic(finish->posInArray);
	start->calculateWeightNode();

	open.push(start);

	while (!open.empty()) {

		auto x = open.top();

		if (x->posInArray == finish->posInArray) {
			break;
		}

		open.pop();

		checkNeighbour(x, open,closed, finish);

	}

	if (!open.empty()) {


		auto ptr = finish->prev;

		while (ptr != nullptr) {

			path.push_back(*ptr);
			if ((ptr->posInArray.x == startPoint.x) && (ptr->posInArray.y == startPoint.y)) {

				break;
			}

			ptr->rect.setFillColor(Color::Red);


			ptr = ptr->prev;

		}


		wasFoundThepath = true;
		return true;
	}

	else {
		wasFoundThepath = false;
		return false;
	}
}


void Labirint::processNode(Node* node, Node* finish, Node* prevNode, std::priority_queue < Node*, std::vector<Node*>, CustomCompare >& open) {


	if ((!node->closet) && (node->state != 3)) {// не стена и не закрытый список

		if (node->prev != nullptr) {// есть в открытом списке

			int prev = node->lengthpathFromStart; // текущая длина пути

			node->calculateLengthFromStart(prevNode); // новая длина пути

			if (prev <= node->lengthpathFromStart) // если новая длина пути больше, то сохраняем старый порядок
				node->lengthpathFromStart = prev;

			else {

			/*	node->prev = prevNode;
				node->calculateHeuristic(finish->posInArray);
				node->calculateWeightNode();

				std::list<Node*> copy;


				while (!open.empty()) {
					auto ptr = open.top();
					copy.push_back(ptr);
					open.pop();

					if (ptr->posInArray == node->posInArray)
						break;

				}

				while (!copy.empty()) {

					auto ptr = copy.begin();
					open.push(*ptr);
					copy.pop_front();

				}*/

			
			}

		}

		else {

			node->prev = prevNode;
			node->calculateLengthFromStart(prevNode);
			node->calculateHeuristic(finish->posInArray);
			node->calculateWeightNode();

			open.push(node);

		}

	}

}

void Labirint::checkNeighbour(
	Node* node, 
	std::priority_queue < Node*, std::vector<Node*>,CustomCompare>& open, 
	std::unordered_set<Node*, std::vector<Node*>, EqualCompare> & closed,
	Node* finish) {



	if (node->posInArray.x != 0) {
		if (node->posInArray.y != 0) {

			processNode(&myLabirint[node->posInArray.x - 1][node->posInArray.y - 1], finish, &myLabirint[node->posInArray.x][node->posInArray.y], open);

		}
		processNode(&myLabirint[node->posInArray.x - 1][node->posInArray.y], finish, &myLabirint[node->posInArray.x][node->posInArray.y], open);
		//myLabirint[node->posInArray->x - 1][node->posInArray->y];

		if (node->posInArray.y != sizeY - 1)
			processNode(&myLabirint[node->posInArray.x - 1][node->posInArray.y + 1], finish, &myLabirint[node->posInArray.x][node->posInArray.y], open);
		//myLabirint[node->posInArray->x - 1][node->posInArray->y + 1];
	}

	if (node->posInArray.x != sizeX - 1) {

		if (node->posInArray.y != 0)
			processNode(&myLabirint[node->posInArray.x + 1][node->posInArray.y - 1], finish, &myLabirint[node->posInArray.x][node->posInArray.y], open);
		//myLabirint[node->posInArray->x + 1][node->posInArray->y - 1];

		processNode(&myLabirint[node->posInArray.x + 1][node->posInArray.y], finish, &myLabirint[node->posInArray.x][node->posInArray.y], open);
		//	myLabirint[node->posInArray->x + 1][node->posInArray->y];

		if (node->posInArray.y != sizeY - 1)
			processNode(&myLabirint[node->posInArray.x + 1][node->posInArray.y + 1], finish, &myLabirint[node->posInArray.x][node->posInArray.y], open);
		//myLabirint[node->posInArray->x + 1][node->posInArray->y + 1];

	}

	if (node->posInArray.y != 0)
		processNode(&myLabirint[node->posInArray.x][node->posInArray.y - 1], finish, &myLabirint[node->posInArray.x][node->posInArray.y], open);
	//myLabirint[node->posInArray->x][node->posInArray->y - 1];

	if (node->posInArray.y != sizeY - 1)
		processNode(&myLabirint[node->posInArray.x][node->posInArray.y + 1], finish, &myLabirint[node->posInArray.x][node->posInArray.y], open);
	//myLabirint[node->posInArray->x][node->posInArray->y + 1];

	myLabirint[node->posInArray.x][node->posInArray.y].closet = true;

}