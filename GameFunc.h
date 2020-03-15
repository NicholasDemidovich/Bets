#pragma once
#include <iostream>
#include <conio.h>
#include "Client.h"

using namespace std;
#pragma warning(disable:4996)

void add_Game(Game obj[], int countGame, int* factCountGame)
{
	if (*factCountGame == countGame) { cout << "\n\t Список игр заполнен!" << endl; return; }
	int n = *factCountGame;
	int idGame, idFirm;
	char gameType[20];
	double coeff;
	cout << "\n\t ||| Добавляем игру |||\n";
	cout << "\n\t Введите идентификационный номер игры: ";
	cin >> idGame;
	obj[n].setIdGame(idGame);
	cout << "\n\t Введите идентификационный номер фирмы: ";
	cin >> idFirm;
	obj[n].setIdFirm(idFirm);
	cout << "\n\t Введите тип игры: ";
	cin >> gameType;
	obj[n].setTypeOfGame(gameType);
	cout << "\n\t Введите коэффициент игры: ";
	cin >> coeff;
	obj[n].setCoefficient(coeff);
	(*factCountGame)++;
}

template <typename ChangeG, typename factC>
ChangeG change_Game(ChangeG game, factC factCount)
{
	cout << "\n\t((( Изменяем параметры игры )))";
	int idGame;
	int idFirm;
	double coeff;
	cout << "\n\t Введите идентификационный номер игры:  ";
	cin >> idGame;
	cout << "\n\t Введите идентификационный номер фирмы:  ";
	cin >> idFirm;
	for (int i = 0; i < factCount; i++)
		if (game[i].getIdGame() == idGame && game[i].getIdFirm() == idFirm)
		{
			cout << "\n\t Введите новый коэффициент:  ";  cin >> coeff;
			game[i].setCoefficient(coeff);
			return 0;
		}
	cout << "\n\t Такой игры или фирмы нет!" << endl;
}

void delete_Game(Game game[], int* factCount)
{
	int idGame;
	int idFirm;
	cout << "\n\t _-_ Удаляем игру _-_";
	cout << "\n\t Введите идентификационный номер удаляемой игры:  ";
	cin >> idGame;
	cout << "\n\t Введите идентификационный номер фирмы:  ";
	cin >> idFirm;
	for (int i = 0; i < *factCount; i++)
		if (game[i].getIdGame() == idGame && game[i].getIdFirm() == idFirm)
		{
			for (int j = i; j < *factCount - 1; j++)
				game[j] = game[j + 1];
			(*factCount)--;
			return;
		}
	cout << "\n\t Такой игры или фирмы нет!" << endl;
}

void show_Game(Game obj[], int factCount)
{
	if (factCount == 0) { cout << "\n\t Создайте игру! "; return; }
	int idGame;
	double bet;
	cout << "\n\t --- Cписок игр ---\n";
	for (int i = 0; i < factCount; i++)
		cout << "\n\t Идентификационный номер фирмы: " << obj[i].getIdFirm()
		<< "\n\t Идентификационный номер игры: " << obj[i].getIdGame()
		<< "\n\t Тип игры: " << obj[i].getTypeOfGame()
		<< "\n\t Коэффициент игры: " << obj[i].getCoefficient() << endl;
}

void sorting(Game game[], int countOfGame)
{
	cout << "\n\t=== Сортируем игры по названию! ===\n\t";
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
	cout << "\n\t### Сортируем игры по идентификационному номеру! ###\n\t";
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