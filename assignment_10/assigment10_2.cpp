

#include <iostream>
#include <list>
using namespace std;

enum account_type
{
    SAVING = 1,
    CURRENT = 2,
    DMAT = 3
};

class insuff_funds
{
    int accid;
    double cur_bal;
    double withdraw_bal;

public:
    insuff_funds(int id, double cur_bal, double withdraw_bal)
    {
        this->accid = id;
        this->cur_bal = cur_bal;
        this->withdraw_bal = withdraw_bal;
    }

    void display()
    {
        cout << "\n****************************Insufficient funds****************************\n";
        cout << "You Cannot withdraw amount\n";
        cout << "Account id : " << accid;
        cout << " Current balance : " << cur_bal << " is less than withdrawal amount : " << withdraw_bal;
    }
};

class account
{
    int id;
    double balance;
    account_type type;

public:
    account()
    {
        this->id = 0;
        this->balance = 0;
    }
    account(int id, account_type type)
    {
        this->id = id;
        this->type = type;
    }

    int get_id()
    {
        return this->id;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_type(account_type type)
    {
        this->type = type;
    }

    account_type get_type()
    {
        return this->type;
    }

    void accept()
    {
        int num;
        cout << "\nEnter bank account details";
        cout << "\nEnter account id : ";
        cin >> id;
        cout << "\nEnter account balance : ";
        cin >> balance;
        cout << "1. SAVING \n2. CURRENT \n3. DMAT \nChoose account type : ";
        cin >> num;
        type = static_cast<account_type>(num);
    }

    void deposit(double depoAmt)
    {
        this->balance += depoAmt;
    }

    void withdraw(double withdrawAmt)
    {
        if (withdrawAmt > balance)
            throw insuff_funds(id, balance, withdrawAmt);

        this->balance -= withdrawAmt;
    }
    void display() const // Add const here
    {
        cout << "\n*****************************Bank Account Details*****************************\n";
        cout << "Account id is : " << this->id;
        cout << "\nAccount balance is : " << this->balance;
        cout << "\nAccount type : ";

        switch (type)
        {
        case SAVING:
            cout << "SAVING";
            break;
        case CURRENT:
            cout << "CURRENT";
            break;
        case DMAT:
            cout << "DMAT";
            break;
        }
    }
};

enum menulist
{
    EXIT,
    ADDBAL,
    WITHDRAW,
    DISPLAYAC,
    DISPLAYREV
};

int menu()
{
    int choice;
    cout << "\n*****************************MENU*****************************\n";
    cout << "\n 0. EXIT \t 1. ACCEPT\t 2. DEPOSIT \t 3. WITHDRAW \t 4. DISPLAY FORWARD \t 5. DISPLAY REVERSE";
    cout << "\nEnter your choice : ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    double depAmt, withdrawAmt;
    list<account> accList; // list to store account objects

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            account a;
            a.accept();
            accList.push_back(a);
            break;
        }
        case 2:
            cout << "Enter amount to deposit : ";
            cin >> depAmt;
            accList.back().deposit(depAmt); // Deposit to the last account in the list
            break;
        case 3:
            cout << "Enter amount to withdraw : ";
            cin >> withdrawAmt;
            try
            {
                accList.back().withdraw(withdrawAmt); // Withdraw from the last account in the list
            }
            catch (insuff_funds ins_funds)
            {
                ins_funds.display();
            }
            break;
        case 4:
            cout << "Accounts in forward order:" << endl;
            for (const auto &acc : accList)
                acc.display();
            break;
        case 5:
            cout << "Accounts in reverse order:" << endl;
            for (list<account>::reverse_iterator it = accList.rbegin(); it != accList.rend(); ++it)
                it->display();
            break;
        }
    }

    return 0;
}