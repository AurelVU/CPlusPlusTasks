#pragma once
#include "Client.h"
#include <string.h>

using namespace std;

class Legal—lient : public Client
{
public:
	Legal—lient();
	Legal—lient(std::string name_company);
	string name_company;

	void putMoney(int money) ;
	void getMoney(int money) ;
	int showMoney() ;
	string getDesignation() ;
	void transferMoney(int score_number, int money) ;
	void transferMoney(Bank* other_bank, int score_number, int money);
};