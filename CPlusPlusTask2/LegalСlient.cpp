#include "Legal�lient.h"

Legal�lient::Legal�lient()
{
}

Legal�lient::Legal�lient(std::string name_company)
{
	this->name_company = name_company;
}

void Legal�lient::transferMoney(Bank other_bank, int score_number, int money)
{
	this->bank.transaction(this, other_bank, score_number, money); //Legal�lient client_from, Bank bank_to, int score_number, int money
}
