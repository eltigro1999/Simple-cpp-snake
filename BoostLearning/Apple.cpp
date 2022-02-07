#include "Apple.h"
#include "cstdlib"

Apple::Apple() {
	renew_destination();
}

void Apple::renew_destination() {
	destination.x = std::rand() % 19 + 1;
	destination.y = std::rand() % 19 + 1;
}