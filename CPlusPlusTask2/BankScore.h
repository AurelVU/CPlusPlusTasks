#pragma once
#include "Bank.h"
class BankScore
{
public:
	BankScore(Bank bank)
	{
		own_bank = bank;
		money = 0;
	}
	BankScore(int money);
	BankScore();
	void set_money(int money);
	void get_money(int money);
	int show_money();
	Bank own_bank;
protected:
	int money;
};

