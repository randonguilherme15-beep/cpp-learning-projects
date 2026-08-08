#include <iostream>

using namespace std;

int main()
{

    int pizze = 7;
    int fettePizza = 8;
    int persone = 6;
    double costoPizza = 9.50;
    double costoBibite = 12.80;
    double budget = 100;

    cout << "Numero totale fette = " << fettePizza*pizze << endl;
    cout << "Fette ricevute da ogni persona = " << (fettePizza*pizze)/persone << endl;
    cout << "Fette che avanzano = " <<  (fettePizza*pizze)%persone << endl;
    cout << "Costo totale delle pizze = " <<  (pizze*costoPizza) << endl;
    cout << "Costo complessivo con le bibite = " << (costoPizza*pizze)+costoBibite << endl;
    cout << "Denaro rimasto dal budget = " << budget-(costoBibite+costoPizza*pizze) << endl;

    return 0;
}
