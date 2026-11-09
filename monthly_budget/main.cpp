#include <iostream>

using namespace std;

int main()
{
    double monthly_budget, years, item_price, calculate;
    item_price = 5000;
    monthly_budget = 370;
    calculate = item_price / monthly_budget;
    years = calculate / 12;


    if (years == 1 || calculate > 1){
            cout<<calculate<<" months"<<endl;
           cout<<years<<" year";
    }
    else
    {
          cout<<years<<" years";
          cout<<calculate<<" month"<<endl;
    }


    return 0;
}
