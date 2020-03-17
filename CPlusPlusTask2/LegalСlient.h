#pragma once
#include "Client.h"
#include <string.h>
class LegalÑlient : Client
{
public:
	LegalÑlient();
	LegalÑlient(std::string name_company);
	std::string name_company;
	void transferMoney(Bank other_bank, int score_number, int money);
};