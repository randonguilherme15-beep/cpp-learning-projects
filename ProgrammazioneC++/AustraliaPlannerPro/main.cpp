#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Una struttura personalizzata che rappresenta una spesa extra
struct ExtraExpense {
    string description;
    double amount;
};

// Legge un numero intero e impedisce input non validi
int readInt(const string& prompt, int minValue) {
    while (true) {
        cout << prompt;

        string line;
        getline(cin, line);

        stringstream parser(line);
        int value;
        char extra;

        if (parser >> value && !(parser >> extra) && value >= minValue) {
            return value;
        }

        cout << "Valore non valido. Inserisci un numero intero maggiore o uguale a "
             << minValue << ".\n";
    }
}

// Legge un numero decimale e impedisce input non validi
double readDouble(const string& prompt, double minValue) {
    while (true) {
        cout << prompt;

        string line;
        getline(cin, line);

        stringstream parser(line);
        double value;
        char extra;

        if (parser >> value && !(parser >> extra) && value >= minValue) {
            return value;
        }

        cout << "Valore non valido. Usa il punto per i decimali.\n";
    }
}

// Legge un valore vero/falso
bool readBool(const string& prompt) {
    while (true) {
        cout << prompt << " (1 = si, 0 = no): ";

        string line;
        getline(cin, line);

        if (line == "1") {
            return true;
        }

        if (line == "0") {
            return false;
        }

        cout << "Inserisci soltanto 1 oppure 0.\n";
    }
}

// Calcola il totale di tutte le spese extra
double calculateExtraExpenses(const vector<ExtraExpense>& expenses) {
    double total = 0.0;

    for (const ExtraExpense& expense : expenses) {
        total += expense.amount;
    }

    return total;
}

// Chiede all'utente tutti i dati principali
void configurePlan(
    string& name,
    int& age,
    int& days,
    double& initialBudget,
    double& flightCost,
    double& dailyExpense,
    double& workHoursPerDay,
    double& hourlyPay,
    bool& hasPassport
) {
    cout << "\n--- CONFIGURAZIONE VIAGGIO ---\n";

    cout << "Nome del viaggiatore: ";
    getline(cin, name);

    age = readInt("Eta: ", 0);
    days = readInt("Giorni in Australia: ", 1);
    initialBudget = readDouble("Budget iniziale: ", 0.0);
    flightCost = readDouble("Costo del volo: ", 0.0);
    dailyExpense = readDouble("Spesa giornaliera prevista: ", 0.0);
    workHoursPerDay = readDouble("Ore lavorate al giorno: ", 0.0);
    hourlyPay = readDouble("Paga oraria prevista: ", 0.0);
    hasPassport = readBool("Hai il passaporto?");

    cout << "\nPiano configurato correttamente.\n";
}

// Aggiunge una nuova spesa extra
void addExpense(vector<ExtraExpense>& expenses) {
    ExtraExpense expense;

    cout << "\nDescrizione della spesa extra: ";
    getline(cin, expense.description);

    expense.amount = readDouble("Importo: ", 0.0);

    expenses.push_back(expense);

    cout << "Spesa aggiunta.\n";
}

// Mostra tutte le spese extra
void listExpenses(const vector<ExtraExpense>& expenses) {
    cout << "\n--- SPESE EXTRA ---\n";

    if (expenses.empty()) {
        cout << "Nessuna spesa extra registrata.\n";
        return;
    }

    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << i + 1 << ". "
             << expenses[i].description << " - "
             << fixed << setprecision(2)
             << expenses[i].amount << " euro\n";
    }

    cout << "Totale spese extra: "
         << calculateExtraExpenses(expenses)
         << " euro\n";
}

// Calcola e mostra il riepilogo completo
void printSummary(
    const string& name,
    int age,
    int days,
    double initialBudget,
    double flightCost,
    double dailyExpense,
    double workHoursPerDay,
    double hourlyPay,
    bool hasPassport,
    const vector<ExtraExpense>& expenses
) {
    const int completeWeeks = days / 7;
    const int remainingDays = days % 7;

    const double stayCost = dailyExpense * days;
    const double extraCost = calculateExtraExpenses(expenses);
    const double totalCost = flightCost + stayCost + extraCost;
    const double expectedEarnings =
        workHoursPerDay * hourlyPay * days;

    const double finalMoney =
        initialBudget + expectedEarnings - totalCost;

    cout << fixed << setprecision(2);

    cout << "\n========================================\n";
    cout << "        AUSTRALIA PLANNER REPORT\n";
    cout << "========================================\n";

    cout << "Viaggiatore: " << name << '\n';

    cout << "Durata: "
         << completeWeeks << " settimane e "
         << remainingDays << " giorni\n";

    cout << "Budget iniziale: "
         << initialBudget << " euro\n";

    cout << "Costo volo: "
         << flightCost << " euro\n";

    cout << "Costo soggiorno: "
         << stayCost << " euro\n";

    cout << "Spese extra: "
         << extraCost << " euro\n";

    cout << "Costo complessivo: "
         << totalCost << " euro\n";

    cout << "Guadagno previsto: "
         << expectedEarnings << " euro\n";

    cout << "Denaro finale: "
         << finalMoney << " euro\n\n";

    // Controllo dell'eta e condizione annidata
    if (age < 18) {
        cout << "Stato legale: non puoi organizzare il viaggio da solo.\n";
    } else {
        cout << "Stato legale: maggiorenne.\n";

        if (hasPassport) {
            cout << "Documenti: passaporto disponibile.\n";
        } else {
            cout << "Documenti: devi ancora richiedere il passaporto.\n";
        }
    }

    // Valutazione economica
    if (finalMoney >= 3000.0) {
        cout << "Valutazione economica: ottima.\n";
    } else if (finalMoney >= 1000.0) {
        cout << "Valutazione economica: buona, ma serve disciplina.\n";
    } else if (finalMoney >= 0.0) {
        cout << "Valutazione economica: margine molto limitato.\n";
    } else {
        cout << "Valutazione economica: budget insufficiente.\n";
    }

    cout << "========================================\n";
}

// Salva un rapporto in un file di testo
void saveReport(
    const string& name,
    int age,
    int days,
    double initialBudget,
    double flightCost,
    double dailyExpense,
    double workHoursPerDay,
    double hourlyPay,
    bool hasPassport,
    const vector<ExtraExpense>& expenses
) {
    ofstream file("AustraliaPlanner_Report.txt");

    if (!file) {
        cout << "Impossibile creare il file del report.\n";
        return;
    }

    const double stayCost = dailyExpense * days;
    const double extraCost = calculateExtraExpenses(expenses);
    const double totalCost = flightCost + stayCost + extraCost;
    const double expectedEarnings =
        workHoursPerDay * hourlyPay * days;

    const double finalMoney =
        initialBudget + expectedEarnings - totalCost;

    file << fixed << setprecision(2);

    file << "AUSTRALIA PLANNER REPORT\n";
    file << "Nome: " << name << '\n';
    file << "Eta: " << age << '\n';
    file << "Giorni: " << days << '\n';
    file << "Budget iniziale: "
         << initialBudget << " euro\n";

    file << "Costo totale: "
         << totalCost << " euro\n";

    file << "Guadagno previsto: "
         << expectedEarnings << " euro\n";

    file << "Denaro finale: "
         << finalMoney << " euro\n";

    file << "Passaporto: "
         << (hasPassport ? "si" : "no")
         << '\n';

    file << "\nSPESE EXTRA\n";

    for (const ExtraExpense& expense : expenses) {
        file << "- "
             << expense.description
             << ": "
             << expense.amount
             << " euro\n";
    }

    file.close();

    cout << "Report salvato nel file AustraliaPlanner_Report.txt\n";
}

// Mostra il menu principale
void printMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Configura viaggio\n";
    cout << "2. Aggiungi spesa extra\n";
    cout << "3. Mostra spese extra\n";
    cout << "4. Mostra riepilogo\n";
    cout << "5. Salva report su file\n";
    cout << "0. Esci\n";
    cout << "==========================\n";
}

int main() {
    string name;

    int age = 0;
    int days = 0;

    double initialBudget = 0.0;
    double flightCost = 0.0;
    double dailyExpense = 0.0;
    double workHoursPerDay = 0.0;
    double hourlyPay = 0.0;

    bool hasPassport = false;
    bool planConfigured = false;

    vector<ExtraExpense> expenses;

    cout << "AUSTRALIA PLANNER PRO\n";
    cout << "Un progetto-obiettivo in C++\n";

    while (true) {
        printMenu();

        const int choice =
            readInt("Scegli un'opzione: ", 0);

        switch (choice) {
            case 1:
                configurePlan(
                    name,
                    age,
                    days,
                    initialBudget,
                    flightCost,
                    dailyExpense,
                    workHoursPerDay,
                    hourlyPay,
                    hasPassport
                );

                planConfigured = true;
                break;

            case 2:
                addExpense(expenses);
                break;

            case 3:
                listExpenses(expenses);
                break;

            case 4:
                if (!planConfigured) {
                    cout << "Prima devi configurare il viaggio.\n";
                } else {
                    printSummary(
                        name,
                        age,
                        days,
                        initialBudget,
                        flightCost,
                        dailyExpense,
                        workHoursPerDay,
                        hourlyPay,
                        hasPassport,
                        expenses
                    );
                }
                break;

            case 5:
                if (!planConfigured) {
                    cout << "Prima devi configurare il viaggio.\n";
                } else {
                    saveReport(
                        name,
                        age,
                        days,
                        initialBudget,
                        flightCost,
                        dailyExpense,
                        workHoursPerDay,
                        hourlyPay,
                        hasPassport,
                        expenses
                    );
                }
                break;

            case 0:
                cout << "Programma terminato. Continua a costruire.\n";
                return 0;

            default:
                cout << "Opzione non disponibile.\n";
        }
    }
}
