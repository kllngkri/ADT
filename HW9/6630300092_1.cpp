#include<iostream>
using namespace std;

struct Node{
    int height;
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* insertTree(struct Node* tree, int value);
void printPreorder(struct Node* tree);
struct Node* getMinNode(struct Node* tree);
struct Node* getMaxNode(struct Node* tree);
void printLeafNode(struct Node* tree);

struct Node* rotateLeft(struct Node* root);
struct Node* rotateRight(struct Node* root);

struct Node* dRotateLeft(struct Node* root);
struct Node* dRotateRight(struct Node* root);

int fheight(struct Node* p);

int main(){
    int choose, value;
    struct Node* tree = NULL;

    do {
        cout << "========MENU======\n"
             << "1) Insert\n"
             << "2) Print Inorder, Min, Max\n"
             << "3) Print leaf nodes (inorder)\n"
             << "4) Exit\n";

        cout << "Please choose > ";
        cin >> choose;

        switch(choose) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree = insertTree(tree, value);
                break;
            case 2:
                cout << "Inorder: ";
                printPreorder(tree);
                cout << "\nMin value: " << (getMinNode(tree) ? getMinNode(tree)->value : -1);
                cout << "\nMax value: " << (getMaxNode(tree) ? getMaxNode(tree)->value : -1);
                cout << endl;
                break;
            case 3:
                cout << "Leaf nodes: ";
                printLeafNode(tree);
                cout << endl;
                break;
        }
    } while (choose != 4);
}

struct Node* insertTree(struct Node* tree, int value) {
    if (tree == NULL) {
        tree = new struct Node;
        tree->value = value;
        tree->left = NULL;
        tree->right = NULL;
        tree->height = 0;
    } else {
        if (value < tree->value) {
            tree->left = insertTree(tree->left, value);
            if (fheight(tree->left) - fheight(tree->right) == 2) {
                if (value < tree->left->value) {
                    tree = rotateRight(tree);
                } else {
                    tree = dRotateRight(tree);
                }
            }
        } else if (value > tree->value) {
            tree->right = insertTree(tree->right, value);
            if (fheight(tree->right) - fheight(tree->left) == 2) {
                if (value > tree->right->value) {
                    tree = rotateLeft(tree);
                } else {
                    tree = dRotateLeft(tree);
                }
            }
        }
    }

    // Update height
    tree->height = max(fheight(tree->left), fheight(tree->right)) + 1;

    return tree;
}

void printPreorder(struct Node* tree) {
    if (tree == NULL) return;

    printPreorder(tree->left);
    cout << tree->value << " ";
    printPreorder(tree->right);
}

struct Node* getMinNode(struct Node* tree) {
    if (tree == NULL) return NULL;
    if (tree->left == NULL) return tree;
    return getMinNode(tree->left);
}

struct Node* getMaxNode(struct Node* tree) {
    if (tree == NULL) return NULL;
    if (tree->right == NULL) return tree;
    return getMaxNode(tree->right);
}

void printLeafNode(struct Node* tree) {
    if (tree == NULL) return;
    if (tree->left == NULL && tree->right == NULL) {
        cout << tree->value << " ";
    } else {
        printLeafNode(tree->left);
        printLeafNode(tree->right);
    }
}

struct Node* rotateLeft(struct Node* root) {
    struct Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    root->height = max(fheight(root->left), fheight(root->right)) + 1;
    newRoot->height = max(fheight(newRoot->left), fheight(newRoot->right)) + 1;
    return newRoot;
}

struct Node* rotateRight(struct Node* root) {
    struct Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    root->height = max(fheight(root->left), fheight(root->right)) + 1;
    newRoot->height = max(fheight(newRoot->left), fheight(newRoot->right)) + 1;
    return newRoot;
}

struct Node* dRotateLeft(struct Node* root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

struct Node* dRotateRight(struct Node* root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

int fheight(struct Node* p) {
    if (p == NULL) return -1;
    return p->height;
}
