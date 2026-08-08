#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Legge un numero e impedisce input non validi.
int readInt(const string& prompt, int minimum, int maximum) {
    while (true) {
        cout << prompt;

        string line;
        getline(cin, line);

        stringstream parser(line);
        int value;
        char extraCharacter;

        if (parser >> value &&
            !(parser >> extraCharacter) &&
            value >= minimum &&
            value <= maximum) {
            return value;
        }

        cout << "Input non valido. Inserisci un numero tra "
             << minimum << " e " << maximum << ".\n";
    }
}

// Dati e comportamento del giocatore.
struct Player {
    string name;

    int level = 1;
    int experience = 0;
    int experienceNeeded = 50;

    int maximumHealth = 100;
    int health = 100;
    int attack = 12;

    int gold = 30;
    int potions = 2;

    bool isAlive() const {
        return health > 0;
    }

    int generateDamage(mt19937& generator) const {
        uniform_int_distribution<int> damageDistribution(
            max(1, attack - 3),
            attack + 3
        );

        return damageDistribution(generator);
    }

    void heal() {
        if (potions <= 0) {
            cout << "Non possiedi pozioni.\n";
            return;
        }

        if (health == maximumHealth) {
            cout << "Hai gia tutta la salute.\n";
            return;
        }

        const int recoveredHealth = 35;

        health = min(maximumHealth, health + recoveredHealth);
        potions--;

        cout << "Hai usato una pozione.\n";
        cout << "Salute attuale: "
             << health << "/" << maximumHealth << '\n';
    }

    void gainExperience(int amount) {
        experience += amount;

        cout << "Hai ottenuto "
             << amount << " punti esperienza.\n";

        while (experience >= experienceNeeded) {
            experience -= experienceNeeded;
            level++;

            experienceNeeded += 30;
            maximumHealth += 15;
            health = maximumHealth;
            attack += 3;

            cout << "\n*** LEVEL UP! ***\n";
            cout << "Sei arrivato al livello " << level << ".\n";
            cout << "Salute massima aumentata.\n";
            cout << "Attacco aumentato.\n";
        }
    }
};

// Dati di un nemico.
struct Enemy {
    string name;

    int maximumHealth;
    int health;
    int attack;

    int goldReward;
    int experienceReward;

    bool isAlive() const {
        return health > 0;
    }

    int generateDamage(mt19937& generator) const {
        uniform_int_distribution<int> damageDistribution(
            max(1, attack - 2),
            attack + 2
        );

        return damageDistribution(generator);
    }
};

class Game {
private:
    Player player;
    mt19937 randomGenerator;

public:
    Game()
        : randomGenerator(random_device{}()) {
    }

    void start() {
        while (true) {
            cout << "\n=================================\n";
            cout << "           NEON ARENA\n";
            cout << "=================================\n";
            cout << "1. Nuova partita\n";
            cout << "2. Carica partita\n";
            cout << "0. Esci\n";

            const int choice =
                readInt("Scegli: ", 0, 2);

            if (choice == 1) {
                createNewGame();
                gameLoop();
            } else if (choice == 2) {
                if (loadGame()) {
                    gameLoop();
                }
            } else {
                cout << "Programma terminato.\n";
                return;
            }
        }
    }

private:
    void createNewGame() {
        player = Player{};

        cout << "\nInserisci il nome del combattente: ";
        getline(cin, player.name);

        if (player.name.empty()) {
            player.name = "Combattente";
        }

        cout << "\nBenvenuto nella Neon Arena, "
             << player.name << "!\n";
    }

    void gameLoop() {
        while (player.isAlive()) {
            cout << "\n=========== MENU ===========\n";
            cout << "1. Esplora l'arena\n";
            cout << "2. Visualizza statistiche\n";
            cout << "3. Visita il negozio\n";
            cout << "4. Salva partita\n";
            cout << "0. Torna al menu principale\n";

            const int choice =
                readInt("Scegli un'azione: ", 0, 4);

            switch (choice) {
                case 1:
                    explore();
                    break;

                case 2:
                    showStatistics();
                    break;

                case 3:
                    openShop();
                    break;

                case 4:
                    saveGame();
                    break;

                case 0:
                    return;
            }
        }

        cout << "\nSei stato sconfitto.\n";
        cout << "La Neon Arena ha avuto la meglio.\n";
    }

    Enemy createEnemy() {
        const vector<string> enemyNames = {
            "Drone da combattimento",
            "Predatore sintetico",
            "Mercenario cyborg",
            "Guardiano al plasma",
            "Bestia mutante"
        };

        uniform_int_distribution<int> nameDistribution(
            0,
            static_cast<int>(enemyNames.size()) - 1
        );

        Enemy enemy;

        enemy.name = enemyNames[nameDistribution(randomGenerator)];

        enemy.maximumHealth =
            35 + player.level * 14;

        enemy.health = enemy.maximumHealth;

        enemy.attack =
            7 + player.level * 3;

        enemy.goldReward =
            12 + player.level * 7;

        enemy.experienceReward =
            20 + player.level * 10;

        // Possibilita di incontrare un boss.
        uniform_int_distribution<int> bossChance(1, 100);

        if (player.level >= 3 &&
            bossChance(randomGenerator) <= 15) {
            enemy.name = "SENTINELLA OMEGA";
            enemy.maximumHealth *= 2;
            enemy.health = enemy.maximumHealth;
            enemy.attack += 6;
            enemy.goldReward *= 3;
            enemy.experienceReward *= 2;
        }

        return enemy;
    }

    void explore() {
        uniform_int_distribution<int> eventDistribution(1, 100);

        const int event = eventDistribution(randomGenerator);

        cout << "\nTi addentri in una nuova zona dell'arena...\n";

        if (event <= 65) {
            Enemy enemy = createEnemy();
            fight(enemy);
        } else if (event <= 82) {
            uniform_int_distribution<int> goldDistribution(10, 35);

            const int foundGold =
                goldDistribution(randomGenerator);

            player.gold += foundGold;

            cout << "Hai trovato una cassa con "
                 << foundGold << " crediti.\n";
        } else if (event <= 94) {
            const int healing = 25;

            player.health =
                min(player.maximumHealth,
                    player.health + healing);

            cout << "Hai trovato una stazione medica.\n";
            cout << "Salute: "
                 << player.health << "/"
                 << player.maximumHealth << '\n';
        } else {
            uniform_int_distribution<int> trapDamage(8, 20);

            const int damage =
                trapDamage(randomGenerator);

            player.health -= damage;

            cout << "Sei caduto in una trappola!\n";
            cout << "Hai subito "
                 << damage << " danni.\n";
        }
    }

    void fight(Enemy enemy) {
        cout << "\n*** NEMICO INCONTRATO ***\n";
        cout << enemy.name << '\n';

        while (player.isAlive() && enemy.isAlive()) {
            cout << "\n" << player.name
                 << ": " << player.health
                 << "/" << player.maximumHealth
                 << " HP\n";

            cout << enemy.name
                 << ": " << enemy.health
                 << "/" << enemy.maximumHealth
                 << " HP\n";

            cout << "\n1. Attacca\n";
            cout << "2. Usa pozione\n";
            cout << "3. Tenta la fuga\n";

            const int choice =
                readInt("Azione: ", 1, 3);

            bool escaped = false;

            if (choice == 1) {
                const int damage =
                    player.generateDamage(randomGenerator);

                enemy.health -= damage;

                cout << "Infliggi "
                     << damage << " danni.\n";
            } else if (choice == 2) {
                player.heal();
            } else {
                uniform_int_distribution<int> escapeChance(1, 100);

                if (escapeChance(randomGenerator) <= 40) {
                    cout << "Sei riuscito a fuggire.\n";
                    escaped = true;
                } else {
                    cout << "Fuga fallita!\n";
                }
            }

            if (escaped) {
                return;
            }

            if (!enemy.isAlive()) {
                cout << "\nHai sconfitto "
                     << enemy.name << "!\n";

                player.gold += enemy.goldReward;

                cout << "Ricompensa: "
                     << enemy.goldReward
                     << " crediti.\n";

                player.gainExperience(
                    enemy.experienceReward
                );

                return;
            }

            const int enemyDamage =
                enemy.generateDamage(randomGenerator);

            player.health -= enemyDamage;

            cout << enemy.name
                 << " ti infligge "
                 << enemyDamage
                 << " danni.\n";
        }
    }

    void showStatistics() const {
        cout << "\n========= STATISTICHE =========\n";
        cout << "Nome: " << player.name << '\n';
        cout << "Livello: " << player.level << '\n';

        cout << "Esperienza: "
             << player.experience << "/"
             << player.experienceNeeded << '\n';

        cout << "Salute: "
             << player.health << "/"
             << player.maximumHealth << '\n';

        cout << "Attacco: "
             << player.attack << '\n';

        cout << "Crediti: "
             << player.gold << '\n';

        cout << "Pozioni: "
             << player.potions << '\n';
    }

    void openShop() {
        while (true) {
            cout << "\n========== NEGOZIO ==========\n";
            cout << "Crediti disponibili: "
                 << player.gold << '\n';

            cout << "1. Pozione - 15 crediti\n";
            cout << "2. Potenzia arma - 50 crediti\n";
            cout << "3. Potenzia armatura - 60 crediti\n";
            cout << "0. Esci dal negozio\n";

            const int choice =
                readInt("Acquisto: ", 0, 3);

            if (choice == 0) {
                return;
            }

            if (choice == 1) {
                if (player.gold >= 15) {
                    player.gold -= 15;
                    player.potions++;

                    cout << "Pozione acquistata.\n";
                } else {
                    cout << "Crediti insufficienti.\n";
                }
            } else if (choice == 2) {
                if (player.gold >= 50) {
                    player.gold -= 50;
                    player.attack += 3;

                    cout << "Arma potenziata.\n";
                } else {
                    cout << "Crediti insufficienti.\n";
                }
            } else if (choice == 3) {
                if (player.gold >= 60) {
                    player.gold -= 60;
                    player.maximumHealth += 15;
                    player.health += 15;

                    cout << "Armatura potenziata.\n";
                } else {
                    cout << "Crediti insufficienti.\n";
                }
            }
        }
    }

    void saveGame() const {
        ofstream file("neon_arena_save.txt");

        if (!file) {
            cout << "Errore durante il salvataggio.\n";
            return;
        }

        file << player.name << '\n';

        file << player.level << ' '
             << player.experience << ' '
             << player.experienceNeeded << ' '
             << player.maximumHealth << ' '
             << player.health << ' '
             << player.attack << ' '
             << player.gold << ' '
             << player.potions << '\n';

        cout << "Partita salvata correttamente.\n";
    }

    bool loadGame() {
        ifstream file("neon_arena_save.txt");

        if (!file) {
            cout << "Nessun salvataggio trovato.\n";
            return false;
        }

        getline(file, player.name);

        file >> player.level
             >> player.experience
             >> player.experienceNeeded
             >> player.maximumHealth
             >> player.health
             >> player.attack
             >> player.gold
             >> player.potions;

        if (!file) {
            cout << "Salvataggio danneggiato.\n";
            return false;
        }

        cout << "Partita caricata.\n";
        cout << "Bentornato, "
             << player.name << "!\n";

        return true;
    }
};

int main() {
    Game game;
    game.start();

    return 0;
}
