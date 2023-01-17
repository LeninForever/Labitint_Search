//#include<D:\lab_1_course\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\include\SFML\Graphics.hpp>
//#include<iostream>
//#include<string>
//#include <queue>
//
//#define barrierCount 3
//
//#define Screen_Width 800
//#define Screen_Height 640
//
//#define Field_Width Screen_Width - 100
//#define Field_Width Screen_Height- 100
//
//#define SkylineY Screen_Height *5/6
//using namespace std;
//struct PosType {
//	int x;
//	int y;
//};
//using namespace sf;
////using namespace std;
//
//
//class Bla {
//public:
//	virtual void method() = 0;
//	virtual void change();
//};
//
//class BlaBla : public Bla {
//
//public:
//	void method() override { cout << "s" << endl; }
//};
//
//class BlaBlaBla : public Bla {
//
//public:
//	void method() override { cout << "s_s" << endl; }
//};
//class Menu;
//class Gamefield {
//
//public:
//	Gamefield() {
//		barrier = new RectangleShape[barrierCount];
//		for (int i = 0; i < barrierCount; i++) {
//			barrier[i].setSize(Vector2f(30, Screen_Height / 7));
//			barrier[i].setFillColor(Color::Blue);
//			barrier[i].setPosition(Vector2f(500 + i * 500, SkylineY - barrier[i].getSize().y));
//		}
//		skyline.setPosition(0, SkylineY);
//		skyline.setSize(Vector2f(Screen_Width, Screen_Height / 100));
//		skyline.setFillColor(Color::Magenta);
//
//	}
//	~Gamefield() {
//		delete[] barrier;
//	}
//	RectangleShape& GetRect(int i) {
//		return barrier[i];
//	}
//	RectangleShape& GetSlyline() {
//		return skyline;
//	}
//	void moitionOfbarrier() {
//		for (int i = 0; i < barrierCount; i++) {
//			barrier[i].setPosition(Vector2f(((Screen_Width + int((barrier[i].getPosition().x - speed))) % Screen_Width), barrier[i].getPosition().y));
//		}
//	}
//
//	friend class Menu;
//private:
//	RectangleShape* barrier;
//	RectangleShape skyline;
//	int speed = 1;
//
//};
//class Menu {
//public:
//	void mr() {
//
//	}
//};
//class Player {
//
//public:
//	Player(std::string path) {
//		speed = 10;
//		sprite.setScale(Vector2f(0.2, 0.5));
//		pos.x = Screen_Width / 10;
//		pos.y = Screen_Height * 9 / 10 - Screen_Height / 7;
//		this->texture.loadFromFile(path);
//		sprite.setTexture(texture);
//
//
//		sprite.setPosition(pos.x, SkylineY - sprite.getTextureRect().height / 2);
//	}
//
//	friend class Gamefield;
//	void move(Keyboard::Key direction) {
//		if (direction == Keyboard::Right)
//			pos.x += speed;
//		else if (direction == Keyboard::Left)
//			pos.x -= speed;
//		else if (direction == Keyboard::Up)
//			pos.y -= speed;
//		else if (direction == Keyboard::Down)
//			pos.y += speed;
//		sprite.setPosition(pos.x, pos.y);
//	}
//	Sprite GetSprite() {
//		return sprite;
//	}
//
//	void jump() {
//
//		//sprite.setPosition(pos.x, pos.y-=5);
//
//	}
//	void jump(int y) {
//		sprite.setPosition(pos.x, pos.y -= y);
//	}
//	void printPos() {
//		cout << " pos.x = " << pos.x << "pos.y = " << pos.y << endl;
//	}
//private:
//	int speed;
//	PosType pos;
//	Texture texture;
//	Sprite sprite;
//
//};
//
//
//
//int main() {
//	RenderWindow window(VideoMode(Screen_Width, Screen_Height), "Jumper");
//
//	auto desktop = sf::VideoMode::getDesktopMode();
//
//	Vector2i  centerPos(desktop.width / 2 - window.getSize().x / 2, desktop.height / 2 - window.getSize().y / 2);
//
//	window.setPosition(centerPos);
//
//	//Texture texture;
//	std::string path = "textures\\second.jpg";
//	//texture.loadFromFile(path);
////	std :: cout <<texture.getSize().x << " " << texture.getSize().y << std::endl;
//	//IntRect rect(0, 0, texture.getSize().x, texture.getSize().y);
//	//Sprite first_sprite(texture,rect);
//	Player maxim(path);
//	Gamefield gamefield;
//	//std::cout <<" x = "<< first_sprite.getPosition().x << "\ny =  " << first_sprite.getPosition().y << std::endl;
//	Time time;
//	Clock clock;
//
//
//	priority_queue <Player, vector<Player>> my;
//	//first_sprite.setPosition(25,13);
//	Event event;
//	RectangleShape brrr(Vector2f(70.f, 100.f));
//brrr:Vector2f(70.f, 100.f);
//	brrr.setFillColor(sf::Color::Blue);
//	sf::sleep(sf::milliseconds(1000));
//	while (window.isOpen()) {
//
//		time = clock.getElapsedTime();
//		while (window.pollEvent(event)) {
//			if (event.type == Event::Closed)
//				window.close();
//			if (Keyboard::isKeyPressed(Keyboard::Down))
//				maxim.move(Keyboard::Key::Down);
//			else if (Keyboard::isKeyPressed(Keyboard::Up))
//				maxim.move(Keyboard::Key::Up);
//
//			else if (Keyboard::isKeyPressed(Keyboard::Right))
//				maxim.move(Keyboard::Key::Right);
//
//			else if (Keyboard::isKeyPressed(Keyboard::Left))
//				maxim.move(Keyboard::Key::Left);
//			if (Keyboard::isKeyPressed(Keyboard::Space)) {
//				maxim.jump();
//			}
//
//
//		}
//
//		gamefield.moitionOfbarrier();
//		//sf::sleep(sf::milliseconds(10));
//		window.clear(Color(255, 128, 25, 34));
//
//
//		window.draw(maxim.GetSprite());
//
//		for (int i = 0; i < barrierCount; i++)
//			window.draw(gamefield.GetRect(i));
//
//		window.draw(gamefield.GetSlyline());
//		//	window.draw(brrr);
//		window.display();
//	}
//	return 0;
//}