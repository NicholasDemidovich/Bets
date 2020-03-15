#include "Game.h"

void Game::setIdGame(int idG) { idGame = idG; }
int Game::getIdGame() { return idGame; }

void Game::setIdFirm(int idF) { idFirm = idF; }
int Game::getIdFirm() { return idFirm; }

void Game::setTypeOfGame(char* f) { strcpy_s(typeOfGame, f); }
char* Game::getTypeOfGame() { return typeOfGame; }

void Game::setCoefficient(int coeff) { coefficient = coeff; }
double Game::getCoefficient() { return coefficient; }

void Game::Print()
{
	cout << "\t | Type of game: " << typeOfGame << " | Id game:   "
		<< idGame << " | Coefficient:  " << coefficient << " | Name of firm " << nameOfFirm <<" |" << endl;
}

Game::~Game(){}