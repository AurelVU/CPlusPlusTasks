#pragma once
#include "Client.h"
#include <string.h>
class Legal�lient : Client
{
public:
	Legal�lient();
	Legal�lient(std::string name_company);
	std::string name_company;
	void transferMoney(Bank other_bank, int score_number, int money);
};