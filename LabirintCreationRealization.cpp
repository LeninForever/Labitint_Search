#include"LabirintOptions.h"

LabirintOption::LabirintOption(Texture* texture, Font* font,bool &initFlag) {

	textureFon = texture;
	myfont = font;

	
		
	
	
	textLabirintOptions.setString(sf::String("Labirint options"));
	textLabirintOptions.setCharacterSize(Size_Font);
	textLabirintOptions.setPosition(Screen_Width / 14.0f, Screen_Height / 13);
	textLabirintOptions.setFillColor(Color(255, 210, 58));
	textLabirintOptions.setFont(*font);


	textChooseRandom.setString(sf::String("Create random labirint"));
	textChooseRandom.setCharacterSize(Size_Font);
	textChooseRandom.setPosition(Screen_Width / 14.0f, Screen_Height / 3.5f);
	textChooseRandom.setFillColor(Color(255, 210, 58));
	textChooseRandom.setFont(*font);
	
	
	textUserCreate.setString(sf::String("Create your own labirint"));
	textUserCreate.setCharacterSize(Size_Font);
	textUserCreate.setPosition(Screen_Width / 14.0f, Screen_Height / 2.5);
	textUserCreate.setFillColor(Color(255, 210, 58));
	textUserCreate.setFont(*font);

	
	textSizeX.setString(sf::String("Size X"));
	textSizeX.setCharacterSize(Size_Font);
	textSizeX.setPosition(Screen_Width / 3.0f, Screen_Height * 0.6f);
	textSizeX.setFillColor(sf::Color(255, 210, 58));
	textSizeX.setFont(*font);

	textBack.setString(sf::String("Back"));
	textBack.setCharacterSize(Size_Font);
	textBack.setPosition(Screen_Width/100, Screen_Height * 0.9f);
	textBack.setFillColor(sf::Color(255, 210, 58));
	textBack.setFont(*font);

	//textSizeY.setString(sf::String("Size Y"));
	//textSizeY.setCharacterSize(Size_Font);
	//textSizeY.setPosition(Screen_Width / 3.0f, Screen_Height * 0.75f);
	//textSizeY.setFillColor(sf::Color(255, 210, 58));
	//textSizeY.setFont(*font);

	
	textEnterX.setString(sf::String("19 < x < 51"));
	textEnterX.setCharacterSize(Size_Font);
	textEnterX.setPosition(Screen_Width *0.45f + Screen_Width * 0.01f, Screen_Height * 0.6f + Screen_Height * 0.001f);
	textEnterX.setFillColor(sf::Color(255, 210, 58));
	textEnterX.setFont(*font);

	
	//textEnterY.setString(sf::String("Y < X - 10 "));
	//textEnterY.setCharacterSize(Size_Font);
	//textEnterY.setPosition(Screen_Width *0.45f + Screen_Width * 0.01f, Screen_Height * 0.75f + Screen_Height * 0.001f);
	//textEnterY.setFillColor(sf::Color(255, 210, 58));
	//textEnterY.setFont(*font);

	
	textCreate.setString(sf::String("Create!"));
	textCreate.setCharacterSize(Size_Font);
	textCreate.setPosition(Screen_Width * 0.7f, Screen_Height * 0.85f);
	textCreate.setFillColor(sf::Color(255, 210, 58));
	textCreate.setFont(*font);


	Vector2f scale = Vector2f(textureFon->getSize());

	scale.x = Screen_Width / scale.x;
	scale.y = Screen_Height / scale.y;

	spriteFon.setTexture(*textureFon);
	spriteFon.setScale(scale);
	
	if (!imageFrame.loadFromFile("textures//frame.bmp"))
		initFlag = false;
	
	imageFrame.createMaskFromColor(sf::Color(255, 255, 255), 0);
	textureFrame.loadFromImage(imageFrame);
	

	if (!imageActiveFrame.loadFromFile("textures//activeFrame.bmp"))
		initFlag = false;
	
	imageActiveFrame.createMaskFromColor(sf::Color(255, 255, 255), 0);
	textureActiveFrame.loadFromImage(imageActiveFrame);


	
	rectFrameX.setSize(Vector2f(Screen_Width / 6.0f, Screen_Height / 10.0f));
	rectFrameX.setTexture(&textureActiveFrame);
	rectFrameX.setPosition(Screen_Width * 0.45f, Screen_Height * 0.6f);
	
	//rectFrameY.setSize(Vector2f(Screen_Width / 6.0f, Screen_Height / 10.0f));
	//rectFrameY.setTexture(&textureFrame);
	//rectFrameY.setPosition(Screen_Width * 0.45f, Screen_Height * 0.75f);
	
	
	cursor.setFillColor(Color(255, 210, 58));
	

	auto bounds = textEnterX.getGlobalBounds();

	cursor.setSize(Vector2f(Screen_Width / 500.0f, bounds.height));
	
	cursor.setPosition(bounds.left + bounds.width, bounds.top);

}

void LabirintOption::draw(RenderWindow& window) {

	
	
	window.clear();

	window.draw(spriteFon);

	window.draw(textLabirintOptions);
	
	window.draw(textBack);

	if (!inActiveSize)
	window.draw(textChooseRandom);
	
	window.draw(textUserCreate);
	
	if (inActiveSize) {
		window.draw(textSizeX);
//		window.draw(textSizeY);

		window.draw(textEnterX);
	//	window.draw(textEnterY);
		
		if (inActiveCreate) {
		
			if (textEnterX.getFillColor() == sf::Color::Red) {
				
				window.draw(textCreate);
				window.display();

				sf::sleep(seconds(2));


				sf::FloatRect rect = textEnterX.getGlobalBounds();
				cursor.setPosition(rect.left + rect.width, rect.top);

				textEnterX.setFillColor(Color(255, 210, 58));
				startEnterX = false;


			}
			else
				window.draw(textCreate);
		
		}
		window.draw(rectFrameX);
		//window.draw(rectFrameY);
		
		
		time = timer.getElapsedTime().asSeconds();
		if (time > 1) {
			window.draw(cursor);

		}
		if (time > 2)
			timer.restart();
	}
	

	

	window.display();
}

int LabirintOption::logic(Event event, RenderWindow& window) {

	

	Vector2f mousePos = Vector2f(sf::Mouse::getPosition(window));

	sf::FloatRect rectChoseRandom = textChooseRandom.getGlobalBounds();
	sf::FloatRect rectUserCreate = textUserCreate.getGlobalBounds();
	sf::FloatRect rectCreate = textCreate.getGlobalBounds();

	sf::FloatRect rectSizeX = rectFrameX.getGlobalBounds();
//	sf::FloatRect rectSizeY = rectFrameY.getGlobalBounds();
	sf::FloatRect rectBack = textBack.getGlobalBounds();
	

	if (rectChoseRandom.contains(mousePos)) {
		textChooseRandom.setStyle(sf::Text::Underlined);
		if (event.type == Event::MouseButtonPressed) {
			textChooseRandom.setStyle(sf::Text::Underlined);
			choice = 1;
			return 3;
		}
		}
		else
			textChooseRandom.setStyle(Text::Regular);

		if (rectUserCreate.contains(mousePos)) {
			if (!inActiveSize) {
				textUserCreate.setStyle(sf::Text::Underlined);

			
			}

			if (event.type == Event::MouseButtonPressed) {
				inActiveSize = true;
				timer.restart();
				return 0;
			}
		}
		else
			textUserCreate.setStyle(Text::Regular);

		if (rectCreate.contains(mousePos)) {

			if (inActiveCreate)
				textCreate.setStyle(sf::Text::Underlined);

			if (event.type == Event::MouseButtonPressed) {
			
				if ((sizeX < 20) || (sizeX > 50)) {

					textEnterX.setString("19 < x < 51");
					textEnterX.setFillColor(Color::Red);

				}

				else {

					textBack.setStyle(sf::Text::Regular);
					inActiveCreate = false;
					inActiveSize = false;
					startEnterX = false;
					textEnterX.setString("20 < x < 40");
					
					sf::FloatRect rect = textEnterX.getGlobalBounds();
					cursor.setPosition(rect.left + rect.width, rect.top);


					choice = 2;
					return 3;
				
				}
			
			}

		}
		else 	
			textCreate.setStyle(sf::Text::Regular);


		if (rectBack.contains(mousePos)) {

			textBack.setStyle(sf::Text::Underlined);

			if (event.type == Event::MouseButtonPressed) {

				
				
				textBack.setStyle(sf::Text::Regular);
				inActiveCreate = false;
				inActiveSize = false;
				startEnterX = false;
				textEnterX.setString("20 < x < 40");
				
				sf::FloatRect rect = textEnterX.getGlobalBounds();

				cursor.setPosition(rect.left + rect.width, rect.top);
				return 1;
			}

		}

		else textBack.setStyle(sf::Text::Regular);

		if (event.type == Event::MouseButtonPressed) {

			

			if (rectSizeX.contains(mousePos)) {
				sf::FloatRect rect = textEnterX.getGlobalBounds();
				//inputX = true;
				rectFrameX.setTexture(&textureActiveFrame);
				//rectFrameY.setTexture(&textureFrame);
				cursor.setPosition(rect.left + rect.width, rect.top);
			}

			/*else if (rectSizeY.contains(mousePos)) {

				sf::FloatRect rect = textEnterY.getGlobalBounds();
				inputX = false;
				rectFrameY.setTexture(&textureActiveFrame);
				rectFrameX.setTexture(&textureFrame);
				cursor.setPosition(rect.left + rect.width, rect.top);
			}*/

		}

			
		if (event.type == Event::KeyPressed) {

			int keyNumber = -1;
			Text* textptr;
			int* sizeptr;
			bool* startEnter;

		switch (event.key.code) {
			case Keyboard::Num0: {
				
				keyNumber = 0;
				break;
			}
			case Keyboard::Num1: {
				
				keyNumber = 1;
				break;
			}
			case Keyboard::Num2: {

				keyNumber = 2;
				break;
			}
			case Keyboard::Num3: {

				keyNumber = 3;
				break;
			}
			case Keyboard::Num4: {

				keyNumber = 4;
				break;
			}
			case Keyboard::Num5: {

				keyNumber = 5;
				break;
			}
			case Keyboard::Num6: {

				keyNumber = 6;
				break;

			}
			case Keyboard::Num7: {

				keyNumber = 7;
				break;
			}
			case Keyboard::Num8: {

				keyNumber = 8;
				break;
			}
			case Keyboard::Num9: {

				keyNumber = 9;
				break;
			}
			case Keyboard::BackSpace: {

				keyNumber = 10;
				break;
			default:
				return 0;
			}
			}

	//	if (inputX) {

			textptr = &textEnterX;
			sizeptr = &sizeX;
			startEnter = &startEnterX;

	//	}
	//	else {

		/*	textptr = &textEnterY;
			sizeptr = &sizeY;
			startEnter = &startEnterY;*/
		//}

		

		std::string str = textptr->getString();
		
		if (keyNumber == 10) {

			if (*startEnter) {

				str.pop_back();
				
				if (str.empty()) {
					textptr->setString("");
					*sizeptr = 0;
					*startEnter = false;
				}
			
				else {
					textptr->setString(str);
					*sizeptr = atoi(str.c_str());
				}
			}
			else {
				if (str.empty())
					return 0;
				str.clear();
				//str += std::to_string(0);
				textptr->setString(str);
				*sizeptr = atoi(str.c_str());
				//*startEnter = true;
			}
		}

		else {
			std::string check = textptr->getString();

			if (check.length() == 2)
				return 0;

			if (*startEnter) {
				str += std::to_string(keyNumber);
				textptr->setString(str);
				*sizeptr = atoi(str.c_str());

			}

			else {
				str.clear();
				str = std::to_string(keyNumber);
				textptr->setString(str);
				*sizeptr = atoi(str.c_str());
				
				*startEnter = true;
			}
		}

		sf::FloatRect rectForCursor = textptr->getGlobalBounds();
		cursor.setPosition(Vector2f(rectForCursor.left+rectForCursor.width, rectForCursor.top));
		if ((startEnterX == true)) //&& (startEnterY == true))
			inActiveCreate = true;
		else
			inActiveCreate = false;
		}
	


	return 0;

}

