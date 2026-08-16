#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int CODICE_CORRETTO = 48291;
    const int NUMERO_DOMANDE = 5;

    string nome;
    int codiceInserito;
    bool accessoConsentito = false;

    cout << "====================================================\n";
    cout << "          NEON SECURITY ACADEMY - TEST C++          \n";
    cout << "====================================================\n\n";

    cout << "Inserisci il nome operatore: ";
    cin >> nome;

    cout << "\nCiao " << nome << ". Hai 3 tentativi per accedere.\n";

    for (int tentativo = 1; tentativo <= 3; tentativo++) {
        cout << "Tentativo " << tentativo << " - codice a 5 cifre: ";
        cin >> codiceInserito;

        if (codiceInserito == CODICE_CORRETTO) {
            accessoConsentito = true;
            cout << "Codice corretto. Accesso consentito.\n";
            break;
        }

        cout << "Codice errato.\n";
    }

    if (!accessoConsentito) {
        cout << "\nAccesso bloccato. Programma terminato.\n";
        return 0;
    }

    int sceltaRuolo;
    string ruolo;
    int potenzaBase = 20;

    cout << "\n================ SCELTA DEL RUOLO ================\n";
    cout << "1. Analista\n";
    cout << "2. Programmatore\n";
    cout << "3. Specialista sicurezza\n";
    cout << "Scegli il ruolo: ";
    cin >> sceltaRuolo;

    switch (sceltaRuolo) {
        case 1:
            ruolo = "Analista";
            potenzaBase = 22;
            break;

        case 2:
            ruolo = "Programmatore";
            potenzaBase = 25;
            break;

        case 3:
            ruolo = "Specialista sicurezza";
            potenzaBase = 30;
            break;

        default:
            ruolo = "Recluta";
            potenzaBase = 18;
            cout << "Scelta non valida: ruolo Recluta assegnato.\n";
    }

    cout << "Ruolo selezionato: " << ruolo << "\n";

    string domande[NUMERO_DOMANDE] = {
        "1) Qual e il primo indice di un array?\n   A) 1   B) 0   C) -1",

        "2) Quando l'operatore && restituisce true?\n"
        "   A) Quando una condizione e vera\n"
        "   B) Sempre\n"
        "   C) Quando entrambe sono vere",

        "3) Quale istruzione interrompe uno switch?\n"
        "   A) break   B) continue   C) stop",

        "4) Come controlli se un numero e pari?\n"
        "   A) n / 2 == 0   B) n % 2 == 0   C) n == 2",

        "5) Qual e l'ultimo indice valido di int valori[4]?\n"
        "   A) 4   B) 2   C) 3"
    };

    char risposteCorrette[NUMERO_DOMANDE] = {
        'B', 'C', 'A', 'B', 'C'
    };

    int punteggio = 0;

    cout << "\n================ TEST TECNICO ====================\n";

    for (int i = 0; i < NUMERO_DOMANDE; i++) {
        char risposta;

        cout << "\n" << domande[i] << "\n";
        cout << "Risposta: ";
        cin >> risposta;

        risposta = static_cast<char>(
            toupper(static_cast<unsigned char>(risposta))
        );

        if (risposta == risposteCorrette[i]) {
            cout << "Corretto!\n";
            punteggio++;
        } else {
            cout << "Sbagliato. Risposta corretta: "
                 << risposteCorrette[i] << "\n";
        }
    }

    cout << "\nPunteggio finale: "
         << punteggio << "/" << NUMERO_DOMANDE << "\n";

    bool bonusQuiz = punteggio >= 4;

    if (bonusQuiz) {
        cout << "Bonus sbloccato: +5 potenza.\n";
        potenzaBase += 5;
    } else {
        cout << "Nessun bonus tecnico sbloccato.\n";
    }

    int saluteGiocatore = 100;
    int saluteServerNemico = 90;
    int kitMedici = 2;
    int scudi = 1;
    bool vittoria = false;

    cout << "\n================ MISSIONE FINALE =================\n";
    cout << "Devi disattivare un server ostile entro 5 turni.\n";

    for (int turno = 1; turno <= 5; turno++) {
        bool inDifesa = false;
        int sceltaAzione;

        cout << "\n---------------- TURNO "
             << turno << " ----------------\n";

        cout << "Salute operatore: "
             << saluteGiocatore << "\n";

        cout << "Integrita server: "
             << saluteServerNemico << "\n";

        cout << "Kit medici: "
             << kitMedici << "\n";

        cout << "Scudi: "
             << scudi << "\n\n";

        cout << "1. Lancia attacco informatico\n";
        cout << "2. Attiva scudo\n";
        cout << "3. Usa kit medico\n";

        cout << "Azione: ";
        cin >> sceltaAzione;

        switch (sceltaAzione) {
            case 1:
                saluteServerNemico -= potenzaBase;

                if (saluteServerNemico < 0) {
                    saluteServerNemico = 0;
                }

                cout << "Hai inflitto "
                     << potenzaBase
                     << " danni al server.\n";
                break;

            case 2:
                if (scudi > 0) {
                    inDifesa = true;
                    scudi--;

                    cout << "Scudo attivato per questo turno.\n";
                } else {
                    cout << "Non hai piu scudi disponibili.\n";
                }

                break;

            case 3:
                if (kitMedici > 0 &&
                    saluteGiocatore < 100) {

                    saluteGiocatore += 25;
                    kitMedici--;

                    if (saluteGiocatore > 100) {
                        saluteGiocatore = 100;
                    }

                    cout << "Kit utilizzato. Salute attuale: "
                         << saluteGiocatore << "\n";
                } else {
                    cout << "Non puoi usare il kit medico.\n";
                }

                break;

            default:
                cout << "Azione non valida. Turno saltato.\n";
                continue;
        }

        if (saluteServerNemico <= 0) {
            vittoria = true;
            cout << "\nServer ostile disattivato!\n";
            break;
        }

        int dannoNemico = 14;

        if (turno % 2 == 0) {
            dannoNemico = 22;
        }

        if (inDifesa) {
            dannoNemico /= 2;
        }

        saluteGiocatore -= dannoNemico;

        if (saluteGiocatore < 0) {
            saluteGiocatore = 0;
        }

        cout << "Il server contrattacca e infligge "
             << dannoNemico << " danni.\n";

        if (saluteGiocatore <= 0) {
            cout << "L'operatore e stato neutralizzato.\n";
            break;
        }
    }

    cout << "\n================ RAPPORTO FINALE =================\n";
    cout << "Operatore: " << nome << "\n";
    cout << "Ruolo: " << ruolo << "\n";
    cout << "Punteggio test: " << punteggio << "/5\n";
    cout << "Salute finale: " << saluteGiocatore << "\n";
    cout << "Integrita server finale: "
         << saluteServerNemico << "\n";

    if (vittoria && saluteGiocatore > 0) {
        cout << "Esito: MISSIONE COMPLETATA.\n";
    } else if (saluteGiocatore <= 0) {
        cout << "Esito: OPERATORE SCONFITTO.\n";
    } else {
        cout << "Esito: TEMPO ESAURITO.\n";
    }

    cout << "====================================================\n";

    return 0;
}