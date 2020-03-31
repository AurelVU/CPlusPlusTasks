#pragma once
#include <vector>
#include <string>
#include <map>
#include "Score.h"
#include "Client.h"
#include "BankScore.h"

class BankScore;
class Client;
class LegalClient;
class Score;

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
	Score* get_score(Client* client);
	Client* get_client_by_score_number(int score_number);
	void transaction(Client* client_from, int score_number, int money);
	void transaction_to_other_bank(Client* client_from, Bank* bank_to, int score_number, int money);
	void get_other_bank_transaction(Client* client_from, Bank* bank_from, int score_number, int money);
	std::map<Client*, Score*> getCliendAndScore();
	BankScore* getBankScore();
protected:
	std::map<Client*, Score*> users_scores;
	Score* getScoreByNymber(int number);
	BankScore* score;
};