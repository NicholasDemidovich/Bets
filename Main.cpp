#include "stdio.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <typeinfo>
#include "Abstr.h"
#include "Firm.h"
#include "Game.h"
#include "Client.h"
#include "ErrorBill.h"
#include "Verification.h"
#include "ClientFunc.h"
#include "FirmFunc.h"
#include "GameFunc.h"
#include "WorkWithFile.h"
using namespace std;



void main()
{
	setlocale(LC_ALL, "Russian");
	file_admin();
	system("cls");
	bool  flag_admin = false;
	bool flag_firm = false;
	bool flag_game = false;
	bool flag_client = false;
	bool flag_NewDay = false;
	Firm firm;
	int factCountOfGame = 0, factCountOfClient = 0;
	int const countOfGame = 20, countOfClient = 100;
	Game game[countOfGame];
	Client client[countOfClient];
	int sw;
	while (true)
	{
		cout << "\n\t***Пожалуйста,выберите: 1- админ,  2- клиент,  0-выход: ";
		cin >> sw;
		fflush(stdin);
		switch (sw)
		{
		case 0:	return;
		case 2:
			system("cls");
			while (true)
			{
				system("cls");
				cout << endl;
				cout << "\n\t\t @@@ МЕНЮ КЛИЕНТА @@@\n";
				sw = show_menu_klient();
				if (sw == 0) break;
				switch (sw)
				{
				case 1:system("cls"); show_Client(client, factCountOfClient); system("pause");   break;
				case 2:system("cls"); add_Bet(firm,client, factCountOfClient); system("pause");    break;
				case 3:system("cls"); correct_Bet(client, factCountOfClient);  break;
				case 4:system("cls"); show_ResultOfBet(client, factCountOfClient); system("pause"); break;
				case 5:system("cls"); show_Game(game, factCountOfGame); system("pause"); break;
				default:
					cout << "\t\t Wrong case. Try again.\n";      break;
				}
			}	 break;

		case 1:
			system("cls");
			if (flag_admin == false)
			{
				if (check_admin_login() == false || check_admin_password() == false)
				{
					cout << "вы не админ"; return;
				}
				else flag_admin = true;
			}
			while (true)
			{
				system("cls");
				cout << endl;
				cout << "\n\t\t @@@ МЕНЮ АМИНИСТРАТОРА @@@\n";
				sw = show_menu_admin();
				if (sw == 0) break;
				switch (sw)
				{
				case 1:system("cls"); create_Firm(firm); flag_firm = true; break;
				case 2:system("cls"); if (flag_firm) show_firm(firm);
					  else cout << "\n\t Фирма не создана!!!\n";
					system("pause");
					break;
				case 3:system("cls"); if (flag_firm) { add_Game(game, countOfGame, &factCountOfGame); flag_game = true; }
					  else cout << "\n\t Фирма не создана!!!\n";
					break;
				case 4:system("cls"); if (flag_firm && flag_game)change_Game(game, factCountOfGame);
					  else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 5:system("cls"); if (flag_firm && flag_game)delete_Game(game, &factCountOfGame);
					  else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 6:system("cls"); if (flag_firm && flag_game) show_Game(game, factCountOfGame);
					   else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 7:system("cls"); if (flag_firm && flag_game) { add_Client(client, countOfClient, &factCountOfClient); flag_client = true; }
					  else cout << "\n\t Фирма или игра не создана!!!\n";
					break;
				case 8:system("cls"); if (flag_firm && flag_game && flag_client) show_Clients(client, factCountOfClient);
					  else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 9:system("cls"); if (flag_firm && flag_game && flag_client) delete_Client(client, &factCountOfClient);
					  else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 10:system("cls"); if (flag_firm && flag_game && flag_client) change_Client(client, factCountOfClient);
					  else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 11:system("cls"); if (flag_firm && flag_game && flag_client) winOrLose_Client(client, factCountOfClient, game, factCountOfGame);
					   else cout << "\n\t Фирма или игра не создана!!!\n";
					break;
				case 12:system("cls"); if (flag_firm && flag_game ) sorting(game, factCountOfGame);
					   else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 13:system("cls"); if (flag_firm && flag_game ) sorting(factCountOfGame, game);
					   else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 14:system("cls"); if (flag_firm && flag_game && flag_client) sortSurname::sorting(client, factCountOfClient);
					   else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 15:system("cls"); if (flag_firm && flag_game && flag_client) sortMoney::sorting(client, factCountOfClient);
					   else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 16:system("cls"); if (flag_firm && flag_game && flag_client)resultOfGame(firm, client, factCountOfClient);
					   else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 17:
					system("cls");
					if (flag_firm && flag_game && flag_client)
					{
						saveFilesAll(firm, game, factCountOfGame, client, factCountOfClient);
						flag_NewDay = true;
					}
					else cout << "\n\t Фирма или игра не создана!!!\n";
					system("pause");
					break;
				case 18:
					system("cls");
					if (!flag_NewDay)
					{
						cout << "\n\t New day!!!" << endl;
						flag_admin = true;
						flag_firm = true;
						flag_game = true;
						flag_client = true;
						flag_NewDay = true;
						loadFilesAll(firm, game, client, &factCountOfGame, &factCountOfClient);
					}
					else
						if (flag_firm && flag_game && flag_client)
							loadFilesAll(firm, game, client, &factCountOfGame, &factCountOfClient);
					system("pause");
					break;
				default:
					cout << "\t\t  Wrong case. Try again.\n";  break;
				}
			} 	break;
		default:
			cout << "\t\t  Wrong case. Try again.\n";   break;
		}
	}

}


