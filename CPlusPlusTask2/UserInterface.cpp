#include "UserInterface.h"

ostream& operator<<(std::ostream& os, BankScore& score) {
    os << "���� �����: " << score.own_bank->name << ", �� �����: " << score.show_money() << '\n';
    return os;
}

ostream& operator<<(std::ostream& os, Score& score)
{
    os << "����: " << score.get_score_numver() << ", ����������� ����� " << score.own_bank->name << ", ����������� ������� " << score.own_bank->get_client_by_score_number(score.get_score_numver())->getDesignation() << "\n";
    os << "�� �����: " << score.show_money();
    return os;
}

ostream& operator<<(std::ostream& os, Client& client)
{
    os << "������: " << client.getDesignation() << "\n";
    os << "��� ����: ";
    os << client.bank->get_score_number(&client);
    return os;
}

ostream& operator<<(std::ostream& os, Physical�lient& client)
{
    os << "������: " << client.getDesignation() << "\n";
    os << "��� ����: ";
    os << client.bank->get_score_number(&client);
    return os;
}

ostream& operator<<(std::ostream& os, Legal�lient& client)
{
    os << "������: " << client.getDesignation() << "\n";
    os << "��� ����: ";
    os << client.bank->get_score_number(&client);
    return os;
}

ostream& operator<<(std::ostream& os, Bank& bank) {
    os << "����: " << bank.name << '\n';
    BankScore* score = bank.getBankScore();
    os << score;
    auto users = bank.getCliendAndScore();
    for (auto row : users)
    {
        os << row.first << " : " << row.second;
    }
    return os;
}

void UserInterface::showAllBanks()
{
    for (Bank* bank : this->banks)
        cout << *bank << "\n";
}

void UserInterface::addBank()
{
    Bank* bank;
    std::string name = "";
    cout << "������� �������� �����: ";
    name = getValue<string>();
    cout << "������� ���������� �����: ";
    int money;
    money = getValue<int>();;
    cout << "������� ��������: ";
    double commission;
    commission = getValue<double>();
    bank = new Bank(name, money, commission);
    banks.push_back(bank);
}

void UserInterface::addPhysicalClient()
{
    Physical�lient* physicalClient;
    cout << "������� ��� ������������";
    string firstname = getValue<string>();
    cout << "������� ������� ������������";
    string lastname = getValue<string>();
    physicalClient = new Physical�lient(firstname, lastname);
    this->clients.push_back(physicalClient);
}

void UserInterface::addLegalClient()
{
    string namecompany;
    cout << "������� �������� ��������: ";
    cin >> namecompany;
    Legal�lient* legalClient = new Legal�lient(namecompany);
    this->clients.push_back(legalClient);
}

void UserInterface::startMenu()
{
    bool flag = true;
    while (flag) {
        cout << "������� � ������: 1\n������� � ��������: 2\n�����: 0\n";
        int command = getValue<int>();
        switch (command)
        {
        case 1:
            startMenuBank();
            break;
        case 2:
            startMenuClient();
            break;
        case 0:
            flag = false;
            break;
        default:
            break;
        }
    }
}

void UserInterface::startMenuBank()
{
    bool flag = true;
    while (flag) {
        cout << "�������� ��������\n������� ����: 1\n�������� ������� � ����: 2\n���������� ������ � �����: 3\n�����: 0\n";
        int command = getValue<int>();
        switch (command)
        {
        case 1:
            addBank();
            break;
        case 2:
            addClientToBank();
            break;
        case 3:
            setMoneyToBank();
            break;
        case 0:
            flag = false;
            break;
        default:
            break;
        }
    }
}

void UserInterface::addClientToBank()
{
    int key;
    cout << "������� �������� �����: ";
    string bankname = "";
    cin >> bankname;
    cout << "���� ������ ����������: 1, ���� �������: 2: ";
    cout << "����� �����, ������� 0";
    key = getValue<int>();
    switch (key)
    {
    case 1:
    {
        cout << "������� ���: ";
        string firstname = getValue<string>();
        cout << "������� ���: ";
        string secondname = getValue<string>();
        Bank* bank = getBank(bankname);
        Physical�lient* pc = getPhysicalClient(firstname, secondname);
        bank->addClient(pc);
        break; 
    }
    case 2:
    {
        cout << "������� �������� ��������: ";
        string firstname = getValue<string>();
        Bank* bank = getBank(bankname);
        Legal�lient* lc = getLegalClient(firstname);
        bank->addClient(lc);
        break; 
    }
    case 0:
        return;
        break;
    default:
        break;
    }
}

void UserInterface::startMenuClient()
{

}

void UserInterface::setMoneyToBank()
{
    cout << "������� �������� �����: ";
    string name = getValue<string>();
    cout << "������� �����: ";
    int money = getValue<int>();
    Bank* bank = getBank(name);
    bank->getBankScore()->set_money(money);
}

void UserInterface::setMoneyToClient()
{
    int key = -1;
    cout << "1 - ���������� ������, 2 - ����������� ������: ";
    while (key != 1 && key != 2)
        key = getValue<int>();
    if (key == 1)
    {
        cout << "������� ���: ";
        string firstname = getValue<string>();
        cout << "������� �������: ";
        string secondname = getValue<string>();
        Physical�lient* pc = getPhysicalClient(firstname, secondname);
        cout << "������� ���������� �����: ";
        int money = getValue<int>();
        pc->putMoney(money);
    }
    else if (key == 2)
    {
        cout << "������� �������� ��������: ";
        string name = getValue<string>();
        Legal�lient* pc = getLegalClient(name);
        cout << "������� ���������� �����: ";
        int money = getValue<int>();
        pc->putMoney(money);
    }
}

void UserInterface::getMoneyFromClient()
{
    int key = -1;
    cout << "1 - ���������� ������, 2 - ����������� ������: ";
    while (key != 1 && key != 2)
        key = getValue<int>();
    if (key == 1)
    {
        cout << "������� ���: ";
        string firstname = getValue<string>();
        cout << "������� �������: ";
        string secondname = getValue<string>();
        Physical�lient* pc = getPhysicalClient(firstname, secondname);
        cout << "������� ���������� �����: ";
        int money = getValue<int>();
        pc->getMoney(money);
    }
    else if (key == 2)
    {
        cout << "������� �������� ��������: ";
        string name = getValue<string>();
        Legal�lient* pc = getLegalClient(name);
        cout << "������� ���������� �����: ";
        int money = getValue<int>();
        pc->getMoney(money);
    }
}
