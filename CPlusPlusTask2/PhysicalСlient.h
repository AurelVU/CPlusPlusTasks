#pragma once
#include "Client.h"
#include <string>
class Physical—lient : public Client
{
public:
	void putMoney(int money);
	std::string firstName;
	std::string secondName;
	Physical—lient();
	Physical—lient(std::string firstName, std::string secondName);
};

