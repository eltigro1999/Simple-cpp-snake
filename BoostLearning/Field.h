#pragma once
#include "Apple.h"
#include "Snake.h"
#include <vector>

class Field {
	std::vector<std::vector<char>> field_template;
public:
	Field();
	void draw(Apple&, Snake&);
	void GameOver();
};