#pragma once
#include <vector>
#include "Apple.h"
#include "Coords.h"

class Snake {
public:

	Coords apple_tail;	// if apple is eaten snake will expand
						// at this coords. If it wasn't eaten it's
						//just a free variable
	Coords head;
	int size;
	int count=0;
	char direction = ' ';
	char opposite_direction = ' ';
	std::vector<Coords> snakey;
	Snake();
	void Eat();
	void Move();
	bool Failed();
private:
	void move_snake_parts();
};

