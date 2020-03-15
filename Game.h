#pragma once
#include "Firm.h"
#include <iostream>
using namespace std;

class Game :public Firm
{
protected:
	int idGame;
	int idFirm;
	char typeOfGame[30];
	double coefficient;
public:
	void setIdGame(int idG);
	int getIdGame();

	void setIdFirm(int idF);
	int getIdFirm();

	void setTypeOfGame(char* f);
	char* getTypeOfGame();

	void setCoefficient(int coeff);
	double getCoefficient();

	virtual void Print();
	friend void sorting(Game [], int);
	friend void sorting(int, Game []);
	Game() {}
	~Game();
};

