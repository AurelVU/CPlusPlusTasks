#pragma once
#include "Bank.h"
class Client
{
public:
	Client(Bank* bank);
	Client();
	virtual void putMoney(int money) = 0;
	virtual void getMoney(int money) = 0;
	virtual int showMoney() = 0;
	virtual void transferMoney(int score_number, int money) = 0;
	Bank* bank;
};

