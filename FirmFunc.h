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
	cout << "\n\t ~~~ ������� ����� ~~~\n";
	cout << "\n\t ������� ����������������� ����� �����: ";
	cin >> id;
	obj.setIdFirm(id);
	cout << "\n\t ������� �������� �����: ";
	cin >> firmName;
	obj.setNameOfFirm(firmName);
	cout << "\n\t ������� ����� �����: ";
	cin >> address;
	obj.setAddress(address);
	cout << "\n\t ������� ���������� ����� �����: ";
	cin >> phoneNumber;
	obj.setNumberOfPhone(phoneNumber);
	while (true)
	{
		try {
			cout << "\n\t ������� ������ �����: ";
			cin >> moneyFirm;
			if (moneyFirm < 10000)throw  1.5;
			obj.setMoneyOfFirm(moneyFirm);
			break;
		}
		catch (double) { cout << "\n\t ������ ����� ������ ���� > 10000: "; continue; }
	}

}

void show_firm(Firm obj)
{
	cout << "\n\t ���������� � ����� \n";
	cout << "\n\t ����������������� ����� �����: " << obj.getIdFirm() << "  �������� �����:  " << obj.getNameOfFirm()
		<< "\n\t ����� �����:  " << obj.getAddress() << "  ���������� ����� �����: " << obj.getNumberOfPhone()
		<< "\n\t ������ �����:  " << obj.getMoneyOfFirm() << endl;
}

