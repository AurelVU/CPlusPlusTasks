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
    if (client.bank != nullptr) {
        os << "Его счет: ";
        os << client.bank->get_score_number(&client);
    }
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
    BankScore score = *bank.getBankScore();
    os << score;
    auto users = bank.getCliendAndScore();
    for (auto row : users)
    {
        os << *row.first << " : " << *row.second;
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
        cout << "Выберите действие\nСоздать банк: 1\nДобавить клиента в банк: 2\nУстановить деньги в банке: 3\nОтобразить все банки: 4\nВыход: 0\n";
        try
        {
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
            case 4:
                showAllBanks();
                break;
            case 0:
                flag = false;
                system("cls");
                break;
            default:
                break;
            }
        }
        catch (const char* msg)
        {
            cout << msg << endl;
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
    cout << "Чтобы выйти, введите 0: ";
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
        system("cls");
        return;
        break;
    default:
        break;
    }
}

void UserInterface::startMenuClient()
{
    bool flag = true;
    while (flag) {
        cout << "Выберите действие\nСоздать клиента: 1\nДобавить деньги на счет клиента: 2\nСнять деньги со счета клиента: 3\nПеревести деньги на другой счет: 4\nОтобразить всех клиентов: 5\nВыход: 0\n";
        int command = getValue<int>();
        switch (command)
        {
        case 1:
            addClient();
            break;
        case 2:
            setMoneyToClient();
            break;
        case 3:
            getMoneyFromClient();
            break;
        case 4:
            makeTransaction();
            break;
        case 5:
            showAllClients();
            break;
        case 0:
            flag = false;
            system("cls");
            break;
        default:
            break;
        }

    }
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

void UserInterface::makeTransaction()
{
    int key = -1;
    cout << "1 - Физический клиент, 2 - Юридический клиент: ";
    key = getValue<int>();
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
        cout << "Введите номер счета: ";
        int number;
        cin >> number;
        pc->transferMoney(number, money);
    }
    else if (key == 2)
    {
        cout << "Введите название компании: ";
        string name = getValue<string>();
        LegalСlient* pc = getLegalClient(name);
        cout << "Введите количетсво денег: ";
        int money = getValue<int>();
        cout << "Введите номер счета: ";
        int number;
        number = getValue<int>();
        cout << "Перевести в другой банк? 1 - да, 2 - нет: ";
        key = getValue<int>();
        while (key != 1 && key != 2)
            key = getValue<int>();
        if (key == 1)
        {
            string name;
            cout << "Введите название банка: ";
            name = getValue<string>();
            Bank* bank = getBank(name);
            pc->transferMoney(bank, number, money);
        }
        else
            pc->transferMoney(number, money);
    }
}

void UserInterface::showAllClients()
{
    for (Client* client : this->clients)
        cout << *client;
}

void UserInterface::addClient()
{
    int key = -1;
    cout << "1 - Физический клиент, 2 - Юридический клиент: ";
    key = getValue<int>();
    while (key != 1 && key != 2)
        key = getValue<int>();
    if (key == 1)
        addPhysicalClient();
    else if (key == 2)
        addLegalClient();
}

Bank* UserInterface::getBank(string name)
{
    for (Bank* bank : this->banks)
        if (bank->name == name)
            return bank;
    throw "Банк с таким названием отсутствует";
}

PhysicalСlient* UserInterface::getPhysicalClient(string firstname, string secondname)
{
    for (Client* client : clients)
        if (client->getDesignation() == firstname + " " + secondname)
            return (PhysicalСlient*)client;
    throw "Клиент с данной фамилией и именем отсутствует";
}

LegalСlient* UserInterface::getLegalClient(string name)
{
    for (Client* client : clients)
        if (client->getDesignation() == name)
            return (LegalСlient*)client;
    throw "Фирма с таким названием отсутствует";
}
