#include <iostream>
#include <string>
using namespace std;

int main()
{ string name;
  int livello;
  int salute = 100;
  int pozioni = 2;
  bool haArmaSpeciale;
  int saluteBoss = 140;
  int attacco = 30;
  int ferita = 25;
  int feritaDifesa = 15;
  int aumentoPozione = 15;
  cout << "Nome personaggio = " << endl;
  cin >> name;

  cout << "Livello personaggio = " << endl;
  cin >> livello;

  cout << "E' in possesso dell'arma speciale? Si con 1, No con 0 " << endl;
  cin >> haArmaSpeciale;

  for (int turno=1; turno<=5; turno++) {
    cout << " ==================== Turno : " << turno << "==============================="<< endl;
    cout << " Salute giocatore : " << salute << endl;
    cout << " Salute boss : " << saluteBoss << endl;
    cout << "Pozioni : " << pozioni << endl;
    cout << " ==================== Scelta Azione =======================================" << endl;
    cout << "1. Attacca " << endl;
    cout << "2. Usa pozione " << endl;
    cout << "3. Difenditi " << endl;

    int scelta;
    cout << "Scegli azione" << endl;
    cin >> scelta;

    bool inDifesa = false;
    int dannoGiocatore = 0;

    switch (scelta) {
    case 1:
       if (livello >= 5 || haArmaSpeciale) {
        dannoGiocatore = 30;
       } else { dannoGiocatore = 15;
       }
       saluteBoss -= dannoGiocatore;

       if (saluteBoss < 0) {
        saluteBoss = 0;
       }
       cout << "Hai inflitto : " << dannoGiocatore << "danni al boss" << endl;
       cout << "Salute boss :" << saluteBoss << endl;
       break;
    case 2:
        if (pozioni> 0 && salute < 100 ) {
            salute += 25;
            pozioni--;
            if (salute>100) {
                    salute = 100;
            }
        cout << "Hai usato una pozione" << endl;
        cout << "Salute giocatore : " << salute << endl;
        cout << "Pozioni rimaste" << pozioni << endl;
        } else {
           cout << "Non puoi usare una pozione. " << endl;
           } break;

    case 3:
        inDifesa = true;
        cout << "Ti prepari a difenderti. " << endl;
        break;

    default:
        cout << "Azione non valida. Turno saltato" << endl;
        continue;
    }
    if (saluteBoss<=0) {
        cout << "=============================== Hai sconfitto il Boss!!!==========================" << endl;
        break;
    }
    int dannoBoss = 12;

if (turno % 2 == 0) {
    dannoBoss = 20;
}

if (inDifesa) {
    dannoBoss = dannoBoss / 2;
}

salute -= dannoBoss;

if (salute < 0) {
    salute = 0;
}

cout << "Il boss ti infligge "
     << dannoBoss << " danni." << endl;

cout << "Salute giocatore: "
     << salute << endl;
cout << "Salute Boss : " << saluteBoss << endl;
if (salute <= 0) {
    cout << "Sei stato sconfitto dal boss." << endl;
    break;
}
    }


  if (saluteBoss > 0 && salute > 0) {
    cout << "Il boss e ancora in piedi. La prova e fallita." << endl;
}
     return 0;


}
