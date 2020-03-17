#pragma once
#include "Bank.h"

class Score
{
public:
	Score(Bank bank, int number)
	{
		own_bank = bank;
		money = 0;
		_number = number;
	}
	Score()
	{
		money = 0;
		_number = 0;
	}
	void set_money();
	void get_money();
	int show_money();
	int get_score_numver();
	Bank own_bank;
protected:
	int money;
	int _number;
};

