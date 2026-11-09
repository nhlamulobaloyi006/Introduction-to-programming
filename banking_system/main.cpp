#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
//user details stored inside arrays
string usernames[4] = {"Nhlamulo","Ocean","Liyema","Martin"};
string surnames[4] = {"Baloyi","Chirwa","Goloza","Chuine"};
string pins[4] = {"0625","0514","0524","0824"};
int account_numbers[4] = {20154545, 20456942, 20649863, 20348548};
double balances[4] = {0, 10, 25, 30};
//Logged in user details
string name, surname;
int account_num;
int getIndex;
double balance = balances[getIndex];
//TIME
    time_t now = time(0);

//menu option
int option;

void checkBalance(double balance)
{
    balance = balances[getIndex];
    cout<<"======================="<<endl;
    cout<<"Account Details"<<endl;
    cout<<"======================="<<endl;
    cout<<"Account Holder: MR "<<name[0]<<" "<<surname<<endl;
    cout<<"Account number: "<<account_num<<endl;
    cout<<"Balance: R"<<balance<<endl;
}
void deposit(double balance, string name)
{
    double depositCash, avail_balance;
    balance = balances[getIndex];
    cout<<"Enter amount to deposit"<<endl;
    cout<<"=R";
    cin>>depositCash;
    avail_balance = balance += depositCash;
    balances[getIndex] = avail_balance;
    balance = balances[getIndex];



    cout<<"========================================================="<<endl;
    cout<<" NB SMART BANKING SYSTEMS             Transaction record"<<endl<<endl;
    cout<<"                                CASH DEPOSIT RECEIPT"<<endl<<endl;
    cout<<" TRANSACTION DATE   "<<ctime(&now)<<endl;
    cout<<" BUSINESS DATE      "<<ctime(&now)<<endl<<endl;
    cout<<" CUSTOMER NAME      "<<name[0]<<" "<<surname<<endl<<endl;
    cout<<" TO ACCOUNT         "<<account_num<<endl<<endl;
    cout<<" AMOUNT DEPOSITED    R"<<depositCash<<endl<<endl;
    cout<<"========================================================="<<endl;
}
void withdraw(double balance)
{
    double withdrawCash, avail_balance;
    balance = balances[getIndex];

    cout<<"Enter amount to withdraw"<<endl;
    cout<<"=R";
    cin>>withdrawCash;

    if (balance < withdrawCash)
    {
        cout<<"You have insufficent funds"<<endl;
    }
    else
    {
        string convert, last_four_digits;
        convert = account_numbers[getIndex];
        cout<<account_numbers[getIndex]<<endl;
        avail_balance = balance -= withdrawCash;
        balances[getIndex] = avail_balance;
        balance = balances[getIndex];

        cout<<"========================================================="<<endl;
        cout<<" NB SMART BANKING SYSTEMS             Transaction record"<<endl<<endl;
        cout<<"                                CASH WITHDRAWAL RECEIPT"<<endl<<endl;
        cout<<" TRANSACTION DATE   "<<ctime(&now)<<endl;
        cout<<" BUSINESS DATE      "<<ctime(&now)<<endl<<endl;
        cout<<" FROM ACCOUNT        "<<"*************"<<to_string(account_numbers[getIndex]).substr(4, 4)<<endl<<endl;
        cout<<" AMOUNT WITHDRAWN   R -"<<withdrawCash<<endl<<endl;
        cout<<" AVAILABE FUNDS     R "<<balance<<endl<<endl;
        cout<<" ACCOUNT BALANCE    R "<<balance<<endl;
        cout<<"========================================================="<<endl;
    }
}
void sendCash(double balance)
{
    vector <string> names = {};
    vector <string> surnames = {};
    vector <int> accounts = {};
    string name, surname, acc_ref;
    int account_number, index;
    double sendCashAmount;
    balance = balances[getIndex];

    cout<<"======================="<<endl;
    cout<<"    Beneficiaries"<<endl;
    cout<<"======================="<<endl;


        cout<<"Enter benefiacry name"<<endl;
        cout<<"= ";
        cin>>name;
        cout<<"Enter benefiacry surname"<<endl;
        cout<<"= ";
        cin>>surname;
        cout<<"Enter benefiacry account number"<<endl;
        cout<<"= ";
        cin>>account_number;
        cout<<"Enter beneficiary reference"<<endl;
        cout<<"= ";
        getline(cin, acc_ref);


        if (isalpha(name[0]) && isalpha(surname[0]) && account_number == account_numbers[0] && name == "Nhlamulo" && account_num != account_numbers[0] || account_number == account_numbers[1]  && name == "Ocean" && account_num != account_numbers[1] || account_number == account_numbers[2]  && name == "Liyema" && account_num != account_numbers[2] || account_number == account_numbers[3]  && name == "Martin" && account_num != account_numbers[3] )
        {
                cout<<"Enter amount"<<endl;
                cout<<"=R";
                cin>>sendCashAmount;

                for (int i = 0; i < 4; i++)
                {
                    if(name == usernames[i])
                    {
                        index = i;
                        cout<<"Index: "<<index<<endl;
                        cout<<usernames[i]<<endl;
                    }
                }

                if (balance >= sendCashAmount)
                {
                    balances[index] = balances[index] += sendCashAmount;
                    balances[getIndex] = balance -= sendCashAmount;
                    balance = balances[getIndex];

                    cout<<"========================================================="<<endl;
                    cout<<" NB SMART BANKING SYSTEMS             Transaction record"<<endl<<endl;
                    cout<<"                                PROOF OF PAYMENT"<<endl<<endl;
                    cout<<" BENEFICIARY NAME            "<<"MR "<<name[0]<<" "<<surname<<endl;
                    cout<<" BENEFICIARY ACCOUNT NUMBER        "<<account_number<<endl;
                    cout<<" BENEFICIARY REFERENCE        "<<acc_ref<<endl;
                    cout<<" AMOUNT    R "<<sendCashAmount<<endl<<endl;
                    cout<<" TRANSACTION DATE   "<<ctime(&now)<<endl;
                    cout<<"========================================================="<<endl;
                }
                else
                {
                    cout<<"You have insufficient funds"<<endl;
                }

        }
        else
        {
            cout<<"Invalid input, please try again"<<endl;
        }


}
//function to validate authentication user input
void validateAuthInput(string username, string pin)
{
        if (username.length() <= 0 || pin.length() != 4)
        {
            cout<<""<<endl;
        }
}

  bool isUser = false;
//function for authentication
void authentication()
{
    cout<<"============================"<<endl;
    cout<<" NB SMART BANKING SYSTEMS"<<endl;
    cout<<"============================"<<endl;


    string username,pin;



    do
    {
        cout<<"        LOGIN"<<endl<<endl;
        cout<<"Username: "<<endl;
        cin>>username;
        cout<<"Pin: "<<endl;
        cin>>pin;

        validateAuthInput(username, pin);

        for (int i = 0; i < 4; i++)
        {
            if (usernames[i] == username && pins[i] == pin)
            {
                getIndex = i;
                isUser = true;
                name = usernames[i];
                surname = surnames[i];
                account_num = account_numbers[i];
                balance = balances[i];
            }


        }

        if (isUser == false)
        {
            cout<<"username or pin is invalid"<<endl;
            cout<<"============================"<<endl;
        }
        else
        {
            cout<<"Access granted"<<endl;
        }

    } while(username.length() != 0 && pin.length() != 4);

}
void menu()
{

    cout<<"======================="<<endl;
    cout<<"Welcome back "<<name<<endl;
    cout<<"======================="<<endl;
    cout<<"Choose option"<<endl;
    cout<<"1. Check Balance & Account Details"<<endl;
    cout<<"2. Deposit Cash"<<endl;
    cout<<"3. Withdraw Cash"<<endl;
    cout<<"4. Send Cash"<<endl;
    cout<<"5. Sign out"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"= ";
    cin>>option;

    switch(option)
    {
    case 1:
        checkBalance(balance);
        break;
    case 2:
        deposit(balance, name);
        break;
    case 3:
        withdraw(balance);
        break;
    case 4:
        sendCash(balance);
        break;
    case 5:
        authentication();
        break;
        break;
    default:
        cout<<"Exiting program.."<<endl;
        break;
    }
}
int main ()
{

    authentication();
    if (isUser == false)
    {
        do
        {
            authentication();
        } while(isUser != true);
    }
    else
    {
        do
        {
            menu();

        } while(option != 0);
    }


    return 0;
}
