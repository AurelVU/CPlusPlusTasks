#pragma once
#include "Client.h"
#include <string>
class Physical—lient : Client
{
public:
	override void putMoney(int money);
	std::string firstName;
	std::string secondName;
	Physical—lient();
	Physical—lient(std::string firstName, std::string secondName);
};

