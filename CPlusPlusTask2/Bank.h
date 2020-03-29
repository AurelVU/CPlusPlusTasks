#pragma once
#include <vector>
#include <string>
#include <map>
#include "Score.h"
#include "Client.h"
#include "Legal—lient.h"
#include "BankScore.h"
class Bank
{
public:
	Bank();
	Bank(std::string name);
	Bank(std::string name, int money);
	Bank(std::string name, int money, double commission);
	std::string name;
	Score* addClient(Client* client);
	double commission;
	int get_score_number(Client* client);
	void transaction(Client* client_from, int score_number, int money);
	void transaction(Legal—lient* client_from, Bank* bank_to, int score_number, int money);
	void get_other_bank_transaction(Legal—lient* client_from, Bank* bank_from, int score_number, int money);
protected:
	std::map<Client*, Score*> users_scores;
	Score* getScoreByNymber(int number);
	BankScore score;
};