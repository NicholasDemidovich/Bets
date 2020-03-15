#include "Firm.h"

	void Firm::setIdFirm(int idF) { idFirm = idF; }
	int Firm::getIdFirm() { return idFirm; }

	void Firm::setNameOfFirm(char* f) { strcpy_s(nameOfFirm, f); }
	char* Firm::getNameOfFirm() { return nameOfFirm; }

	void Firm::setAddress(char* f) { strcpy_s(address, f); }
	char* Firm::getAddress() { return address; }

	void Firm::setNumberOfPhone(char* f) { strcpy_s(numberOfPhone, f); }
	char* Firm::getNumberOfPhone() { return numberOfPhone; }

	void Firm::setResultGame(bool fl) { resultGame = fl; }
	bool Firm::getResultGame() { return resultGame; }

	void Firm::Print()
	{
		cout << "\n\t Name of firm " << nameOfFirm << " Id firm:   "
			<< idFirm << "  Address:  " << address << " Number of phone " << numberOfPhone << endl;
	}
	void Firm::setMoneyOfFirm(double money) { moneyOfFirm = money; }
	double Firm::getMoneyOfFirm() { return moneyOfFirm; }
	void Firm::AddMoney(double money) { moneyOfFirm += money; }
	void Firm::SubMoney(double money) { moneyOfFirm -= money; }

