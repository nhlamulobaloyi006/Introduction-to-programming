#include <iostream>

using namespace std;

double vat_amount;
int option;

void calculateVatExclusive()
{
    double calculate, results, results_inc;
    cout<<"========================"<<endl;
    cout<<"VAT EXCLUSIVE CALCULATOR"<<endl;
    cout<<"========================"<<endl;
    cout<<"Enter VAT inclusive amount"<<endl;
    cout<<"=R";
    cin>>vat_amount;

    calculate = vat_amount / 1.15;
    results = vat_amount - calculate;
    results_inc = calculate + results;
    cout<<"============================="<<endl;
    cout<<"How to calculate vat exclusive"<<endl;
    cout<<"1. Formula =  Inclusive Price / 1.15 = Exclusive Price"<<endl;
    cout<<"2. Formula = Inclusive Price  -  Exclusive Price = Difference"<<endl;
    cout<<"3. Formula = Inclusive Price  +  Exclusive Price = Inclusive Price"<<endl;
    cout<<""<<endl;
    cout<<"1. Original Price = R"<<vat_amount<<" /"<<" 1.15 "<<"= R"<<calculate<<endl;
    cout<<"2. Difference = R"<<vat_amount<<"  -"<<"  R"<<calculate<<" = R"<<results<<endl;
    cout<<"3. VAT INC = R"<<calculate<<"  +"<<"  R"<<results<<" = R"<<results_inc<<endl<<endl;
    cout<<"  Vat Exclusive = R"<<calculate<<endl;
    cout<<"============================="<<endl;

}
void calculateVatInclusive()
{
    double calculate, results, results_inc;
    cout<<"========================"<<endl;
    cout<<"VAT INCLUSIVE CALCULATOR"<<endl;
    cout<<"========================"<<endl;
    cout<<"Enter VAT inclusive amount"<<endl;
    cout<<"=R";
    cin>>vat_amount;

    calculate = vat_amount * 0.15;
    results = vat_amount + calculate;
    cout<<"============================="<<endl;
    cout<<"How to calculate vat exclusive"<<endl;
    cout<<"1. Formula =  Exclusive Price x 0.15 = Inclusive Price "<<endl;
    cout<<"2. Formula = Exclusive Price  + Inclusive Price = Total Inclusive Price"<<endl;
    cout<<""<<endl;
    cout<<"1. Vat Inclusive = R"<<vat_amount<<" x 0.15 = "<<calculate<<endl;
    cout<<"2. Vat Inclusive = R"<<vat_amount<<" + R"<<calculate<<" = R"<<results<<endl<<endl;
    cout<<"  Vat Inclusive = R"<<results<<endl;
    cout<<"============================="<<endl;

}
void menu()
{
    cout<<"========================"<<endl;
    cout<<"  VAT  CALCULATOR"<<endl;
    cout<<"========================"<<endl;
    cout<<"CHOOSE OPTION"<<endl;
    cout<<"1. VAT INCLUSIVE"<<endl;
    cout<<"2. VAT EXCLUSIVE"<<endl;
    cout<<"3. EXIT"<<endl;
    cout<<"= ";
    cin>>option;

    switch(option)
    {
    case 1:
        calculateVatInclusive();
        break;
    case 2:
        calculateVatExclusive();
        break;
    default:
        cout<<"Exiting program..."<<endl;
        break;
    }

}
int main()
{
    do
    {
        menu();
    } while (option != 3);

    return 0;
}
