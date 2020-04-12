#include "Score.h"

Score::Score(Bank* bank, int number)
{
	this->own_bank = bank;
	this->_number = number;
}

Score::Score()
{
}

void Score::set_money(int money)
{
	this->money += money;
}

void Score::get_money(int money)
{
	if (this->money < money)
		throw "Недостаточно денег";
	this->money -= money;
}

int Score::show_money()
{
	return this->money;
}

int Score::get_score_numver()
{
	return this->_number;
}
