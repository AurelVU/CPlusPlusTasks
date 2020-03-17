#include "LegalÑlient.h"

LegalÑlient::LegalÑlient()
{
}

LegalÑlient::LegalÑlient(std::string name_company)
{
	this->name_company = name_company;
}

void LegalÑlient::transferMoney(Bank other_bank, int score_number, int money)
{
	this->bank.transaction(this, other_bank, score_number, money); //LegalÑlient client_from, Bank bank_to, int score_number, int money
}
