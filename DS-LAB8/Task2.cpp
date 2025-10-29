#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant
{
public:
    char name[50];
    int hp;
    int attackPower;

    Combatant() : hp(0), attackPower(0)
    {
        name[0] = '\0';
    }

    Combatant(const char *n, int h, int ap) : hp(h), attackPower(ap)
    {
        int i = 0;
        while (n[i] != '\0' && i < 49)
        {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
    }
};

class BSTNode
{
public:
    Combatant data;
    int key;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int k, Combatant c) : key(k), data(c), left(NULL), right(NULL) {}
};

class BST
{
private:
    BSTNode *root;

    BSTNode *insertHelper(BSTNode *node, int key, Combatant data)
    {
        if (node == NULL)
        {
            return new BSTNode(key, data);
        }
        if (key < node->key)
        {
            node->left = insertHelper(node->left, key, data);
        }
        else if (key > node->key)
        {
            node->right = insertHelper(node->right, key, data);
        }
        return node;
    }

    BSTNode *findMin(BSTNode *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    BSTNode *deleteHelper(BSTNode *node, int key)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (key < node->key)
        {
            node->left = deleteHelper(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = deleteHelper(node->right, key);
        }
        else
        {
            if (node->left == NULL)
            {
                BSTNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BSTNode *temp = node->left;
                delete node;
                return temp;
            }
            BSTNode *temp = findMin(node->right);
            node->key = temp->key;
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->key);
        }
        return node;
    }

    void inorderHelper(BSTNode *node)
    {
        if (node != NULL)
        {
            inorderHelper(node->left);
            cout << node->data.name << "(HP:" << node->data.hp << ") ";
            inorderHelper(node->right);
        }
    }

    void destroyTree(BSTNode *node)
    {
        if (node != NULL)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(NULL) {}

    ~BST()
    {
        destroyTree(root);
    }

    void insert(int key, Combatant data)
    {
        root = insertHelper(root, key, data);
    }

    void remove(int key)
    {
        root = deleteHelper(root, key);
    }

    BSTNode *getFrontline()
    {
        if (root == NULL)
        {
            return NULL;
        }
        return findMin(root);
    }

    bool isEmpty()
    {
        return root == NULL;
    }

    void display()
    {
        if (root == NULL)
        {
            cout << "None";
        }
        else
        {
            inorderHelper(root);
        }
    }
};

class Game
{
private:
    BST playerTeam;
    BST enemyTeam;
    int round;

public:
    Game() : round(0)
    {
        srand(time(0));
    }

    void initializeTeams()
    {
        playerTeam.insert(1, Combatant("Gear 5 Luffy", 100, 25));
        playerTeam.insert(2, Combatant("Ultra Instinct Goku", 1000, 300));
        playerTeam.insert(3, Combatant("Baryon Mode Naruto", 95, 23));
        playerTeam.insert(4, Combatant("Kurosaki", 100, 43));
        playerTeam.insert(5, Combatant("Gojo Satoru", 105, 30));

        enemyTeam.insert(1, Combatant("Kaido",110, 20));
        enemyTeam.insert(2, Combatant("Golden Frieza", 750, 220));
        enemyTeam.insert(3, Combatant("Isshiki", 100, 24));
        enemyTeam.insert(4, Combatant("Yhwach", 120, 25));
        enemyTeam.insert(5, Combatant("Ryomen Sukuna", 110, 22));
    }

    void displayStatus()
    {
        cout << "Round " << round << endl;
        cout << "Heroes: ";
        playerTeam.display();
        cout << endl;
        cout << "Enemies: ";
        enemyTeam.display();
        cout << endl;
    }

    void attack(BST &attackerTeam, BST &defenderTeam, const char *attackerType, const char *defenderType)
    {
        BSTNode *attacker = attackerTeam.getFrontline();
        BSTNode *defender = defenderTeam.getFrontline();

        if (attacker == NULL || defender == NULL)
        {
            return;
        }

        int damage = attacker->data.attackPower + (rand() % 5);

        cout << attackerType << " " << attacker->data.name << " attacks " << defenderType << " " << defender->data.name << " for " << damage << " damage!" << endl;

        defender->data.hp -= damage;

        cout << defender->data.name << " HP: " << (defender->data.hp > 0 ? defender->data.hp : 0) << endl;

        if (defender->data.hp <= 0)
        {
            cout << defender->data.name << " has been defeated!" << endl;
            defenderTeam.remove(defender->key);
        }
    }

    void startBattle()
    {
        initializeTeams();

        cout << "BattleQuest: BST Arena" << endl;

        while (!playerTeam.isEmpty() && !enemyTeam.isEmpty())
        {
            round++;
            displayStatus();

            cout << endl << "Player Turn" << endl;
            attack(playerTeam, enemyTeam, "Hero", "Enemy");

            if (enemyTeam.isEmpty())
            {
                break;
            }

            cout << endl << "Enemy Turn" << endl;
            attack(enemyTeam, playerTeam, "Enemy", "Hero");
        }

        cout << endl << "Battle End" << endl;
        if (playerTeam.isEmpty())
        {
            cout << "Defeat! Enemy team wins!" << endl;
        }
        else
        {
            cout << "Victory! Player team wins!" << endl;
        }
    }
};

int main()
{
    Game game;
    game.startBattle();
    return 0;
}
