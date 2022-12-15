#include "Monster.h"

using namespace std;

class PokedexEntry<K, Monster>: public MonsterFactory {
    Monster monster;
    int key;
    struct node<K, Monster> *left;
    struct node<K, Monster> *right;

    PokedexEntry(K key, PokedexEntry<K, Monster> *left, PokedexEntry<K, Monster> *right, Monster monster) {
        this->key = key;
        this->monster = monster;
        this->left = left;
        this->right = right;
    }
    public:
        // accessors
        K getKey() {
            return this->key;
        }
        PokedexEntry<K> *getLeft() {
            return this->left;
        }
        PokedexEntry<K> *getRight() {
            return this->right;
        }
        Monster getMonster() {
            return this->monster;
        }

        // mutators
        void setKey(K key) {
            this->monster = key;
        }
        void setLeft(PokedexEntry<K> *left) {
            this->left = left;
        }
        void setRight(PokedexEntry<K> *right) {
            this->right = right;
        }


    struct node *newPokedexEntry(int key, Monster monster) {
        struct node *temp = new node();
        temp->key = key;
        temp->monster = monster;
        temp->left = temp->right = NULL;
        return temp;
    }

    void inorder(struct node *root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->key << endl;
            inorder(root->right);
        }
    }

    struct node* insert(struct node* node, int key, Monster monster) {
        /* If the tree is empty, return a new node */
        if (node == NULL) return newPokedexEntry(key, monster);

        /* Otherwise, recur down the tree */
        if (key < node->key)
            node->left = insert(node->left, key, monster);
        else if (key > node->key)
            node->right = insert(node->right, key, monster);

        /* return the (unchanged) node pointer */
        return node;
    }

    //bst search
    Monster search(struct node* root, int key) {
        // Base Cases: root is null or key is present at root
        if (root == NULL || root->key == key)
            return root->monster;

        // Key is greater than root's key
        if (root->key < key)
            return search(root->right, key);

        // Key is smaller than root's key
        return search(root->left, key);
    }
};
