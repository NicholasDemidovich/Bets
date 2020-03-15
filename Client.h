#pragma once
#include "Game.h"
#include <iostream>
using namespace std;

class Client :public Game
{
protected:
	int idClient, idFirm, idGame;
	int age;
	double bet;//ставка
	double bill;//кол-во денег на счету 
	char fio[30];
	bool winOrLose;
	double summOfWin;
public:
	void setIdClient(int idC);
	int getIdClient();

	void setIdFirm(int idF);
	int getIdFirm();

	void setIdGame(int idG);
	int getIdGame();

	void setAge(int a);
	int getAge();

	void setBet(double b);
	double getBet();

	void setBill(double b);
	double getBill();

	void setFio(char* f);
	char* getFio();

	void setWinOrLose(bool flag);
	bool getWinOrLose();

	void setSummOf();

	void setSummOfWin(double coif);
	double getSummOfWin();

	Client	operator+(Client  obj);    

	void printClient();
	virtual void Print();
	Client() {}
	~Client() {}
};

