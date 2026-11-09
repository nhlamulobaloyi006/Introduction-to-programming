#include <iostream>
#include <vector>

using namespace std;

double balance = 0;
int declineCount = 0;
int option;
vector<string>transactions;


void history()
{
    cout << "Transactions"<<endl;
    if (transactions.size() <= 0)
    {
        cout << "======================================"<<endl;
        cout << "Transactions have not been made yet!"<<endl;
        cout << "======================================"<<endl;
    }
    else
    {
            for (int i = 0; i < transactions.size(); i++)
        {
            cout << "======================================"<<endl;
            cout << i+1  << ". "<<transactions[i] << endl;
            cout << "======================================"<<endl;
        }
    }
}

void lockOut()
{
    declineCount++;
    if (declineCount >=3)
    {
        cout << "Your account has been temporarily blocked, please visit your nearest branch"<<endl;
    }
}

void checkBalance()
{
    cout << "Balance : R"<< balance <<endl;

}

void depositCash()
{
    double deposit ;
    cout << "Enter amount you want to deposit : R";
    cin >> deposit;
    balance += deposit;
    cout << "You have successfully deposited R"<<deposit<<" to Mr Baloyi"<<endl;
    cout << "Available Balance : R" << balance<<endl;
    string deposited = to_string(deposit);
    transactions.push_back("Deposited R" + deposited);
}

void withdrawCash()
{
    double withdraw;
    cout << "Enter amount you want to withdraw R";
    cin>>withdraw;

    if (balance < withdraw)
    {
        cout << "You have insufficient funds" << endl;
        cout << "You can't withdraw R"<<withdraw<<" while your balance is R"<<balance<<endl;
        cout << "R5 Fee is deducted for each decline"<<endl;
        balance -= 5;
        cout << "Available Balance : R" << balance<<endl;
        string withdrawn = to_string(withdraw);
        transactions.push_back("Declined R" + withdrawn);
        cout << "============================"<<endl;
        lockOut();
    }
    else
    {
        balance -= withdraw;
        cout << "You have successfully withdrawn R"<<withdraw<<endl;
        cout<<"Remaining Balance : R"<<balance<<endl;
        string withdrawn = to_string(withdraw);
        transactions.push_back("Withdrawn R" + withdrawn);
    }

}

void menu()
{

    cout << "1. Check Balance"<<endl;
    cout << "2. Withdraw Cash "<<endl;
    cout << "3. Deposit Cash "<<endl;
    cout << "4. History "<<endl;
    cout << "= ";
    cin>>option;
    switch(option)
    {
    case 1:
        checkBalance();
        break;
    case 2:
        withdrawCash();
        break;
    case 3:
        depositCash();
        break;
    case 4:
        history();
        break;
    default:
        cout << "Error Redo"<<endl;
        break;
    }
}

int main()
{
  do
  {
      menu();
  } while (option != 5 && declineCount != 3);
    return 0;
}
