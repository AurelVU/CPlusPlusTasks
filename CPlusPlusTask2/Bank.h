#pragma once
#include <vector>
#include <string>
#include "Score.h"
#include "Client.h"
class Bank
{
public:
	std::string name;
	void addClient(Client client);
	double commission;
protected:
	std::vector<Score> scores;
	std::vector<Client> users;

};