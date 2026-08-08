#include <iostream>
#include <string>
using namespace std;

int main()
{  cout << "Che Viaggio Vogliamo Organizzare Oggi??????" << endl;

    string name;
  cout << "Come ti chiami? = " << endl;
  cin >> name;

  int eta;
  cout << "Quanti anni hai ? = " << endl;
  cin >> eta;

  int giorni;
  cout << "Quanti giorni resterai all'Estero? = " << endl;
  cin >> giorni;

  double budget;
  cout << "Qual è il tuo budget iniziale? = " << endl;
  cin >> budget;

  double costoVolo;
  cout << "Quanto costa il volo? =" << endl;
  cin >> costoVolo;

  double spesaGiornaliera;
  cout << "Quanto prevedi di spendere al giorno? = " << endl;
  cin >> spesaGiornaliera;

  double oreLavoro;
  cout << "Quante ore lavorerai ogni giorno? =" << endl;
  cin >> oreLavoro;

  double pagaOraria;
  cout << "Quanto guadagnerai all'ora? = " << endl;
  cin >> pagaOraria;

  bool haPassaporto;
  cout << "Hai un passaporto? Digita 1 per si e 0 per no" << endl;
  cin >> haPassaporto;

  cout << "==============================================================" << endl;

  cout <<                           "Risultati" << endl;

  auto settimaneComplete = giorni/7;
  auto giorniAvanzati = giorni%7;
  auto costoTot = spesaGiornaliera*giorni;
  auto costoViaggio = costoVolo+costoTot;
  auto guadagnoPrevisto = oreLavoro* pagaOraria*giorni;
  auto denaroFinale = budget+guadagnoPrevisto-costoViaggio;

  cout << "Settimane complete = " << settimaneComplete << endl;
  cout << "Giorni avanzati = " << giorniAvanzati << endl;
  cout << "Costo totale = " << costoTot << endl;
  cout << "Costo totale solo viaggio = " << costoViaggio << endl;
  cout << "Guadagno previsto lavorativo = " << guadagnoPrevisto << endl;
  cout << "Guadagno lavoro e spese = " << denaroFinale << endl;

  cout << "=============================================================" << endl;

  cout <<                     "Considerazioni Finali" << endl;

  if (eta>=18) {
    cout << "Sei maggiorenne e puoi organizzare il viaggio." << endl;
    cout << "Controllo Documenti ... ";

    if (haPassaporto== true) {
        cout << "Passaporto Disponibile " << endl;
    }
    else {
   cout << "Passaporto Mancante " << endl;
   }
  } else {
      cout << "Non puoi organizzare il viaggio da solo" << endl;
  }


  if (denaroFinale>=1000) {
    cout << "Situazione economica ottima";
  } else if (denaroFinale>=0 && denaroFinale<1000) {
      cout << "Puoi partire, ma il margine economico è limitato." << endl;
  } else  {
      cout << "Il budget é insufficiente" << endl;
  }

return 0;

}
