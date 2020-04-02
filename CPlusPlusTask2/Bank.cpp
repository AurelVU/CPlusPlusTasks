#include "Bank.h"

Bank::Bank()
{
	this->score = new BankScore(this);
}

Bank::Bank(std::string name)
{
	this->name = name;
	this->score = new BankScore(this);
}

Bank::Bank(std::string name, int money)
{
	this->name = name;
	this->score = new BankScore(money);
	this->score->own_bank = this;
}

Bank::Bank(std::string name, int money, double commission)
{
	this->name = name;
	this->score = new BankScore(money);
	this->score->own_bank = this;
	this->commission = commission;
}

Score* Bank::addClient(Client* client)
{
	Score* score = new Score(this, this->users_scores.size());
	users_scores[client] = score;
	client->bank = this;
	return score;
}

int Bank::get_score_number(Client* client)
{
	return this->users_scores[client]->get_score_numver();
}

Score* Bank::get_score(Client* client)
{
	return this->users_scores[client];
}

Client* Bank::get_client_by_score_number(int number)
{
	for (auto row : this->users_scores)
		if (row.second->get_score_numver() == number)
			return row.first;
	return nullptr;
}

void Bank::transaction(Client* client_from, int score_number, int money)
{
	Score* score_from = this->users_scores[client_from];
	Score score_to;
	score_from->get_money(money * (1 + this->commission));
	this->score->set_money(money * this->commission);
	score_to.set_money(money);
}

void Bank::transaction_to_other_bank(Client* client_from, Bank* bank_to, int score_number, int money)
{
	Score* score_from = users_scores[(Client*)client_from];
	bank_to->get_other_bank_transaction(client_from, this, score_number, money);
}

void Bank::get_other_bank_transaction(Client* client_from, Bank* bank_from, int score_number, int money)
{
	Score* score = getScoreByNymber(score_number);
	score->set_money(money);
}

std::map<Client*, Score*> Bank::getCliendAndScore()
{
	return this->users_scores;
}

BankScore* Bank::getBankScore()
{
	return this->score;
}

Score* Bank::getScoreByNymber(int number)
{
	for (auto I : users_scores)
	{
		Score* i = I.second;
		if (i->get_score_numver() == number)
			return i;
	}
	return nullptr;
}