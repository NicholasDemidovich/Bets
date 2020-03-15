#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
#pragma warning(disable:4996)



char* input_password()
{
	int index = 0;
	char c;
	char* password = new char[81];
	while (true)
	{  	
		c = _getch();
		cout << "*";
		if (c == '\r') break;
		if (c != 8)
		{
			password[index] = c;
			index++;
		}
	}
	password[index] = '\0';
	return password;
}

void file_admin()
{
	cout << "\n\t\t  СОЗДАНИЕ ФАЙЛА АДМИНИСТРАТОРА ";
	const char* login, * password;
	login = new char[81];
	password = new char[81];
	char password_new[81];
	login = "Nicholas";
	password = "12345678";

	unsigned char maska;
	char* str_maska = new char[1];
	cout << "\n\t  Введите маску администратора: ";
	str_maska = input_password();
	sscanf(str_maska, "%b", &maska);
	fflush(stdin);

	for (int i = 0; i < strlen(password); i++)
		password_new[i] = password[i] + (i + 1) + 7 ^ maska;
	password_new[strlen(password)] = '\0';
	FILE* admin_file = fopen("admin_file.txt", "w");
	fprintf(admin_file, "%s %s\n", login, password_new);
	fclose(admin_file);
}

bool check_admin_login()
{
	FILE* admin_file = fopen("admin_file.txt", "r");
	char* admin_login = new char[81];
	if (!admin_file)
	{
		cout << "\t  Ошибка открытия файла!\n";
		return  false;
	}
	fscanf(admin_file, "%s", admin_login);

	int input_counter = 0;
	char* checking = new char[81];
	while (input_counter < 3)
	{
		cout << "\t Введите логин администратора:  ";
		fflush(stdin);
		cin >> checking;
		if (strcmp(checking, admin_login) == 0)
		{
			fclose(admin_file);
			return true;
		}
		input_counter++;
		cout << "\t логин:" << checking;
		cout << "\t\t  Неверный ввод логина!";
	}
	cout << "\t  три попытки использовано , ошибка ввода логина!";
	fclose(admin_file);
	return false;
}


bool check_admin_password()
{
	FILE* admin_file = fopen("admin_file.txt", "r");
	char* admin_password = new char[81];
	if (!admin_file)
	{
		puts("\t  Ошибка открытия файла!\n");
		return  false;
	}
	fscanf(admin_file, "%s%s", admin_password, admin_password);
	int input_counter = 0;
	char* str_maska = new char[1];
	unsigned char maska;
	cout << "\n\t  Введите маску: ";
	str_maska = input_password();
	sscanf(str_maska, "%b", &maska);
	char* checking = new char[81];
	while (input_counter < 3)
	{
		cout << "\n\t\t Введите пароль администратора:  ";
		fflush(stdin);
		checking = input_password();
		for (int i = 0; i < strlen(checking); i++)
			checking[i] = checking[i] + (i + 1) + 7 ^maska;
		if (strcmp(checking, admin_password) == 0)
		{
			fclose(admin_file);
			return true;
		}
		input_counter++;
		cout << "\n\t\t Неверный ввод пароля!";
	}
	cout << "\t  три попытки использовано , ошибка ввода пароля!";
	fclose(admin_file);
	return false;
}


bool  read_yes_no(const char* quescin)
{
	char ans[7];
	bool  flag = true;
	while (true)
	{
		cout << "\n %s (yes/no)? " << quescin;
		fflush(stdin);
		cin >> ans;
		if (strcmp(ans, "yes") == 0 || strcmp(ans, "YES") == 0 || strcmp(ans, "no") == 0 || strcmp(ans, "NO") == 0)  break;
	}
	if (ans[0] == 'n' || ans[0] == 'N')	flag = false;
	return  flag;
}

void change_login_password(void)
{
	char* login, * password;
	login = new char[81];
	password = new char[81];
	char* password_new;
	password_new = new char[81];

	bool  flag;
	FILE* admin_file = fopen("admin_file.txt", "r");
	if (!admin_file)
	{
		cout << "\t  Ошибка открытия файла администратора!\n";
		return;
	}
	fscanf(admin_file, "%s%s", login, password);
	fclose(admin_file);

	flag = false;
	if (read_yes_no("\nAre you sure that you want to changed admin_login "))
	{
		fflush(stdin);  flag = true;
		cout << "\t\t Введите новый логин администратора:  ";
		cin >> login;
		fflush(stdin);
	}
	if (read_yes_no("\nAre you sure that you want to changed admin_password "))
	{
		flag = true;
		cout << "\t\t Введите новый пароль администратора:  ";
		fflush(stdin);
		password_new = input_password();
		if (flag)
		{
			unsigned char maska;
			char* str_maska = new char[1];;
			cout << "\n\t  Введите маску администратора: ";
			str_maska = input_password();
			sscanf(str_maska, "%b", &maska);
			fflush(stdin);
			for (int i = 0; i < strlen(password_new); i++)
				password[i] = password_new[i] + (i + 1) + 7 ^ maska;
			password[strlen(password_new)] = '\0';
		}
	}
	if (flag)
	{
		FILE* admin_file = fopen("admin_file.txt", "w");
		fprintf(admin_file, "%s %s\n", login, password);
		fclose(admin_file);
	}
}

int show_menu_admin(void)
{
	int c;
	do {
		cout << "\n 0.Переход на верхний уровень \n";
		cout << " 1.Создать фирму.\n";
		cout << " 2.Отобразить фирму.\n";
		cout << " 3.Добавить игру.\n";
		cout << " 4.Поменять параметры игру.\n";
		cout << " 5.Удалить игру.\n";
		cout << " 6.Показать список игр.\n";
		cout << " 7.Добавить клиента.\n";
		cout << " 8.Показать информацию о клиентах.\n";
		cout << " 9.Удалить клиента.\n";
		cout << " 10.Поменять клиента.\n";
		cout << " 11.Проведение игры.\n";
		cout << " 12.Рассортировать игры по названию.\n";
		cout << " 13.Рассортировать игры по ID.\n";
		cout << " 14. Рассортировать клиентов по фамилии.\n";
		cout << " 15. Рассортировать клиентов по вкладу.\n";
		cout << " 16.Отобразить отчет о проведенных играх.\n";
		cout << " 17.Записать результаты выпонения приложения в файлы.\n";
		cout << " 18.Восстановить результаты выпонения приложения из файлов.\n";
		cout << "\t Please, select: ";
		cin >> c;
		fflush(stdin);
	} while (c < 0 || c > 18);
	return c;
}

int show_menu_klient(void)
{
	int c;
	do {
		cout << "\n 0.Переход на верхний уровень \n";
		cout << " 1.Отобразить информацию о клиенте.\n";
		cout << " 2.Добавить ставку.\n";
		cout << " 3.Скорректировать ставку .\n";
		cout << " 4.Отобразить результаты ставки .\n";
		cout << " 5.Показать список игр.\n";
		cout << "\t Please, select: ";
		cin >> c;
		fflush(stdin);
	} while (c < 0 || c > 5);
	return c;
}