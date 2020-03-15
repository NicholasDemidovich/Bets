#pragma once
#include <iostream>
#include <conio.h>
#include "Client.h"
#include "ErrorBill.h"
#include "fstream"
using namespace std;


void saveFirm(Firm firm, int  countGame, int countClient)
{
	int len = sizeof(firm);
	fstream out;
	out.open("Firm.dat", ios::out | ios::binary);
	if (!out)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: Firm \n"; return;
	}
	out.write((char*)&firm, len);
	out.write((char*)&countGame, sizeof(int));
	out.write((char*)&countClient, sizeof(int));
	out.close();
}

void saveGames(Game game, int countGame)
{
	fstream out;
	out.open("Game.dat", ios::out | ios::binary);
	if (!out)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: Game \n"; return;
	}
	int len = sizeof(game);
	out.write((char*)&game, len);
	out.close();
}

void saveClients(Client client, int countClient)
{
	fstream out;
	out.open("Client.dat", ios::out | ios::binary);
	if (!out)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: Client \n"; return;
	}
	int len = sizeof(client);
	out.write((char*)&client, len);
	out.close();
}

void saveFilesAll(Firm firm, Game game[], int countGame, Client client[], int countClient)
{
	saveFirm(firm, countGame, countClient);
	for (int i = 0; i < countGame; i++)
	{
		saveGames(game[i], countGame);
	}
	for (int i = 0; i < countClient; i++)
	{
		saveClients(client[i], countClient);
	}
	cout << "\n\t\t  SAVE: write file.\n";
}

void loadFirm(Firm& firm, int* countGame, int* countClient)
{
	int len = sizeof(Firm);
	fstream in;
	in.open("Firm.dat", ios::in);
	if (!in) { cerr << "\n\t\t  Load - Couldn't open file: Firm \n"; return; }
	in.read((char*)&firm, len);
	in.read((char*)countGame, sizeof(int));
	in.read((char*)countClient, sizeof(int));
	in.close();

}

void loadGame(Game& game)
{
	int len = sizeof(Game);
	fstream in;
	in.open("Game.dat", ios::in);
	if (!in) { cerr << "\n\t\t  Load - Couldn't open file: Game \n"; return; }
	in.read((char*)&game, len);
	in.close();
}

void loadClient(Client& client)
{
	int len = sizeof(client);
	fstream in;
	in.open("Client.dat", ios::in);
	if (!in) { cerr << "\n\t\t  Load - Couldn't open file: Client \n"; return; }
	in.read((char*)&client, len);
	in.close();
}

void loadFilesAll(Firm& firm, Game game[], Client client[], int* countGame, int* countClient)
{
	loadFirm(firm, countGame, countClient);
	for (int i = 0; i < *countGame; i++)
	{
		loadGame(game[i]);
	}
	for (int i = 0; i < *countClient; i++)
	{
		loadClient(client[i]);
	}
	cout << "\n\t\t LOAD--fclose! \n";
}

