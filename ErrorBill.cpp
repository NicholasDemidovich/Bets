#include "ErrorBill.h"

void ErrorBill::showErrorBill(double bet, double money)
{
	cout << "\n\tERROR:���� ������ " << bet << " ������ ������ ������:  " << money << endl;
}
ErrorBill::ErrorBill(double bet, double money) { this->bet = bet; this->money = money; };