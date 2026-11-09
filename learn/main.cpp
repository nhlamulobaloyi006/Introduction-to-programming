#include <iostream>
#include <vector>

using namespace std;

struct User
{
    string name;
    int age;

    void info()
    {
        cout<<"Name: "<<endl;
        cin>>name;
        cout<<"Age: "<<endl;
        cin>>age;
             cout<<"================"<<endl;
    }
};

int main()
{
    User user;
    vector<User> users;

   for (int i = 0; i < 3; i++)
   {
       user.info();
       users.push_back(user);

   }
     cout<<"Users"<<endl;
   for(int i = 0; i < users.size();  i++)
   {

       cout<<users[i].name<<endl;

   }




    return 0;
}
