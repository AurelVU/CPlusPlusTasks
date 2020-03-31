#pragma once
#include <iostream>
#include "Bank.h"
#include "BankScore.h"
#include "Client.h"
#include "LegalСlient.h"
#include "PhysicalСlient.h"
#include "Score.h"
#include <vector>

using namespace std;

class UserInterface
{
public:
	void showAllBanks();
	void addBank();
	void addPhysicalClient();
	void addLegalClient();
	void startMenu();
	void startMenuBank();
	void addClientToBank();
	void startMenuClient();
	void setMoneyToBank();
	void setMoneyToClient();
	void getMoneyFromClient();
	void makeTransaction();
private:
	template <typename T>
	T getValue();
	Bank* getBank(string name);
	PhysicalСlient* getPhysicalClient(string firstname, string secondname);
	LegalСlient* getLegalClient(string name);
	vector<Bank*> banks;
	vector<Client*> clients;
};

template<typename T>
inline T UserInterface::getValue()
{
	T value;

	while (!(cin >> value))
	{
		cout << "Неверный формат Ввода. Повторите ввод\n";
		cin.clear();                                        //сбрасываем ошибку
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удаляем все из буфера до перевода строки
		cout << "Введите значение: ";
	}

	return value;
}
