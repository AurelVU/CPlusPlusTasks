#include "UserInterface.h"

ostream& operator<<(std::ostream& os, BankScore& score) {
    os << "Счет банка: " << score.own_bank->name << ", на счету: " << score.show_money() << '\n';
    return os;
}

ostream& operator<<(std::ostream& os, Score& score)
{
    os << "Счет: " << score.get_score_numver() << ", принадлежит банку " << score.own_bank->name << ", принадлежит клиенту " << score.own_bank->get_client_by_score_number(score.get_score_numver())->getDesignation() << "\n";
    os << "На счету: " << score.show_money();
    return os;
}

ostream& operator<<(std::ostream& os, Client& client)
{
    os << "Клиент: " << client.getDesignation() << "\n";
    os << "Его счет: ";
    os << client.bank->get_score_number(&client);
    return os;
}

ostream& operator<<(std::ostream& os, PhysicalСlient& client)
{
    os << "Клиент: " << client.getDesignation() << "\n";
    os << "Его счет: ";
    os << client.bank->get_score_number(&client);
    return os;
}

ostream& operator<<(std::ostream& os, LegalСlient& client)
{
    os << "Клиент: " << client.getDesignation() << "\n";
    os << "Его счет: ";
    os << client.bank->get_score_number(&client);
    return os;
}

ostream& operator<<(std::ostream& os, Bank& bank) {
    os << "Банк: " << bank.name << '\n';
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
    cout << "Введите название банка: ";
    name = getValue<string>();
    cout << "Введите количество денег: ";
    int money;
    money = getValue<int>();;
    cout << "Введите комиссию: ";
    double commission;
    commission = getValue<double>();
    bank = new Bank(name, money, commission);
    banks.push_back(bank);
}

void UserInterface::addPhysicalClient()
{
    PhysicalСlient* physicalClient;
    cout << "Введите имя пользователя";
    string firstname = getValue<string>();
    cout << "Введите фамилию пользователя";
    string lastname = getValue<string>();
    physicalClient = new PhysicalСlient(firstname, lastname);
    this->clients.push_back(physicalClient);
}

void UserInterface::addLegalClient()
{
    string namecompany;
    cout << "Введите название компании: ";
    cin >> namecompany;
    LegalСlient* legalClient = new LegalСlient(namecompany);
    this->clients.push_back(legalClient);
}

void UserInterface::startMenu()
{
    bool flag = true;
    while (flag) {
        cout << "Перейти к банкам: 1\nПерейти к клиентам: 2\nВыход: 0\n";
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
        cout << "Выберите действие\nСоздать банк: 1\nДобавить клиента в банк: 2\nУстановить деньги в банке: 3\nВыход: 0\n";
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
    cout << "Введите название банка: ";
    string bankname = "";
    cin >> bankname;
    cout << "Если клиент физический: 1, если частный: 2: ";
    cout << "Чтобы выйти, введите 0";
    key = getValue<int>();
    switch (key)
    {
    case 1:
    {
        cout << "Введите имя: ";
        string firstname = getValue<string>();
        cout << "Введите имя: ";
        string secondname = getValue<string>();
        Bank* bank = getBank(bankname);
        PhysicalСlient* pc = getPhysicalClient(firstname, secondname);
        bank->addClient(pc);
        break; 
    }
    case 2:
    {
        cout << "Введите название компании: ";
        string firstname = getValue<string>();
        Bank* bank = getBank(bankname);
        LegalСlient* lc = getLegalClient(firstname);
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
    cout << "Введите название банка: ";
    string name = getValue<string>();
    cout << "Введите сумму: ";
    int money = getValue<int>();
    Bank* bank = getBank(name);
    bank->getBankScore()->set_money(money);
}

void UserInterface::setMoneyToClient()
{
    int key = -1;
    cout << "1 - Физический клиент, 2 - Юридический клиент: ";
    while (key != 1 && key != 2)
        key = getValue<int>();
    if (key == 1)
    {
        cout << "Введите имя: ";
        string firstname = getValue<string>();
        cout << "Введите фамилию: ";
        string secondname = getValue<string>();
        PhysicalСlient* pc = getPhysicalClient(firstname, secondname);
        cout << "Введите количетсво денег: ";
        int money = getValue<int>();
        pc->putMoney(money);
    }
    else if (key == 2)
    {
        cout << "Введите название компании: ";
        string name = getValue<string>();
        LegalСlient* pc = getLegalClient(name);
        cout << "Введите количетсво денег: ";
        int money = getValue<int>();
        pc->putMoney(money);
    }
}

void UserInterface::getMoneyFromClient()
{
    int key = -1;
    cout << "1 - Физический клиент, 2 - Юридический клиент: ";
    while (key != 1 && key != 2)
        key = getValue<int>();
    if (key == 1)
    {
        cout << "Введите имя: ";
        string firstname = getValue<string>();
        cout << "Введите фамилию: ";
        string secondname = getValue<string>();
        PhysicalСlient* pc = getPhysicalClient(firstname, secondname);
        cout << "Введите количетсво денег: ";
        int money = getValue<int>();
        pc->getMoney(money);
    }
    else if (key == 2)
    {
        cout << "Введите название компании: ";
        string name = getValue<string>();
        LegalСlient* pc = getLegalClient(name);
        cout << "Введите количетсво денег: ";
        int money = getValue<int>();
        pc->getMoney(money);
    }
}
