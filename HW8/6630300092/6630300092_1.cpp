#include<iostream>
using namespace std;

const int PREORDER = 0;
const int INORDER = 1;
const int POSTORDER = 2;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};


void insertTree(struct Node* &root,int val);
void deleteNode(struct Node* &root,int val);
void printTree(struct Node* root,int tervarsalType);
void printLeafNode(struct Node* root);
void printNonLeafNode(struct Node* root);
struct Node* getMinNode(struct Node* root);
struct Node* getMaxNode(struct Node* root);

int main(){
    int choose;
    int val;
    struct Node* tree = NULL;

    do{
        cout << "========================\n"
                "          MENU            \n"
                "========================\n"
                "1) Insert\n"
                "2) Delete\n"
                "3) Print Inorder,Max,Min\n"
                "4) Print leaf node,non leaf node\n"
                "5) Exit\n";
        cout << "Please choose > ";
        cin >> choose;

        switch(choose){

            case 1 :
                cout<<"Enter : ";
                cin>>val;
                insertTree(tree,val);

                break;

            case 3 :
                cout<<"INORDER : ";
                printTree(tree,INORDER);
                cout<<endl;

                cout<<"Max     : "<<getMaxNode(tree)->val;
                cout<<endl;

                cout<<"Min     : "<<getMinNode(tree)->val;
                cout<<endl;

                break;
            case 2 :
                cout<<"Delete : ";
                cin>>val;
                deleteNode(tree,val);
                cout<<"\nData in tree = ";
                printTree(tree,INORDER);
                cout<<endl;
                break;
            case 4 :
                cout<<"Leaf node : ";
                printLeafNode(tree);
                cout<<endl;

                cout<<"Non leaf node : ";
                printNonLeafNode(tree);
                cout<<endl;

                break;



        }

    }while(choose != 5);
    return 0;
}

void insertTree(struct Node* &root,int val){

    struct Node* newNode = new struct Node;
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;


    if(root == NULL){
        root = newNode;
        cout<<"Success!!\n";
    }

    else{

        if(val < root->val){
            insertTree(root->left,val);
        }else if(val > root->val){
            insertTree(root->right,val);
        }

    }

}


void printTree(struct Node* root,int terversalType){

    if(root == NULL){
        return;
    }


    switch(terversalType){

        case PREORDER:

            cout<<root->val<<" ";
            printTree(root->left,terversalType);
            printTree(root->right,terversalType);
            break;

        case INORDER:

            printTree(root->left,terversalType);
            cout<<root->val<<" ";
            printTree(root->right,terversalType);
            break;

        case POSTORDER:

            cout<<root->val<<" ";
            printTree(root->left,terversalType);
            printTree(root->right,terversalType);
            break;

    }
}

struct Node* getMinNode(struct Node* root){

    if(root == NULL)
        return NULL;

    if(root->left != NULL)
        return getMinNode(root->left);
    else
        return root;
};

struct Node* getMaxNode(struct Node* root){

    if(root == NULL)
        return NULL;

    if(root->right != NULL)
        return getMaxNode(root->right);
    else
        return root;

};

void printLeafNode(struct Node* root){

    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
        cout<<root->val<<" ";
    else{

        printLeafNode(root->left);
        printLeafNode(root->right);
    }
}

void printNonLeafNode(struct Node* root){

    if(root == NULL)
        return;
    else if(root->left == NULL && root->right == NULL)
        return;

    cout<<root->val<<" ";
    printNonLeafNode(root->left);
    printNonLeafNode(root->right);

}

void deleteNode(struct Node* &root,int val){

    if(root == NULL)
        return;


    if(val < root->val)
        deleteNode(root->left,val);
    else if(val > root->val)
        deleteNode(root->right,val);
    else{

        if(root->left == NULL && root->right == NULL){
            delete(root);
            root = NULL;
            cout<<"Success!";
        }else if(root->left != NULL && root->right != NULL){
            struct Node* temp = getMinNode(root->right);
            root->val = temp->val;
            deleteNode(root->right,temp->val);

        }else if(root->left != NULL){
            struct Node* temp = root;
            root = root->left;
            delete(temp);
            cout<<"Success!";

        }else if(root->right != NULL){
            struct Node* temp = root;
            root = root->right;
            delete(temp);
            cout<<"Success!";

        }

    }

}
