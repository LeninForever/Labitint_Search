#pragma once
#include<E:\lab_1_course\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\include\SFML\Graphics.hpp>

#include<iostream>
#include<vector>
#include<queue>
#include<list>

#define Screen_Width 1200
#define Screen_Height 800
#define Size_Font 66

#define Labirint_Width Screen_Height
#define Labirint_Height Screen_Height



using namespace sf;


enum NODE_STATE
{
	FREENODE = 1,
	BARRIER = 2,
	WALL = 3

};

enum LABIRINT_STATE {

	WASNTCREATE = 0,
	INCREATION = 1,
	READYTOFIND = 2,
};

enum CURSOR_STATE {

	NOTHING = 0,
	DRAWFREE = 1,
	DRAWBARRIER = 2,
	DRAWWALL = 3,
	DRAWSTART = 4,
	DRAWFINISH = 5,


};

struct Point {

	float x;
	float y;
	Point() : x(0), y(0) {};

	friend bool operator== (const Point& p1, const Point& p2) { if ((p1.x == p2.x) && (p1.y == p2.y))return true; else return false; }
};


struct intPoint {

	int x;
	int y;
	intPoint() : x(0), y(0) {};

	friend bool operator== (const intPoint& p1, const intPoint& p2) { if ((p1.x == p2.x) && (p1.y == p2.y))return true; else return false; }

};


class Node {

	Point pos;

	intPoint posInArray;
	RectangleShape rect;
	int state = 0;

	Node* prev = nullptr;

	bool closet = false;

	int lengthpathFromStart = 0;
	int heuristicpath = 0; //from current to end 
	int weightNode = 0;


public:
	void calculateLengthFromStart(const Node* node);
	void calculateHeuristic(const intPoint& point);
	void calculateWeightNode() { weightNode = lengthpathFromStart + heuristicpath; }

	//Texture texture;
	friend class Labirint;

};

class Menu {



public:
	virtual void draw(RenderWindow& window) = 0;
	virtual int logic(Event event, RenderWindow& window) = 0;
};


