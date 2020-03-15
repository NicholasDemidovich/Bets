#pragma once

#include <iostream>
#include <conio.h>
#include "Firm.h"
#include "ErrorBill.h"
using namespace std;
#pragma warning(disable:4996)

void create_Firm(Firm& obj)
{
	int id;
	char firmName[20];
	char address[20];
	char phoneNumber[20];
	double moneyFirm;
	cout << "\n\t ~~~ Создаем фирму ~~~\n";
	cout << "\n\t Введите идентификационный номер фирмы: ";
	cin >> id;
	obj.setIdFirm(id);
	cout << "\n\t Введите название фирмы: ";
	cin >> firmName;
	obj.setNameOfFirm(firmName);
	cout << "\n\t Введите адрес фирмы: ";
	cin >> address;
	obj.setAddress(address);
	cout << "\n\t Введите контактный номер фирмы: ";
	cin >> phoneNumber;
	obj.setNumberOfPhone(phoneNumber);
	while (true)
	{
		try {
			cout << "\n\t Введите бюджет фирмы: ";
			cin >> moneyFirm;
			if (moneyFirm < 10000)throw  1.5;
			obj.setMoneyOfFirm(moneyFirm);
			break;
		}
		catch (double) { cout << "\n\t Бюджет фирмы должен быть > 10000: "; continue; }
	}

}

void show_firm(Firm obj)
{
	cout << "\n\t Информация о фирме \n";
	cout << "\n\t Идентификационный номер фирмы: " << obj.getIdFirm() << "  Название фирмы:  " << obj.getNameOfFirm()
		<< "\n\t Адрес фирмы:  " << obj.getAddress() << "  Контактный номер фирмы: " << obj.getNumberOfPhone()
		<< "\n\t Бюджет фирмы:  " << obj.getMoneyOfFirm() << endl;
}

