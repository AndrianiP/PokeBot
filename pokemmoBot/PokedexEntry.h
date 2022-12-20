using namespace std;


// Nodes for the BST
template <class K, class Monster>
struct PokedexEntry {
    Monster monster;
    int key;
    PokedexEntry<K, Monster> *left;
    PokedexEntry<K, Monster> *right;
    PokedexEntry<K, Monster> *root = nullptr;

    PokedexEntry() {
        this->key = 0;
        this->left = NULL;
        this->right = NULL;
        this->monster = Monster();
    }

    PokedexEntry(K key, PokedexEntry<K, Monster> *left, PokedexEntry<K, Monster> *right, Monster monster) {
        this->key = key;
        this->monster = monster;
        this->left = left;
        this->right = right;
    }

    // accessors
    K getKey() {
        return this->key;
    }
    PokedexEntry<K, Monster> *getLeft() {
        return this->left;
    }
    PokedexEntry<K, Monster> *getRight() {
        return this->right;
    }
    Monster getMonster() {
        return this->monster;
    }

    // mutators
    void setKey(K key) {
        this->monster = key;
    }
    void setLeft(PokedexEntry<K, Monster>*left) {
        this->left = left;
    }
    void setRight(PokedexEntry<K, Monster>*right) {
        this->right = right;
    }

    // Methods
    PokedexEntry<K, Monster> *insert(K key, Monster monster){
        if (root == NULL) {
            root = new PokedexEntry<K, Monster>(key, NULL, NULL, monster);
        }
        else {
            PokedexEntry<K, Monster> *current = root;
            PokedexEntry<K, Monster> *parent = NULL;
            while (true) {
                parent = current;
                if (key < current->key) {
                    current = current->left;
                    if (current == NULL) {
                        parent->left = new PokedexEntry<K, Monster>(key, NULL, NULL, monster);
                        break;
                    }
                }
                else {
                    current = current->right;
                    if (current == NULL) {
                        parent->right = new PokedexEntry<K, Monster>(key, NULL, NULL, monster);
                        break;
                    }
                }
            }
        }
        return root;
    }

    PokedexEntry<K, Monster> search(K key, Monster monster) {
        if (root == NULL) {
            return NULL;
        }
        else {
            PokedexEntry<K, Monster> *current = root;
            while (current->key != key) {
                if (key < current->key) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
                if (current == NULL) {
                    return NULL;
                }
            }
            return current;
        }
    }
};






// class PokedexEntry<K, Monster>: public MonsterFactory {
//     Monster monster;
//     int key;
//     struct node<K, Monster> *left;
//     struct node<K, Monster> *right;
    

//     PokedexEntry(K key, PokedexEntry<K, Monster> *left, PokedexEntry<K, Monster> *right, Monster monster) {
//         this->key = key;
//         this->monster = monster;
//         this->left = left;
//         this->right = right;
//     }
//     public:
//         // accessors
//         K getKey() {
//             return this->key;
//         }
//         PokedexEntry<K> *getLeft() {
//             return this->left;
//         }
//         PokedexEntry<K> *getRight() {
//             return this->right;
//         }
//         Monster getMonster() {
//             return this->monster;
//         }

//         // mutators
//         void setKey(K key) {
//             this->monster = key;
//         }
//         void setLeft(PokedexEntry<K> *left) {
//             this->left = left;
//         }
//         void setRight(PokedexEntry<K> *right) {
//             this->right = right;
//         }


// };
// struct node* newPokedexEntry(int key, Monster monster) {
//     struct node* temp = new node();
//     temp->key = key;
//     temp->monster = monster;
//     temp->left = temp->right = NULL;
//     return temp;
// }

// void inorder(struct node* root) {
//     if (root != NULL) {
//         inorder(root->left);
//         cout << root->key << endl;
//         inorder(root->right);
//     }
// }

// struct node* insert(struct node* node, int key, Monster monster) {
//     /* If the tree is empty, return a new node */
//     if (node == NULL) return newPokedexEntry(key, monster);

//     /* Otherwise, recur down the tree */
//     if (key < node->key)
//         node->left = insert(node->left, key, monster);
//     else if (key > node->key)
//         node->right = insert(node->right, key, monster);

//     /* return the (unchanged) node pointer */
//     return node;
// }

// //bst search
// Node::search(struct node* root, int key) {
//     // Base Cases: root is null or key is present at root
//     if (root == NULL || root->key == key)
//         return root->monster;

//     // Key is greater than root's key
//     if (root->key < key)
//         return search(root->right, key);

//     // Key is smaller than root's key
//     return search(root->left, key);
// }