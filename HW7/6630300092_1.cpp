//นาย เกรียงเดช เปี่ยมแจง 6630300092

#include<iostream>
using namespace std;

const int PREORDER = 1;
const int INORDER = 2;
const int POSTORDER = 3;
const int MAX_TO_MIN = 4;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};


void insertTree(struct Node* &tree,int val);
void printTree(struct Node* tree,int traversalType);

int main(){
    int choose;
    int val;
    struct Node* tree = NULL;

    do{
        cout << "========================\n"
                "          MENU            \n"
                "========================\n"
                "1) Insert\n"
                "2) Print Inorder, Preorder, Postorder, Max to min\n"
                "3) Exit\n";
        cout << "Please choose > ";
        cin >> choose;

        switch(choose){

            case 1 :
                cout<<"Enter : ";
                cin>>val;
                insertTree(tree,val);
                cout<<"Success!!\n";
                break;

            case 2 :
                cout<<"PREORDER   : ";
                printTree(tree,PREORDER);
                cout<<endl;

                cout<<"INORDER    : ";
                printTree(tree,INORDER);
                cout<<endl;

                cout<<"POSTORDER  : ";
                printTree(tree,POSTORDER);
                cout<<endl;

                cout<<"MAX_TO_MIN : ";
                printTree(tree,MAX_TO_MIN);
                cout<<endl;

                break;


        }

    }while(choose != 3);


    return 0;
}

void insertTree(struct Node* &tree,int val){
    struct Node* node = new struct Node;
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    if(tree == NULL){
        tree = node;
    }else{
        if(tree->val > val){
            insertTree(tree->left,val);
        }else if(tree->val < val){
            insertTree(tree->right,val);
        }
    }
}

void printTree(struct Node* root,int traversalType){

    if(root == NULL){
        return;
    }

    switch(traversalType)
    {
        case PREORDER :

            cout<<root->val<<" ";
            printTree(root->left,traversalType);
            printTree(root->right,traversalType);
            break;

        case INORDER :

            printTree(root->left,traversalType);
            cout<<root->val<<" ";
            printTree(root->right,traversalType);
            break;

        case POSTORDER :

            printTree(root->left,traversalType);
            printTree(root->right,traversalType);
            cout<<root->val<<" ";
            break;

        case MAX_TO_MIN :

            printTree(root->right,traversalType);
            cout<<root->val<<" ";
            printTree(root->left,traversalType);
            break;


        }
}
