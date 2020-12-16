// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This project was created with the help of the following tutorial: Computer Graphics with Modern OpenGl and C++ 
// Link to the Course: https://www.udemy.com/course/graphics-with-modern-opengl/
// The tutorial provided the theory of the topics and then help on implementation of the discussed topic

#include "Game.h"
int main()
{
	Game* game;
	game = new Game();
	game->Start();

	delete game;

	return 0;
}