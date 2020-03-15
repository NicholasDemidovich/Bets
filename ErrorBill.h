#pragma once
#include <iostream>
#include "Client.h"
using namespace std;
#pragma warning(disable:4996)

class ErrorBill
{
	double bet, money;
public:
	void showErrorBill(double bet, double money);
	ErrorBill(double bet, double money);
};

