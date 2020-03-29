#pragma once
#include "Bank.h"

class Score
{
public:
	Score(Bank* bank, int number);
	Score();
	void set_money(int money);
	void get_money(int money);
	int show_money();
	int get_score_numver();
	Bank* own_bank;
protected:
	int money;
	int _number;
};

