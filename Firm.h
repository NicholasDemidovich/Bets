#pragma once
#include "Abstr.h"
#include <iostream>
using namespace std;

class Firm :public Abstr
{
protected:
	int idFirm;
	char nameOfFirm[30];
	char address[50];
	char numberOfPhone[20];
	double moneyOfFirm;
	bool resultGame = false;
public:
	void setIdFirm(int idF);
	int getIdFirm();

	void setNameOfFirm(char* f);
	char* getNameOfFirm();

	void setAddress(char* f);
	char* getAddress();

	void setNumberOfPhone(char* f);
	char* getNumberOfPhone();

	void setResultGame(bool fl);
	bool getResultGame();

	virtual void Print();
	void setMoneyOfFirm(double money);
	double getMoneyOfFirm();
	void AddMoney(double money);
	void SubMoney(double money);
};
