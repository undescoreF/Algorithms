#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// Base class for characters
class Character {
public:
    string name;
    int health;
    int attack;

    Character(string n, int h, int a) : name(n), health(h), attack(a) {}
    virtual void display() { cout << name << " | Health: " << health << " | Attack: " << attack << endl; }
};

class Player : public Character {
public:
    int lives;
    int potions;

    Player(string n) : Character(n, 100, 15), lives(3), potions(3) {}

    void usePotion() {
        if (potions > 0) {
            health += 20;
            potions--;
            cout << name << " uses a potion! Health restored. Remaining potions: " << potions << endl;
        } else {
            cout << "No potions left!" << endl;
        }
    }
};

class Enemy : public Character {
public:
    Enemy() : Character("Temple Guardian", 80, 12) {}
};

class Boss : public Enemy {
public:
    Boss() : Enemy() { name = "Dragon Lord"; health = 150; attack = 20; }
};

class Inventory {
public:
    vector<string> items;
    void addItem(string item) { items.push_back(item); }
    void show() {
        cout << "Inventory: ";
        for (string item : items) cout << item << " ";
        cout << endl;
    }
};

class Weapon {
public:
    string type;
    int damage;
    Weapon(string t, int d) : type(t), damage(d) {}
};

class Armor {
public:
    string type;
    int defense;
    Armor(string t, int d) : type(t), defense(d) {}
};

class MagicSpell {
public:
    string name;
    int power;
    MagicSpell(string n, int p) : name(n), power(p) {}
};

class Merchant {
public:
    vector<string> goods = {"Potion", "Sword", "Shield"};
    void showGoods() {
        cout << "Merchant offers: ";
        for (string item : goods) cout << item << " ";
        cout << endl;
    }
};

class Quest {
public:
    string description;
    bool completed;
    Quest(string d) : description(d), completed(false) {}
    void complete() { completed = true; }
};

class NPC {
public:
    string name;
    string dialogue;
    NPC(string n, string d) : name(n), dialogue(d) {}
    void talk() { cout << name << ": " << dialogue << endl; }
};

class Combat {
public:
    static void start(Player& player, Enemy& enemy) {
        while (player.health > 0 && enemy.health > 0) {
            cout << "\n" << player.name << " (Lives: " << player.lives << ", Health: " << player.health << ") vs " << enemy.name << " (Health: " << enemy.health << ")\n";
            cout << "Choose an action:\n1. Attack\n2. Use Potion\n";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << player.name << " attacks!\n";
                enemy.health -= player.attack;
                if (enemy.health <= 0) {
                    cout << "You defeated the enemy!" << endl;
                    return;
                }
            } else if (choice == 2) {
                player.usePotion();
            }
            
            cout << enemy.name << " attacks!\n";
            player.health -= enemy.attack;
            if (player.health <= 0) {
                player.lives--;
                if (player.lives > 0) {
                    cout << "You lost a life! Remaining lives: " << player.lives << endl;
                    player.health = 100;
                } else {
                    cout << "Game Over! You have no lives left." << endl;
                    return;
                }
            }
        }
    }
};

class Game {
    public:
        void startGame() {
            string playerName;
            cout << "Enter your name: ";
            cin >> playerName;
            Player player(playerName);
            
            // Step 1: Introduction to the story
            cout << "Welcome to Valoria!\n";
            cout << "You stand before the temple that holds the Eye of the Dragon...\n";
            cout << "A guardian blocks your path!\n";
            
            Enemy guardian;
            Combat::start(player, guardian);
            
            // Step 2: Entering the temple
            if (player.lives > 0) {
                cout << "You defeated the guardian and can now enter the temple.\n";
                cout << "The temple doors creak open, revealing a dark and eerie corridor.\n";
                
                cout << "You hear footsteps echoing down the hall... What do you do?\n";
                cout << "1. Proceed cautiously\n2. Search the area\n";
                int choice;
                cin >> choice;
                
                if (choice == 1) {
                    cout << "You proceed cautiously, stepping over ancient stones, and enter a large room.\n";
                    cout << "Suddenly, a new enemy emerges from the shadows!\n";
                    Enemy shadowEnemy;
                    Combat::start(player, shadowEnemy);
                } else if (choice == 2) {
                    cout << "You find a hidden chest! It contains a potion and a sword.\n";
                    player.usePotion();  // Use potion found
                    Weapon sword("Sword", 20);
                    cout << "You equip the sword. Your attack is now " << sword.damage << endl;
                    cout << "You proceed cautiously and enter the next room.\n";
                    Enemy shadowEnemy;
                    Combat::start(player, shadowEnemy);
                }
            }
            
            // Step 3: The Boss Battle
            if (player.lives > 0) {
                cout << "You reach the heart of the temple. The Dragon Lord awaits!\n";
                cout << "Prepare for your final battle!\n";
                Boss dragonLord;
                Combat::start(player, dragonLord);
                
                // After the boss is defeated
                if (player.lives > 0) {
                    cout << "Congratulations, " << player.name << "! You've defeated the Dragon Lord and claimed the Eye of the Dragon!\n";
                    cout << "You have won the game!\n";
                } else {
                    cout << "You have lost all your lives... Game Over!\n";
                }
            }
        }
    };
    

int main() {
    srand(time(0));
    Game game;
    game.startGame();
    return 0;
}
