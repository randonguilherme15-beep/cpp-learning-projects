#include <iostream>
#include <string>
using namespace std;

int main()
{ string nome;

  int livello;
  bool haBadge;
  bool conosceCodice;
  bool accountBloccato;

  cout << "Nome operatore : "<< endl;
  cin >> nome;

  cout << "Livello autorizzazione :" << endl;
  cin >> livello;

  cout << "Possiede il Badge? 1= si, 0= no" << endl;
  cin >> haBadge;

  cout << "Conosci il codice di sicurezza? 1=si, 0=no" << endl;
  cin >> conosceCodice;

  cout << "Account bloccato? 1=si, 0=no" << endl;
  cin >> accountBloccato;

  if ((livello>= 5 || haBadge) && !accountBloccato) {
     cout << "  Accesso consentito al server centrale  " << endl;
    } else { cout << "Accesso negato. Requisiti insufficienti" << endl;
    }
  return 0;

}
