#include <iostream>
#include <string>

using namespace std;

int main()
{
    string subjects[3];
   string subjectName;
   int i;



   for (i = 0; i < 3; i++)
   {
       cout << "Enter Subject " << i+1 << " :"<< endl;
       cin >> subjects[i];
   }

   for (int i = 0; i < 3; i++)
   {
       cout << i+1 <<". " << subjects[i] <<endl;
   }


    return 0;
}
