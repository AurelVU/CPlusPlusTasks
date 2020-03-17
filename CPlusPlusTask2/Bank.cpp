#include "Bank.h"

Bank::Bank()
{
}

Bank::Bank(std::string name)
{
	this->name = name;
}

Bank::Bank(std::string name, int money)
{
	this->name = name;
	this->score = BankScore(money);
}

Bank::Bank(std::string name, int money, double commission)
{
	this->name = name;
	this->score = BankScore(money);
	this->commission = commission;
}

Score Bank::addClient(Client client)
{
	Score score(*this, this->users_scores.size());
	users_scores[client] = score;
	client.bank = *this;
	return score;
}

int Bank::get_score_number(Client client)
{
	this->users_scores[client];
}

void Bank::transaction(Client client_from, int score_number, int money)
{
	Score score_from = this->users_scores[client_from];
	Score score_to;
	score_from.get_money(money * (1 + this->commission));
	this->score.set_money(money * this->commission);
	score_to.set_money(money);
}

void Bank::transaction(Legal—lient client_from, Bank bank_to, int score_number, int money)
{
	Score score_from = users_scores[client_from];
	bank_to.get_other_bank_transaction(client_from, *this, score_number, money);
}
