#pragma once
#include <string>
//#include "Bank.h"

using namespace std;

//class Bank;

class Client
{
public:
	Client(Bank* bank);
	Client();
	virtual void putMoney(int money);
	virtual void getMoney(int money);
	virtual int showMoney();
	virtual string getDesignation();
	virtual void transferMoney(int score_number, int money);
	//Bank* bank;
};

