#pragma once
#include <iostream>
#include "Bank.h"
#include "BankScore.h"
#include "Client.h"
#include "Legal�lient.h"
#include "Physical�lient.h"
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
	Physical�lient* getPhysicalClient(string firstname, string secondname);
	Legal�lient* getLegalClient(string name);
	vector<Bank*> banks;
	vector<Client*> clients;
};

template<typename T>
inline T UserInterface::getValue()
{
	T value;

	while (!(cin >> value))
	{
		cout << "�������� ������ �����. ��������� ����\n";
		cin.clear();                                        //���������� ������
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //������� ��� �� ������ �� �������� ������
		cout << "������� ��������: ";
	}

	return value;
}
