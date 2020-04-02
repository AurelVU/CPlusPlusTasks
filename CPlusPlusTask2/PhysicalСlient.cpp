#include "PhysicalÑlient.h"

PhysicalÑlient::PhysicalÑlient()
{
	this->bank = nullptr;
	this->firstName = "";
	this->secondName = "";
}

std::string PhysicalÑlient::getDesignation()
{
	return this->firstName + " " + this->secondName;
}

void PhysicalÑlient::transferMoney(int score_number, int money)
{
	this->bank->transaction(this, score_number, money);
}

PhysicalÑlient::PhysicalÑlient(std::string firstName, std::string secondName)
{
	this->firstName = firstName;
	this->secondName = secondName;
}

void PhysicalÑlient::putMoney(int money)
{
	this->bank->get_score(this)->set_money(money);
}

void PhysicalÑlient::getMoney(int money)
{
	this->bank->get_score(this)->get_money(money);
}

int PhysicalÑlient::showMoney() 
{
	return this->bank->get_score(this)->show_money();
}
void transferMoney(int score_number, int money) {}