#pragma once
#include "Score.h"

class Client
{
public:
	Client(Score _score) 
	{ 
		score = _score; 
	}
	virtual void putMoney();
	virtual void getMoney();
	virtual void showMoney();
	virtual void transferMoney();
	Score score;
};

