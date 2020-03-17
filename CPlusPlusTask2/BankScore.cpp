#include "BankScore.h"

BankScore::BankScore(int money)
{
	this->money = money;
}

BankScore::BankScore()
{
}

void BankScore::set_money(int money)
{
	this->money += money;
}

void BankScore::get_money(int money)
{
	this->money -= money;
}

int BankScore::show_money()
{
	return this->money;
}
