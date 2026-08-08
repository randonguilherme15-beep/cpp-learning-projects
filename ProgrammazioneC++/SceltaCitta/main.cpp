#include <iostream>

using namespace std;

int main()
{
   int sceltaCitta;

cout << "Scegli la citta:" << endl;
cout << "1. Sydney" << endl;
cout << "2. Melbourne" << endl;
cout << "3. Perth" << endl;
cout << "4. Brisbane" << endl;

cin >> sceltaCitta;

switch (sceltaCitta) {

    case 1:
       cout << "Sydney" << endl;// stampa Sydney
        break;

    case 2:
        cout << "Melbourn" << endl; // stampa Melbourne
        break;

    case 3:
        cout << "Perth" << endl;// stampa Perth
        break;

    case 4:
        cout << "Brisbane" << endl; // stampa Brisbane
        break;

    default:
        cout << "Scelta non valida" << endl;// stampa scelta non valida

    return 0;
}
}
