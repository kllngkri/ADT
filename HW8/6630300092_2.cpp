#include<iostream>
using namespace std;

struct record{

    char val;
    struct record* left;
    struct record* right;
};

struct Node{

    struct record* val;
    struct Node* next;
};




void push(struct Node* &s,struct record* tree);
bool isEmpty(struct Node* node);
void pop(struct Node* &s);
struct record* top(struct Node* s);

struct record* getTree(char val);
void printInfix(struct record* tree);

bool isOperator(char input);



int main(){
    string postFix;
    struct Node* s = NULL;

    cout<<"Input postfix : ";
    cin>>postFix;

    for(char input : postFix){
        if(input == '.')break;

        if(isOperator(input)){
            struct record* root = getTree(input);
            root->right = top(s);
            pop(s);

            root->left = top(s);
            pop(s);

            push(s,root);
        }else{
            push(s,getTree(input));
        }
    }

    cout<<"Infix : ";
    printInfix(top(s));



    return 0;
}

struct record* getTree(char val){

    struct record* node = new struct record;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void push(struct Node* &s,struct record* tree){

    struct Node* newNode = new struct Node;
    newNode->val = tree;
    newNode->next = NULL;

    if(s == NULL){
        s = newNode;
    }else{
        newNode->next = s;
        s = newNode;
    }

}

bool isEmpty(struct Node* s){
    return s == NULL;
}

void pop(struct Node* &s){
    if(s == NULL){
        cout<<"stack is null";
        return;
    }

    struct Node* temp = s;
    s = s->next;
    delete(temp);
}

struct record* top(struct Node* s){
    return s->val;
}

bool isOperator(char input){
    return  input == '+' ||
            input == '-' ||
            input == '*' ||
            input == '/' ;
}

void printInfix(struct record* tree){
    if(tree == NULL)
        return;

    printInfix(tree->left);
    cout<<tree->val;
    printInfix(tree->right);

}
