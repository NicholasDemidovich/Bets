#pragma once
#include <iostream>
#include <conio.h>
#include "Client.h"

using namespace std;
#pragma warning(disable:4996)

void add_Game(Game obj[], int countGame, int* factCountGame)
{
	if (*factCountGame == countGame) { cout << "\n\t ������ ��� ��������!" << endl; return; }
	int n = *factCountGame;
	int idGame, idFirm;
	char gameType[20];
	double coeff;
	cout << "\n\t ||| ��������� ���� |||\n";
	cout << "\n\t ������� ����������������� ����� ����: ";
	cin >> idGame;
	obj[n].setIdGame(idGame);
	cout << "\n\t ������� ����������������� ����� �����: ";
	cin >> idFirm;
	obj[n].setIdFirm(idFirm);
	cout << "\n\t ������� ��� ����: ";
	cin >> gameType;
	obj[n].setTypeOfGame(gameType);
	cout << "\n\t ������� ����������� ����: ";
	cin >> coeff;
	obj[n].setCoefficient(coeff);
	(*factCountGame)++;
}

template <typename ChangeG, typename factC>
ChangeG change_Game(ChangeG game, factC factCount)
{
	cout << "\n\t((( �������� ��������� ���� )))";
	int idGame;
	int idFirm;
	double coeff;
	cout << "\n\t ������� ����������������� ����� ����:  ";
	cin >> idGame;
	cout << "\n\t ������� ����������������� ����� �����:  ";
	cin >> idFirm;
	for (int i = 0; i < factCount; i++)
		if (game[i].getIdGame() == idGame && game[i].getIdFirm() == idFirm)
		{
			cout << "\n\t ������� ����� �����������:  ";  cin >> coeff;
			game[i].setCoefficient(coeff);
			return 0;
		}
	cout << "\n\t ����� ���� ��� ����� ���!" << endl;
}

void delete_Game(Game game[], int* factCount)
{
	int idGame;
	int idFirm;
	cout << "\n\t _-_ ������� ���� _-_";
	cout << "\n\t ������� ����������������� ����� ��������� ����:  ";
	cin >> idGame;
	cout << "\n\t ������� ����������������� ����� �����:  ";
	cin >> idFirm;
	for (int i = 0; i < *factCount; i++)
		if (game[i].getIdGame() == idGame && game[i].getIdFirm() == idFirm)
		{
			for (int j = i; j < *factCount - 1; j++)
				game[j] = game[j + 1];
			(*factCount)--;
			return;
		}
	cout << "\n\t ����� ���� ��� ����� ���!" << endl;
}

void show_Game(Game obj[], int factCount)
{
	if (factCount == 0) { cout << "\n\t �������� ����! "; return; }
	int idGame;
	double bet;
	cout << "\n\t --- C����� ��� ---\n";
	for (int i = 0; i < factCount; i++)
		cout << "\n\t ����������������� ����� �����: " << obj[i].getIdFirm()
		<< "\n\t ����������������� ����� ����: " << obj[i].getIdGame()
		<< "\n\t ��� ����: " << obj[i].getTypeOfGame()
		<< "\n\t ����������� ����: " << obj[i].getCoefficient() << endl;
}

void sorting(Game game[], int countOfGame)
{
	cout << "\n\t=== ��������� ���� �� ��������! ===\n\t";
	Game temp;
	for (int i = 0; i < countOfGame; i++)
		for (int j = i; j < countOfGame; j++)
			if (strcmp(game[i].typeOfGame, game[j].typeOfGame) > 0)
			{
				temp = game[i];
				game[i] = game[j];
				game[j] = temp;
			}
}

void sorting(int countOfGame, Game game[])
{
	cout << "\n\t### ��������� ���� �� ������������������ ������! ###\n\t";
	Game temp;
	for (int i = 0; i < countOfGame; i++)
		for (int j = i; j < countOfGame; j++)
			if (game[i].idGame > game[j].idGame)
			{
				temp = game[i];
				game[i] = game[j];
				game[j] = temp;
			}
}