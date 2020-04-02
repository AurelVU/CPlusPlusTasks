#include "LegalÑlient.h"

LegalÑlient::LegalÑlient()
{
	this->bank = nullptr;
	this->name_company = "";
}

LegalÑlient::LegalÑlient(std::string name_company)
{
	this->name_company = name_company;
}

std::string LegalÑlient::getDesignation()
{
	return this->name_company;
}

void LegalÑlient::transferMoney(int score_number, int money)
{
	bank->transaction(this, score_number, money);
}

void LegalÑlient::transferMoney(Bank* other_bank, int score_number, int money)
{
	this->bank->transaction_to_other_bank(this, other_bank, score_number, money); //LegalÑlient client_from, Bank bank_to, int score_number, int money
}

void LegalÑlient::putMoney(int money)
{
	this->bank->get_score(this)->set_money(money);
}

void LegalÑlient::getMoney(int money)
{
	this->bank->get_score(this)->get_money(money);
}

int LegalÑlient::showMoney()
{
	return this->bank->get_score(this)->show_money();
}
