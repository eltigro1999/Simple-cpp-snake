#include "Field.h"
#include <vector>
#include<iostream>
#include <algorithm>

Field::Field() {
	field_template.push_back(std::vector<char>(21, '#'));
	for (int i = 1; i < 20; ++i) {
		field_template.push_back(std::vector<char>(21, ' '));
		field_template[i][0] = '#';
		field_template[i][20] = '#';
	}
	field_template.push_back(std::vector<char>(21, '#'));
}

void Field::draw(Apple& apple, Snake& snake)
{
	std::system("CLS");
	std::cout << "Count: " << snake.count << std::endl;
	std::vector<std::vector<char>> field = field_template;
	if (snake.head == apple.destination) {
		snake.Eat();
		for (int i = 0; i < snake.size; ++i) {
			field[snake.snakey[i].y][snake.snakey[i].x]='s';
		}
		do {
			apple.renew_destination();
		} while (std::count(snake.snakey.begin(), snake.snakey.end(),apple.destination)!=0);
	}
	else {
		for (int i = 0; i < snake.size; ++i) {
			field[snake.snakey[i].y][snake.snakey[i].x] = 's';
		}
		field[apple.destination.y][apple.destination.x]='O';
	}
	for (const auto& lines : field) {
		for (const auto& cell : lines) {
			std::cout << cell;
		}
		std::cout << std::endl;
	}
}

void Field::GameOver() {
	std::system("CLS");
	std::cout << "##############################" << std::endl;
	std::cout << "##########GAME#OVER###########" << std::endl;
	std::cout << "##############################" << std::endl;
}