#pragma once
#include "Client.h"
#include <string>

using namespace std;

class Physical—lient : public Client
{
public:
	void putMoney(int money);
	string firstName;
	string secondName;
	Physical—lient();
	string getDesignation();
	Physical—lient(std::string firstName, std::string secondName);
	void putMoney(int money) override;
	void getMoney(int money) override;
	int showMoney() override;
	string getDesignation() override;
	void transferMoney(int score_number, int money) override;
};

