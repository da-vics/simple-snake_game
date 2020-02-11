#include "snake.h"

int main()
{
	system("mode 50");
	system("color 2");

	bool over = false;

	snake snake_obj;
	snake_obj.set_fruits();

	while (!over) {

		snake_obj.clear_display();
		snake_obj.get_key();
		snake_obj.con();
		snake_obj.draw();
		snake_obj.collison(over);

		Sleep(100);
		system("cls");
	} ///


} ///


