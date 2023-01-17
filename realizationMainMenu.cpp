#include"Main_Menu.h"


MainMenu::MainMenu(Texture* texture, Font* font, bool& initFlag) {

	myfont = font;
	textureFon = texture;



	start.setFont(*myfont);
	start.setString(sf::String("Start"));
	start.setCharacterSize(Screen_Height / 10);
	start.setFillColor(Color(255, 210, 58));

	sf::FloatRect rectStart = start.getLocalBounds();
	start.setPosition(Vector2f(Screen_Width / 2 - rectStart.width / 2, Screen_Height / 2 - Screen_Height / 8));



	exit.setFont(*myfont);
	exit.setString("Exit");
	exit.setCharacterSize(Screen_Height / 10);
	exit.setFillColor(Color(255, 210, 58));

	sf::FloatRect rectExit = exit.getLocalBounds();

	exit.setPosition(Vector2f(Screen_Width / 2 - rectExit.width / 2, Screen_Height / 2 - Screen_Height / 8 + rectStart.height * 3));


	fon.setTexture(*textureFon);




	Vector2f scale = Vector2f(textureFon->getSize());


	scale.x = Screen_Width / scale.x;
	scale.y = Screen_Height / scale.y;



	fon.setTextureRect(sf::IntRect(Vector2i(0, 0), Vector2i(Screen_Width, Screen_Height)));
	fon.setScale(scale);


}


void MainMenu::draw( RenderWindow& window) {

	window.clear();

	window.draw(fon);
	window.draw(start);
	window.draw(exit);
	
	window.display();

}


int MainMenu::logic(Event event,RenderWindow& window) {

	Vector2f mousePos = Vector2f(sf::Mouse::getPosition(window));

	
	sf::FloatRect rectStart = start.getGlobalBounds();
	sf::FloatRect rectEnd = exit.getGlobalBounds();
	
	

	if (rectStart.contains(mousePos)) {
		start.setStyle(sf::Text::Underlined);
		if (event.type == Event::MouseButtonPressed)
			return 2;
	}
	else
		start.setStyle(Text::Regular);


	if (rectEnd.contains(mousePos)) {
		exit.setStyle(sf::Text::Underlined);
		if (event.type == Event::MouseButtonPressed)
			window.close();
	}
	else
		exit.setStyle(Text::Regular);

	

	return 0;
}



