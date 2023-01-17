#pragma once
#include"basicClasses.h"

class Application;

class Labirint :public Menu {

private:
	int sizeX;
	int sizeY;
	float sizeOfEveryNode = 0;

	Node** myLabirint = nullptr;

	int cursorState = NOTHING;

	short labirintState = 0;

	bool wasChoosenStart = false;
	bool wasChoosenFinish = false;
	bool wasFoundThepath = false;


	bool inCreation = false;

	std::list<Node> path;


	Font* font;

	Texture textureWall;
	Texture textureBarrier;
	Texture textureOrdinaryNode;
	Texture textureStart;
	Texture textureFinish;
	Texture texturepath;
	Texture textureFon;


	RectangleShape rectStart;
	RectangleShape rectFinish;
	RectangleShape rectFon;
	RectangleShape rectWall;
	RectangleShape rectFreeNode;
	RectangleShape rectBarrier;



	Text textStart;
	Text textFinish;
	Text textChoosePosition;
	Text textFindThepath;
	Text textChooseNew;

	Text textWall;
	Text textBarrier;
	Text textOrdinary;
	Text textSave;


	Text textBackToMenu;

	intPoint prevPoint;

	intPoint startPoint;
	intPoint finishPoint;


	struct CustomCompare
	{
		bool operator()(const Node* node_1, const Node* node_2)
		{
			return node_1->weightNode > node_2->weightNode;
		}
	};

	struct EqualCompare {
		bool operator()(const Node* node_1, const Node* node_2) {
			return node_1->posInArray == node_2->posInArray;
		}
	};





	void processNode(Node* node, Node* finish, Node* prevNode, std::priority_queue < Node*, std::vector<Node*>, CustomCompare >& open);

	void checkNeighbour(Node* node, std::priority_queue < Node*, std::vector<Node*>, CustomCompare >& open, 
		std::unordered_set<Node*, std::vector<Node*>, EqualCompare> &closed,
		Node* finish);


public:
	Labirint(Font* font, bool& initFlag);

	void createLabirint(short _choice);

	void randCreation();
	void userCreation();

	bool findpath();

	virtual void draw(RenderWindow& window) override;
	virtual int logic(Event event, RenderWindow& window) override;

	void setSize(int x, int y) { sizeX = x; sizeY = y; }
	friend class Application;
};