#include <iostream>
#include <vector>

using namespace std;

int option ;
struct BankingSystem
{
public:
    double balance = 0;
    string name, acc_no, pin;
    vector<BankingSystem> users;


    void UserInformation()
    {
        BankingSystem user,user2,user3;

        user.name = "Nhlamulo";
        user.acc_no = "20157234";
        user.pin = "0000";
        user.balance = 0;

        user2.name = "Ocean";
        user2.acc_no = "98654356";
        user2.pin = "1111";
        user2.balance = 0;

        user3.name = "Liyema";
        user3.acc_no = "57939532";
        user3.pin = "2222";
        user3.balance = 0;

        users.push_back(user);
        users.push_back(user2);
        users.push_back(user3);

        Authentiction();
    }

    void Authentiction()
    {
            cout<<"Login"<<endl;
            cout<<"Enter username"<<endl;
            cout<<"= ";
            cin>>name;
            cout<<"Enter pin"<<endl;
            cout<<"= ";
            cin>>pin;

            for (int i = 0; i < users.size(); i++)
            {
                cout<<"Hi"<<endl;
                if (users[i].name == name && users[i].pin == pin)
                {
                    cout<<"Login Successful"<<endl;
                    cout<<users[i].name;
                }
                if (users[i].name != name && users[i].pin != pin)
                {
                    cout<<"Username or Pin is incorrect"<<endl;
                    break;
                }

            }

    }
};


using namespace std;

int main()
{
    BankingSystem user;

    user.UserInformation();

    return 0;
}
