#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "Snake.h"
#include "Apple.h"
#include "Field.h"


int main() {
	system("Color 02");
	std::srand(std::time(0));
	Snake snake;
	Apple apple;
	Field field;
	while (!snake.Failed()) {
		field.draw(apple, snake);
		snake.Move();
	}
	field.GameOver();
}