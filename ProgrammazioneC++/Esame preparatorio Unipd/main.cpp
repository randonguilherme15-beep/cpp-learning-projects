#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;

struct Domanda {
    string sezione;
    string testo;
    vector<string> opzioni;
    char corretta;
    string spiegazione;
};

char leggiRisposta() {
    char risposta;
    while (true) {
        cout << "\nRisposta (A/B/C/D): ";
        cin >> risposta;
        risposta = toupper(risposta);

        if (risposta >= 'A' && risposta <= 'D') {
            return risposta;
        }

        cout << "Inserisci solamente A, B, C oppure D.\n";
    }
}

int main() {
    vector<Domanda> domande = {
        {
            "Matematica",
            "Se 3x - 5 = 16, quanto vale x?",
            {"5", "7", "9", "11"},
            'B',
            "3x = 21, quindi x = 7."
        },
        {
            "Matematica",
            "Quale frazione e' equivalente a 0,375?",
            {"3/8", "3/5", "5/8", "7/20"},
            'A',
            "0,375 = 375/1000 = 3/8."
        },
        {
            "Matematica",
            "Quanto vale (2^3 * 2^4) / 2^5?",
            {"2", "4", "8", "16"},
            'B',
            "Con la stessa base: 2^(3+4-5) = 2^2 = 4."
        },
        {
            "Logica",
            "Completa la sequenza: 2, 6, 12, 20, 30, ...",
            {"36", "40", "42", "44"},
            'C',
            "Le differenze sono 4, 6, 8, 10; la successiva e' 12. Quindi 30 + 12 = 42."
        },
        {
            "Logica",
            "Tutti i programmatori sono curiosi. Alcune persone curiose sono musicisti. Quale conclusione e' certamente vera?",
            {
                "Tutti i musicisti sono programmatori",
                "Alcuni programmatori sono musicisti",
                "Tutti i programmatori sono curiosi",
                "Nessun musicista e' programmatore"
            },
            'C',
            "L'unica conclusione garantita e' quella gia' contenuta nella prima premessa."
        },
        {
            "Comprensione verbale",
            "La frase 'Benche' fosse stanco, continuo' a studiare' indica:",
            {"Una causa", "Una concessione", "Una conseguenza", "Una condizione"},
            'B',
            "'Benche'' introduce una concessione: il fatto avviene nonostante un ostacolo."
        },
        {
            "Comprensione verbale",
            "Quale parola e' il contrario di 'effimero'?",
            {"Breve", "Inutile", "Duraturo", "Fragile"},
            'C',
            "'Effimero' significa di breve durata; il contrario e' 'duraturo'."
        },
        {
            "Scienze",
            "Qual e' l'unita' di misura della forza nel Sistema Internazionale?",
            {"Joule", "Watt", "Pascal", "Newton"},
            'D',
            "La forza si misura in newton (N)."
        },
        {
            "Scienze",
            "Un corpo percorre 120 metri in 15 secondi a velocita' costante. Qual e' la velocita'?",
            {"6 m/s", "8 m/s", "10 m/s", "12 m/s"},
            'B',
            "v = spazio / tempo = 120 / 15 = 8 m/s."
        },
        {
            "Matematica",
            "Qual e' il dominio della funzione 1/(x - 4)?",
            {"Tutti i reali", "x > 4", "x < 4", "Tutti i reali tranne 4"},
            'D',
            "Il denominatore non puo' essere zero, quindi x deve essere diverso da 4."
        }
    };

    cout << "=========================================\n";
    cout << "   SIMULAZIONE TOLC-I - DIAGNOSTICO 1\n";
    cout << "=========================================\n";
    cout << "10 domande. Una sola risposta corretta.\n";
    cout << "Il programma salvera' i risultati nel file:\n";
    cout << "risultati_TOLCI_diagnostico1.txt\n\n";

    cout << "Inserisci il tuo nome: ";
    string nome;
    getline(cin, nome);

    vector<char> risposte;
    vector<long long> tempi;
    int corrette = 0;
    int errate = 0;

    auto inizioTotale = chrono::steady_clock::now();

    for (size_t i = 0; i < domande.size(); i++) {
        const Domanda& d = domande[i];

        cout << "\n-----------------------------------------\n";
        cout << "Domanda " << i + 1 << "/" << domande.size();
        cout << " - " << d.sezione << "\n";
        cout << d.testo << "\n\n";

        for (size_t j = 0; j < d.opzioni.size(); j++) {
            cout << char('A' + j) << ") " << d.opzioni[j] << "\n";
        }

        auto inizioDomanda = chrono::steady_clock::now();
        char risposta = leggiRisposta();
        auto fineDomanda = chrono::steady_clock::now();

        long long secondi = chrono::duration_cast<chrono::seconds>(
            fineDomanda - inizioDomanda
        ).count();

        risposte.push_back(risposta);
        tempi.push_back(secondi);

        if (risposta == d.corretta) {
            corrette++;
        } else {
            errate++;
        }

        // Non mostra la soluzione subito, per non falsare il test.
        cout << "Risposta registrata.\n";
    }

    auto fineTotale = chrono::steady_clock::now();
    long long tempoTotale = chrono::duration_cast<chrono::seconds>(
        fineTotale - inizioTotale
    ).count();

    double punteggioTolc = corrette * 1.0 - errate * 0.25;

    ofstream file("risultati_TOLCI_diagnostico1.txt");

    if (!file.is_open()) {
        cerr << "\nErrore: impossibile creare il file dei risultati.\n";
        return 1;
    }

    file << "SIMULAZIONE TOLC-I - DIAGNOSTICO 1\n";
    file << "Nome: " << nome << "\n";
    file << "Domande: " << domande.size() << "\n";
    file << "Corrette: " << corrette << "\n";
    file << "Errate: " << errate << "\n";
    file << "Non risposte: 0\n";
    file << fixed << setprecision(2);
    file << "Punteggio stile TOLC: " << punteggioTolc << "/" << domande.size() << "\n";
    file << "Tempo totale: " << tempoTotale << " secondi\n\n";

    file << "DETTAGLIO RISPOSTE\n";
    file << "=========================================\n";

    for (size_t i = 0; i < domande.size(); i++) {
        const Domanda& d = domande[i];
        bool giusta = risposte[i] == d.corretta;

        file << "\nDomanda " << i + 1 << " - " << d.sezione << "\n";
        file << d.testo << "\n";
        file << "Risposta data: " << risposte[i] << "\n";
        file << "Risposta corretta: " << d.corretta << "\n";
        file << "Esito: " << (giusta ? "CORRETTA" : "ERRATA") << "\n";
        file << "Tempo: " << tempi[i] << " secondi\n";

        if (!giusta) {
            file << "Spiegazione: " << d.spiegazione << "\n";
        }
    }

    file.close();

    cout << "\n=========================================\n";
    cout << "TEST TERMINATO\n";
    cout << "Corrette: " << corrette << "\n";
    cout << "Errate: " << errate << "\n";
    cout << fixed << setprecision(2);
    cout << "Punteggio stile TOLC: " << punteggioTolc;
    cout << "/" << domande.size() << "\n";
    cout << "Tempo totale: " << tempoTotale << " secondi\n";
    cout << "\nApri e inviami il file:\n";
    cout << "risultati_TOLCI_diagnostico1.txt\n";
    cout << "Si trova nella cartella del progetto o nella cartella bin/Debug.\n";

    return 0;

}
