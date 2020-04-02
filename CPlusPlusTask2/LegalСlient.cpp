#include "Legal�lient.h"

Legal�lient::Legal�lient()
{
	this->bank = nullptr;
	this->name_company = "";
}

Legal�lient::Legal�lient(std::string name_company)
{
	this->name_company = name_company;
}

std::string Legal�lient::getDesignation()
{
	return this->name_company;
}

void Legal�lient::transferMoney(int score_number, int money)
{
	bank->transaction(this, score_number, money);
}

void Legal�lient::transferMoney(Bank* other_bank, int score_number, int money)
{
	this->bank->transaction_to_other_bank(this, other_bank, score_number, money); //Legal�lient client_from, Bank bank_to, int score_number, int money
}

void Legal�lient::putMoney(int money)
{
	this->bank->get_score(this)->set_money(money);
}

void Legal�lient::getMoney(int money)
{
	this->bank->get_score(this)->get_money(money);
}

int Legal�lient::showMoney()
{
	return this->bank->get_score(this)->show_money();
}
