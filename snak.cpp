#include "snake.h"

void snake::get_key()
{
	prevx = snakex;
	prevy = snakey;
	if (_kbhit()) {

		switch (_getch()) {

		case 'w':
		case 'W':
			--snakey;
			state = dir::UP;
			break;

		case 's':
		case 'S':
			state = dir::DOWN;
			++snakey;

			break;

		case 'a':
		case 'A':
			state = dir::LEFT;
			--snakex;

			break;

		case 'd':
		case 'D':
			state = dir::RIGHT;
			++snakex;
			break;

		case 'p':
		case 'P':
			system("pause");
			break;


		} ///
	}  ///

	snake::tail();
}

void snake::draw()
{
	cout << "SCORE : " << score << endl;
	for (uint16_t i = 0; i < width; ++i) {
		cout << '-';
	}

	cout << endl;

	snake::eat();       ///

	if (snakex >= width - 1)
		snakex = 1;

	if (snakex <= 0)
		snakex = width - 1;

	if (snakey >= height - 1)
		snakey = 1;

	if (snakey <= 0)
		snakey = height - 1;

	window[snakey][snakex] = 'O';
	window[fruit_y][fruit_x] = '&';

	for (uint16_t i = 0; i < height;++i) {

		for (uint16_t j = 0; j < width; ++j) {
			cout << window[i][j];
		}
		cout << endl;
	}

	for (uint16_t i = 0; i < width; ++i) {
		cout << '-';
	}
}

void snake::eat()
{
	if (snakex == fruit_x && snakey == fruit_y) {

		if (num_tails == 0)
		{
			prevx = snakex;
			prevy = snakey;
		}

		++num_tails;
		++score;

		///snake::tail();

		fruit_x = rand() % width - 4;
		fruit_y = rand() % height - 5;
		fruit_x = abs(fruit_x);
		fruit_y = abs(fruit_y);

		if (fruit_x == snakex && fruit_y == snakey)
		{
			fruit_x = rand() % width - 4;
			fruit_y = rand() % height - 5;
			fruit_x = abs(fruit_x);
			fruit_y = abs(fruit_y);

		}
	}
}

void snake::tail()
{
	int* prx = new int[num_tails];
	int* pry = new int[num_tails];

	if (num_tails == 0) {
		prx[0] = NULL;        ///
		pry[0] = NULL;
	}
	if (num_tails == 1) {
		snake_tailx[0] = prevx;
		snake_taily[0] = prevy;
		window[snake_taily[0]][snake_tailx[0]] = 'o';

	} /// if num_tails....

	else if (num_tails > 1) {

		prx[0] = snake_tailx[0];
		pry[0] = snake_taily[0];
		snake_tailx[0] = prevx;
		snake_taily[0] = prevy;
		window[snake_taily[0]][snake_tailx[0]] = 'o';

		for (uint8_t i = 1; i < num_tails;++i) {
			prx[i] = snake_tailx[i];
			pry[i] = snake_taily[i];
			snake_tailx[i] = prx[i - 1];
			snake_taily[i] = pry[i - 1];
			window[snake_taily[i]][snake_tailx[i]] = 'o';

		}

	}  ///

	prx = nullptr;
	pry = nullptr;
	delete[] prx;
	delete[] pry;
}

void snake::con()
{
	/// for continous movement of the snake
	prevx = snakex;
	prevy = snakey;
	if (state == dir::UP)
		--snakey;

	else if (state == dir::DOWN)
		++snakey;

	else if (state == dir::LEFT)
		--snakex;

	else if (state == dir::RIGHT)
		++snakex;

	snake::tail();
}

void snake::collison(bool& ov) {

	for (int i = 0; i <= num_tails; ++i) {

		if (snakex == snake_tailx[i] && snakey == snake_taily[i])
		{
			system("color 4f");
			cout << "game over!" << endl;
			system("pause");
			ov = true;

		}
	}
}

void snake::set_fruits()
{
	srand(static_cast<unsigned int>(time(NULL)));

	fruit_x = rand() % width - 4;
	fruit_y = rand() % height - 5;
	fruit_x = abs(fruit_x);
	fruit_y = abs(fruit_y);

	while (fruit_x == snakex && fruit_y == snakey) {

		fruit_x = rand() % width - 4;
		fruit_y = rand() % height - 5;
		fruit_x = abs(fruit_x);
		fruit_y = abs(fruit_y);

	}
}

void snake::clear_display()
{
	for (uint16_t i = 0; i < height;++i) {
		for (uint16_t j = 0; j < width;++j) {
			window[i][j] = ' ';                  /// clear the game map
		}
	}
}