#pragma once
#include "Bank.h"
class Client
{
public:
	Client(Bank bank);
	Client();
	virtual void putMoney(int money);
	virtual void getMoney(int money);
	virtual int showMoney();
	virtual void transferMoney(int score_number, int money);
	Bank bank;
};

