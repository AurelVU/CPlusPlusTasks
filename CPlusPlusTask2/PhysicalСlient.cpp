#include "Physical�lient.h"

Physical�lient::Physical�lient()
{
	this->bank = nullptr;
	this->firstName = "";
	this->secondName = "";
}

std::string Physical�lient::getDesignation()
{
	return this->firstName + " " + this->secondName;
}

void Physical�lient::transferMoney(int score_number, int money)
{
	this->bank->transaction(this, score_number, money);
}

Physical�lient::Physical�lient(std::string firstName, std::string secondName)
{
	this->firstName = firstName;
	this->secondName = secondName;
}

void Physical�lient::putMoney(int money)
{
	this->bank->get_score(this)->set_money(money);
}

void Physical�lient::getMoney(int money)
{
	this->bank->get_score(this)->get_money(money);
}

int Physical�lient::showMoney() 
{
	return this->bank->get_score(this)->show_money();
}
void transferMoney(int score_number, int money) {}