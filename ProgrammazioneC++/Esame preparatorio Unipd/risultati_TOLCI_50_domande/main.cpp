



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <cctype>
#include <limits>

using namespace std;

struct Domanda {
    string sezione;
    string testo;
    string A, B, C, D;
    char corretta;
    string spiegazione;
};

char leggiRisposta(int numero) {
    char r;
    while (true) {
        cout << "\nRisposta " << numero << " (A/B/C/D oppure X per vuota): ";
        cin >> r;
        r = static_cast<char>(toupper(static_cast<unsigned char>(r)));

        if (r == 'A' || r == 'B' || r == 'C' || r == 'D' || r == 'X')
            return r;

        cout << "Valore non valido.\n";
    }
}

int main() {
    vector<Domanda> q = {
        {"Matematica","Quanto vale 3/4 + 1/8?","1/2","5/8","7/8","1",'C',"3/4 = 6/8, quindi 6/8 + 1/8 = 7/8."},
        {"Matematica","Risolvi: 2x + 5 = 17","5","6","7","8",'B',"2x = 12, quindi x = 6."},
        {"Matematica","Qual e' il 25% di 80?","15","18","20","25",'C',"25% di 80 = 20."},
        {"Matematica","Semplifica 48/64.","2/3","3/4","4/5","6/8",'B',"Dividendo entrambi per 16 si ottiene 3/4."},
        {"Matematica","Quanto vale 2^5?","10","16","25","32",'D',"2^5 = 32."},
        {"Matematica","Quanto vale 3^2 * 3^4?","3^6","9^6","3^8","6^3",'A',"Stessa base: si sommano gli esponenti."},
        {"Matematica","Quanto vale (2^3)^2?","2^5","2^6","4^5","8^4",'B',"Potenza di potenza: 3*2 = 6."},
        {"Matematica","Quale frazione corrisponde a 0,375?","3/8","3/5","5/8","375/10",'A',"0,375 = 375/1000 = 3/8."},
        {"Matematica","Quale numero e' maggiore?","3/5","5/8","Uguali","Impossibile saperlo",'B',"3/5 = 0,6; 5/8 = 0,625."},
        {"Matematica","Risolvi: 5x - 10 = 25","5","6","7","8",'C',"5x = 35, quindi x = 7."},

        {"Matematica","Se x = 3, quanto vale 2x^2 + 1?","13","18","19","21",'C',"2*9+1 = 19."},
        {"Matematica","Dominio di 1/(x-4)?","Tutti i reali","x > 4","x diverso da 4","x = 4",'C',"Il denominatore non puo' essere zero."},
        {"Matematica","Radice quadrata di 144?","10","11","12","14",'C',"12*12 = 144."},
        {"Matematica","Due numeri consecutivi hanno prodotto 56. Quali?","6 e 7","7 e 8","8 e 9","5 e 6",'B',"7*8 = 56."},
        {"Matematica","MCD tra 36 e 48?","6","8","12","16",'C',"Il massimo divisore comune e' 12."},
        {"Matematica","mcm tra 6 e 8?","12","18","24","48",'C',"Il primo multiplo comune e' 24."},
        {"Matematica","7/20 in forma decimale?","0,07","0,25","0,35","0,70",'C',"7/20 = 35/100 = 0,35."},
        {"Matematica","Se 3/4 = x/20, quanto vale x?","12","15","16","18",'B',"Moltiplicando per 5: x = 15."},
        {"Matematica","Quanto vale 15 - 3*4?","48","3","12","27",'B',"Prima 3*4 = 12, poi 15-12 = 3."},
        {"Matematica","Quanto vale |-7|?","-7","0","7","14",'C',"Il valore assoluto e' 7."},

        {"Logica","Tutti i programmatori usano un computer. Marco usa un computer. Marco e' sicuramente programmatore?","Si","No","Solo con Linux","Solo se lavora",'B',"Usare un computer non implica essere programmatore."},
        {"Logica","Completa: 2, 4, 8, 16, ...","18","24","30","32",'D',"Ogni numero raddoppia."},
        {"Logica","Completa: 1, 4, 9, 16, ...","20","24","25","32",'C',"Sono quadrati perfetti."},
        {"Logica","Tutti gli A sono B e nessun B e' C. Allora:","Nessun A e' C","Tutti i C sono A","Alcuni A sono C","Tutti i B sono A",'A',"A e' contenuto in B e B non contiene C."},
        {"Logica","Quale elemento non appartiene al gruppo?","Quadrato","Triangolo","Cerchio","Cubo",'D',"Il cubo e' tridimensionale."},
        {"Logica","Completa: A, C, E, G, ...","H","I","J","K",'B',"Si salta una lettera ogni volta."},
        {"Logica","Anna e' piu' alta di Luca; Luca piu' alto di Marco. Chi e' il piu' basso?","Anna","Luca","Marco","Non si sa",'C',"Anna > Luca > Marco."},
        {"Logica","Se oggi e' lunedi', che giorno sara' tra 10 giorni?","Mercoledi","Giovedi","Venerdi","Sabato",'B',"10 giorni = 7+3, quindi giovedi."},
        {"Logica","Completa: 3, 6, 12, 24, ...","27","36","42","48",'D',"Ogni numero raddoppia."},
        {"Logica","Nessun pesce e' mammifero. Il delfino e' mammifero. Quindi:","E' un pesce","Non e' un pesce","Tutti i mammiferi sono delfini","Non si sa",'B',"Un mammifero non puo' essere un pesce."},

        {"Scienze","Unita' SI della forza?","Joule","Watt","Newton","Pascal",'C',"La forza si misura in newton."},
        {"Scienze","Un'auto percorre 180 km in 3 ore. Velocita' media?","50 km/h","60 km/h","70 km/h","90 km/h",'B',"180/3 = 60 km/h."},
        {"Scienze","Quale organo pompa il sangue?","Polmone","Fegato","Cuore","Rene",'C',"Il cuore pompa il sangue."},
        {"Scienze","Gas piu' abbondante nell'atmosfera?","Ossigeno","Azoto","CO2","Idrogeno",'B',"L'azoto e' circa il 78%."},
        {"Scienze","A pressione normale l'acqua bolle a:","0 C","50 C","100 C","212 C",'C',"Bolle a 100 C."},
        {"Scienze","Particella con carica negativa?","Protone","Neutrone","Elettrone","Nucleo",'C',"L'elettrone e' negativo."},
        {"Scienze","Formula della densita'?","massa*volume","massa/volume","volume/massa","massa+volume",'B',"Densita' = massa/volume."},
        {"Scienze","Energia di un corpo in movimento?","Chimica","Cinetica","Nucleare","Potenziale",'B',"E' energia cinetica."},
        {"Scienze","Pianeta piu' vicino al Sole?","Venere","Terra","Marte","Mercurio",'D',"Mercurio e' il piu' vicino."},
        {"Scienze","Formula H2O?","Ossigeno","Acqua","Idrogeno","Sale",'B',"H2O e' acqua."},

        {"Comprensione","Contrario di 'espandere'?","Allargare","Ridurre","Crescere","Aumentare",'B',"Il contrario e' ridurre."},
        {"Comprensione","'Benche' fosse stanco, continuo'': 'benche'' introduce:","Causa","Conseguenza","Concessione","Fine",'C',"E' una proposizione concessiva."},
        {"Comprensione","Sinonimo di 'rapido'?","Lento","Veloce","Debole","Difficile",'B',"Rapido significa veloce."},
        {"Comprensione","Quale frase e' corretta?","O visto Marco","Ho visto Marco","A visto Marco","Ha visto a Marco",'B',"L'ausiliare corretto e' 'ho'."},
        {"Comprensione","'Ambiguo' significa:","Chiarissimo","Con un solo significato","Interpretabile in piu' modi","Sempre falso",'C',"Ambiguo significa non univoco."},
        {"Comprensione","Completa: 'Il risultato dipende ___ metodo utilizzato'.","dal","dello","al","nel",'A',"Si dice dipendere da: dal metodo."},
        {"Comprensione","Congiunzione avversativa?","Perche","Quindi","Ma","Quando",'C',"'Ma' indica opposizione."},
        {"Comprensione","In 'Luca legge un libro', il soggetto e':","Legge","Libro","Luca","Un",'C',"Il soggetto e' Luca."},
        {"Comprensione","Quale frase esprime una causa?","Studio affinche' passi","Non esco perche' piove","Esco nonostante piova","Piove, quindi resto",'B',"'Perche' piove' esprime la causa."},
        {"Comprensione","Quale forma e' corretta?","Qual'e'","Qual e'","Quale'","Quall'e'",'B',"'Qual e'' si scrive senza apostrofo."}
    };

    vector<char> risposte;
    cout << "========================================\n";
    cout << "SIMULAZIONE TOLC-I - 50 DOMANDE\n";
    cout << "+1 corretta, -0.25 errata, 0 vuota\n";
    cout << "========================================\n";
    cout << "Premi INVIO per iniziare...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    auto start = chrono::steady_clock::now();

    for (size_t i = 0; i < q.size(); ++i) {
        cout << "\n\nDomanda " << i+1 << "/50 - " << q[i].sezione << "\n";
        cout << q[i].testo << "\n";
        cout << "A) " << q[i].A << "\n";
        cout << "B) " << q[i].B << "\n";
        cout << "C) " << q[i].C << "\n";
        cout << "D) " << q[i].D << "\n";
        risposte.push_back(leggiRisposta((int)i+1));
    }

    auto end = chrono::steady_clock::now();
    long long sec = chrono::duration_cast<chrono::seconds>(end-start).count();

    int corrette=0, errate=0, vuote=0;
    double punti=0;

    ofstream out("risultati_TOLCI_50_domande.txt");
    out << fixed << setprecision(2);

    for (size_t i=0; i<q.size(); ++i) {
        if (risposte[i]=='X') vuote++;
        else if (risposte[i]==q[i].corretta) { corrette++; punti+=1; }
        else { errate++; punti-=0.25; }
    }

    out << "SIMULAZIONE TOLC-I - 50 DOMANDE\n";
    out << "Corrette: " << corrette << "\n";
    out << "Errate: " << errate << "\n";
    out << "Vuote: " << vuote << "\n";
    out << "Punteggio: " << punti << "/50\n";
    out << "Tempo totale: " << sec << " secondi\n";
    out << "Tempo medio: " << (double)sec/q.size() << " secondi per domanda\n\n";

    out << "DETTAGLIO RISPOSTE\n";
    out << "========================================\n";

    for (size_t i=0; i<q.size(); ++i) {
        out << "\nDomanda " << i+1 << " - " << q[i].sezione << "\n";
        out << q[i].testo << "\n";
        out << "Tua risposta: " << risposte[i] << "\n";
        out << "Corretta: " << q[i].corretta << "\n";
        if (risposte[i]=='X') out << "Esito: VUOTA\n";
        else if (risposte[i]==q[i].corretta) out << "Esito: CORRETTA\n";
        else out << "Esito: ERRATA\n";
        out << "Spiegazione: " << q[i].spiegazione << "\n";
    }

    out.close();

    cout << "\n\nSIMULAZIONE TERMINATA\n";
    cout << "Corrette: " << corrette << "\n";
    cout << "Errate: " << errate << "\n";
    cout << "Vuote: " << vuote << "\n";
    cout << fixed << setprecision(2);
    cout << "Punteggio: " << punti << "/50\n";
    cout << "File creato: risultati_TOLCI_50_domande.txt\n";

    return 0;
}
