#include <iostream>
#include <string>
using namespace std;

int main()
{ cout << "_______________GIOCO DELL'ARENA________________" << endl;

 cout << "       Negoziante chiede :    " << endl;

 string name;
 cout << "     Nome personaggio = " << endl; cin >> name;

 double crediti;
 cout << "         Crediti disponibili  =   " << endl; cin >> crediti;

 cout << "    Articoli disponibili" << endl;

 cout << "^=-________________________-=^" << endl;

 cout << "  1. Spada al Plasma  - 80 crediti " << endl;
 cout << "  2. Lancia infuocata - 120 crediti " << endl;
 cout << "  3. Scudo di Medusa  - 60 crediti " << endl;
 cout << "  4. Kit medico       - 30 crediti " << endl;

 cout << "^=-________________________-=^" << endl;


 int scelta;
  double prezzo = 0;
  bool sceltaValida = true;

  cout << " Quale articolo vuoi acquistare? Digita da 1 a 4: ";
  cin >> scelta;

  switch (scelta) {
    case 1:
    prezzo = 80;
    cout << "      Hai scelto la Spada al Plasma     " << endl;
      break;

    case 2:
    prezzo = 120;
    cout << "      Hai scelto la Lancia Infuocata    " << endl;
      break;

    case 3 :
     prezzo= 60;
    cout << "       Hai scelto lo Scudo di Medusa    " << endl;
       break;

    case 4:
    prezzo = 30;
    cout << "        Hai scelto il Kit Medico        " << endl;
    break;

    default:
    cout << "!!!!!!!!!!Scelta non possibile!!!!!!" << endl;
    sceltaValida= false;
    break;
  }
  if (sceltaValida) {
    if (crediti >= prezzo) {
        double creditiRimasti = crediti-prezzo;
        cout << "Acquisto completato, complimenti Avventuriero " << endl;
        cout << "Crediti rimasti = " << creditiRimasti << endl;
    } else {
        double creditiMancanti = prezzo- crediti;
        cout << "Acquisto non possibile, ritorna a lavorare Avventuriero" << endl;
        cout << " Ti mancano =  " << creditiMancanti << endl;
    }

    return 0;


  }
}











