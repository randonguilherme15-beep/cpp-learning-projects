#include <iostream>

using namespace std;

int main()
{
    string name;
   cout << "Come ti chiami?  " << endl;
   cin >> name;

   int days;
   cout << "Quanti giorni resterai in vacanza ? " << endl;
   cin >> days;

   double spent;

   cout << "Quanto prevedi di spendere al giorno? " << endl;
   cin >> spent;

   double budget;
   cout << "Qual e il tuo budget totale? " << endl;
   cin >> budget;

   double spesaPrevista = spent*days;
   double budgetRimanente = budget-spesaPrevista;

   cout << "Ciao" << name << endl;
   cout << "Spesa prevista : " << spesaPrevista << endl;
   cout << "Budget rimanente : " << budgetRimanente << endl;

   return 0;
}

