
#include <iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>

#ifndef SNAKE_H
#define SNAKE_H

using namespace std;

constexpr int16_t  width = 30;
constexpr int16_t height = 10;

enum class dir :int
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	INACTIVE
};

class snake
{
private:
	int16_t snakex,
		snakey,
		num_tails,
		prevx,
		prevy,
		fruit_x,
		fruit_y,
		score;
	dir state;
	char window[height][width];       ///  game map
	uint8_t n;

	int16_t snake_tailx[40],
		snake_taily[40];

public:
	snake()              ///
	{
		prevx = 0;
		prevy = 0;
		score = 0;
		snakex = (width / 2);
		snakey = (height / 2);
		num_tails = 0;
		fruit_x = 0;
		fruit_y = 0;
		snake_tailx[0] = NULL;
		snake_taily[0] = NULL;


		state = dir::INACTIVE;
	}

	~snake()
	{
		cout << "Game Over!" << endl;
	}

	void collison(bool&);
	void con();
	void eat();
	void draw();
	void get_key();               /// prototyped functions
	void tail();
	void set_fruits();
	void clear_display();
};

#endif