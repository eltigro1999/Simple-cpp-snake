#include "Snake.h"
#include <conio.h>
#include <vector>

Snake::Snake() {
	head.x = 10;
	head.y = 10;
	snakey.push_back(head);
	apple_tail = head;
	size = snakey.size();
}

void Snake::Move() {
	do{
		if (_kbhit) {
			direction = _getch();
			if (opposite_direction != direction) {
				move_snake_parts();
				switch (direction) {
				case 'w':
					opposite_direction = 's';
					snakey[0].y -= 1;
					break;
				case 's':
					snakey[0].y += 1;
					opposite_direction = 'w';
					break;
				case 'a':
					snakey[0].x -= 1;
					opposite_direction = 'd';
					break;
				case 'd':
					snakey[0].x += 1;
					opposite_direction = 'a';
					break;
				default: break;
				}
			}
		}
	} while (opposite_direction == direction);
	head = snakey[0];
}

void Snake::move_snake_parts() {
	apple_tail = snakey[snakey.size() - 1];
	for (int i = snakey.size() - 2; i >=0; --i) {
		snakey[i + 1] = snakey[i];
	}

}


void Snake::Eat() {
	snakey.push_back(apple_tail);
	size=snakey.size();
	++count;
}
bool Snake::Failed() {
	for (int i = 1; i < size; ++i) {
		if (head == snakey[i]) {
			return true;
		}
	}
	if (head.x == 0 || head.x == 20) {
		return true;
	}
	else if (head.y == 0 || head.y == 20) {
		return true;
	}
	return false;
}