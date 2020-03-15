#pragma once
#include <iostream>
#include <conio.h>
#include "Client.h"
#include "ErrorBill.h"
using namespace std;

void show_Clients(Client obj[], int factCount)
{
	if (factCount == 0) { cout << "\n\t �������� �������! "; return; }
	cout << "\n\t\t������ ��������" << endl;
	for (int i = 0; i < factCount; i++)  	obj[i].printClient();
}


void correct_Bet(Client obj[], int factCount)
{
	if (factCount == 0) { cout << "\n\t �������� �������! "; return; }
	int idGame, idClient, money;
	double bet;
	int n = factCount;
	cout << "\n\t ������� ����������������� ����� ����:  ";
	cin >> idGame;
	cout << "\n\t ������� ����������������� ����� ������:  ";
	cin >> idClient;
	for (int i = 0; i < n; i++)
	{
		if (idGame == obj[i].getIdGame() && idClient == obj[i].getIdClient())
		{
			if (obj[i].getBet() != 0)
			{
				bet = obj[i].getBet();
				money = obj[i].getBill();
				money += bet;
				obj[i].setBill(money);
			}
			cout << "\n\t ������� ����� ������:  ";
			cin >> bet;
			obj[i].setBet(bet);
			money = obj[i].getBill();
			money -= bet;
			obj[i].setBill(money);
			return;
		}
	}
	cout << "\n\t ������ ������� ���!" << endl;
}

void show_ResultOfBet(Client obj[], int factCount)
{
	if (factCount == 0) { cout << "\n\t �������� �������! "; return; }
	int id;
	double bet;
	cout << "\n\t ������� ����������������� ����� �������:  ";
	cin >> id;
	for (int i = 0; i < factCount; i++)
		if (obj[i].getIdClient() == id)
			if (obj[i].getWinOrLose())
			{
				cout << "\n\t �����������,�� ��������!   ";
				obj[i].Print();
				return;
			}
			else
			{
				cout << "\n\t �������� ����������,�� ��������� :-( ";
				obj[i].Print();
				return;
			}
	cout << "\n\t ������ ������� ���!" << endl;
}

void show_Client(Client obj[], int factCount)
{
	if (factCount == 0) { cout << "\n\t �������� �������! "; return; }
	int id;
	double bet;
	cout << "\n\t ������� ����������������� ����� �������:  ";
	cin >> id;
	for (int i = 0; i < factCount; i++)
		if (obj[i].getIdClient() == id)
		{
			obj[i].printClient();
			return;
		}
	cout << "\n\t ������ ������� ���!" << endl;
}

void add_Client(Client obj[], int countClient, int* factCountClient)
{
	if (*factCountClient == countClient) { cout << "\n\t ������ �������� ��������!" << endl; return; }
	int n = *factCountClient;
	int idFirm, idGame, idClient;
	int age;
	char surname[20];
	double bet, money;
	cout << "\n\t +++ ��������� ������� +++\n";
	cout << "\n\t ������� ����������������� ����� �����:  ";
	cin >> idFirm;
	obj[n].setIdFirm(idFirm);
	cout << "\n\t ������� ����������������� ����� ����:  ";
	cin >> idGame;
	obj[n].setIdGame(idGame);
	cout << "\n\t ������� ����������������� ����� �������:  ";
	cin >> idClient;
	obj[n].setIdClient(idClient);
	while (true)
	{
		try
		{
			cout << "\n\t ������� ������� �������:  ";
			cin >> age;
			if (age < 21 || age>130)throw - 777;
			obj[n].setAge(age); break;
		}
		catch (int)
		{
			cout << "\n\t ������� ������� >= 21 && <= 130 \n"; continue;
		}
	}
	cout << "\n\t ������� ������� �������:  ";
	cin >> surname;
	obj[n].setFio(surname);
	cout << "\n\t ������� ����� ������ �������:  ";
	cin >> money;
	obj[n].setBill(money);
	obj[n].setBet(0);
	obj[n].setSummOf();
	(*factCountClient)++;
}



void add_Bet(Firm firm,Client obj[], int factCountClient)
{
	int n = factCountClient;
	int idGame, idClient;
	int age;
	double bet, money;
	cout << "\n\t $$$ ��������� ������ $$$\n";
	cout << "\n\t ������� ����������������� ����� ����:  ";
	cin >> idGame;
	cout << "\n\t ������� ����������������� ����� ������:  ";
	cin >> idClient;
	try
	{
		for (int i = 0; i < n; i++)
		{
			if (idGame == obj[i].getIdGame() && idClient == obj[i].getIdClient())
			{
				cout << "\n\t ������� ������ �������:  ";
				cin >> bet;
				money = obj[i].getBill();
				if (bet > obj[i].getBill()) { throw ErrorBill(bet, money); }
				obj[i].setBet(bet);
				money -= bet;
				obj[i].setBill(money);
				firm.setResultGame(false);
				return;
			}
		}
	}
	catch (double bet)
	{
		cout << "\n\tERROR:���� ������ " << bet << " ������ ������ ������:  " << money << endl;
	}
	catch (...)
	{
		cout << "\n\tERROR:���� ������ " << bet << " ������ ������ ������:  " << money << endl;
	}
	cout << "\n\t ������ ������� �������!!!";
}

void delete_Client(Client client[], int* factCount)
{
	int idClient;
	int idGame;
	int idFirm;
	cout << "\n\t %%% ������� ������� %%%\n";
	cout << "\n\t ������� ����������������� ����� ���������� �������:  ";
	cin >> idClient;
	cout << "\n\t ������� ����������������� ����� ����:  ";
	cin >> idGame;
	cout << "\n\t ������� ����������������� ����� �����:  ";
	cin >> idFirm;
	for (int i = 0; i < *factCount; i++)
		if (client[i].getIdClient() == idClient && client[i].getIdFirm() == idFirm && client[i].getIdGame() == idGame)
		{
			cout << "\n\t ������ ������ � �����������  " << endl;
			cout << "\t Fio: " << client[i].getFio() << " Id Game:   " << idGame
				<< "  Bet:  " << client[i].getBet() << " ID Firm:  " << idFirm << endl;
			for (int j = i; j < *factCount - 1; j++)
				client[j] = client[j + 1];
			(*factCount)--;
			return;
		}
	cout << "\n\t ����� ����,������� ��� ����� ���!" << endl;
}

void change_Client(Client client[], int factCount)
{
	int idClient;
	int idGame;
	int idFirm;
	int sw;
	double bet;
	cout << "\n\t !!! �������� ������� !!!\n";
	cout << "\n\t ������� ����������������� ����� ����������� �������:  ";
	cin >> idClient;
	cout << "\n\t ������� ����������������� ����� ����:  ";
	cin >> idGame;
	cout << "\n\t ������� ����������������� ����� �����:  ";
	cin >> idFirm;
	for (int i = 0; i < factCount; i++)
		if (client[i].getIdClient() == idClient && client[i].getIdFirm() == idFirm && client[i].getIdGame() == idGame)
		{
			while (true)
			{
				cout << "\n\t ������� ����?(1 - yes/0 - no)";
				cin >> sw;
				if (sw == 0 || sw == 1)break;
			}
			if (sw == 1)
			{
				cout << "\n\t ������� ����� ����:  ";
				cin >> idGame;
				client[i].setIdGame(idGame);
			}
			while (true)
			{
				cout << "\n\t ������� ������?(1 - yes/0 - no)";
				cin >> sw;
				if (sw == 0 || sw == 1)break;
			}
			if (sw == 1)
			{
				cout << "\n\t ������� ����� ������:  ";
				cin >> bet;
				client[i].setBet(bet);
			}
			return;
		}
	cout << "\n\t ����� ����,������� ��� ����� ���!" << endl;
}


void winOrLose_Client(Client client[], int factCount, Game game[], int m)
{
	int idClient;
	int idGame;
	int idFirm;
	int sw;
	double coeff=0;
	double money, summOfWin;
	cout << "\n\t /// ���������� ��������� ���� ///\n";
	cout << "\n\t ������� ����������������� ����� �������:  ";
	cin >> idClient;
	cout << "\n\t ������� ����������������� ����� ����:  ";
	cin >> idGame;
	cout << "\n\t ������� ����������������� ����� �����:  ";
	cin >> idFirm;
	for (int i = 0; i < factCount; i++)
		if (client[i].getIdClient() == idClient && client[i].getIdFirm() == idFirm &&
			client[i].getIdGame() == idGame && client[i].getBet() != 0)
		{
			for (int j = 0; j < m; j++)
				if (game[j].getIdGame() == idGame)
				{
					coeff = game[j].getCoefficient();
				}
			while (true)
			{
				cout << "\n\t 1 - ������� , 0 - ��������(����� � ���� �� ����������!): ";
				cin >> sw;
				if (sw == 1)
				{
					client[i].setWinOrLose(true);
					client[i].setSummOfWin(coeff);
					money = client[i].getBill();
					summOfWin = client[i].getSummOfWin();
					money += summOfWin;
					money += client[i].getBet();
					client[i].setBill(money);
					break;
				}
				if (sw == 0)
				{
					client[i].setWinOrLose(false);
					client[i].setSummOfWin(-1);
					break;
				}
			}
			return;
		}
	cout << "\n\t ����� ����,������� ��� ����� ���!" << endl;
}

void resultOfGame(Firm& firm, Client client[], int countOfClient)
{
	cout << "\n\t &&& ����� ���������� ����! &&&\n";
	double win = 0, lose = 0, money=0;
	for (int i = 0; i < countOfClient; i++)
	{
		if (client[i].getSummOfWin() > 0)
		{
			win += client[i].getSummOfWin();
		}
		else lose += client[i].getSummOfWin();
	}
	cout << "\n\t ����� ������� �������� ��������: " << win;
	cout << "\n\t ����� �������� �������� ��������: " << -lose;
	money = firm.getMoneyOfFirm();
	cout << "\n\t �������� ������� �����:  " << money;
	if (firm.getResultGame()) { cout << "\n\t ���� �����������!���������� ������!!! \n"; return; }//��������  ���� �� ��� ������!
	money -= win;
	money -= lose;
	firm.setMoneyOfFirm(money);
	cout << "\n\t ���������������� ������� �����:  " << money;
	firm.setResultGame(true);
}



namespace sortSurname
{
	void sorting(Client client[], int countOfGame)
	{
		cout << "\n\t <<< ��������� �������� �� �������! >>>\n\t";
		Client temp;
		for (int i = 0; i < countOfGame; i++)
			for (int j = i; j < countOfGame; j++)
				if (strcmp(client[i].getFio(), client[j].getFio()) > 0)
				{
					temp = client[i];
					client[i] = client[j];
					client[j] = temp;
				}
	}
}

namespace sortMoney
{
	void sorting(Client client[], int countOfGame)
	{
		cout << "\n\t >>> ��������� �������� �� ������! <<<\n\t";
		Client temp;
		for (int i = 0; i < countOfGame; i++)
			for (int j = i; j < countOfGame; j++)
				if (client[i].getBill() > client[j].getBill())
				{
					temp = client[i];
					client[i] = client[j];
					client[j] = temp;
				}
	}
}
