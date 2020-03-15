#include "Client.h"

void Client::setIdClient(int idC) { idClient = idC; }
int Client::getIdClient() { return idClient; }

void Client::setIdFirm(int idF) { idFirm = idF; }
int Client::getIdFirm() { return idFirm; }

void Client::setIdGame(int idG) { idGame = idG; }
int Client::getIdGame() { return idGame; }

void Client::setAge(int a) { age = a; }
int Client:: getAge() { return age; }

void Client:: setBet(double b) { bet = b; }
double Client::getBet() { return bet; }

void Client::setBill(double b) { bill = b; }
double Client::getBill() { return bill; }

void Client::setFio(char* f) { strcpy_s(fio, f); }
char* Client::getFio() { return fio; }

void Client::setWinOrLose(bool flag) { winOrLose = flag; }
bool Client::getWinOrLose() { return winOrLose; }

void Client::setSummOf() { summOfWin = 0; }

void Client::setSummOfWin(double coif) { summOfWin = bet * coif; }
double Client::getSummOfWin() { return summOfWin; }



Client Client::operator+(Client  obj)         
{
	Client ob;
	double summ = obj.getBill();
	summ += bill;
	ob.setBill(summ);
	return  ob;
}

void Client::printClient()
{
	cout << "\t | Fio: " << fio << " | Id CLient:  " << idClient << " | Id Game:   " << idGame
		<< " | Bill:  " << bill << " | ID Firm:  " << idFirm << " | Bet:  " << bet << " |"<<endl;
}
void Client::Print()
{
	if (winOrLose)
		cout << "\t | Fio: " << fio << " | Id Game:   " << idGame << " | Bet:  " << bet
		<< " | summ of Win " << summOfWin << " |"<< endl;
	else
		cout << "\t | Fio: " << fio << " | Id Game:   " << idGame << " | Bet:  " << bet
		<< " | summ of Lose " << summOfWin << " |" << endl;
}
