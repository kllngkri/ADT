#include<iostream>
using namespace std;

struct Node{
    int value;
    struct Node *next;
};
typedef struct Node *Stack;


void pop(Stack s);
void push(Stack s,int value);
void popAll(Stack s);
void top(Stack s);
Stack createStack(void);
bool isEmty(Stack s);


int main(){
    int choice;
    Stack S = createStack();

    do {
        cout << "========================\n"
                "          MENU            \n"
                "========================\n"
                "1) Push\n"
                "2) Top\n"
                "3) Pop\n"
                "4) Pop All \n"
                "5) Exit\n";
        cout << "Please choose > ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                int value;

                cout<<"Push : ";
                cin>>value;
                push(S,value);
                cout<<S->next->value;
                cout << endl;
                }
                break;
            case 2:
                top(S);
                break;
            case 3:
                pop(S);
                break;
            case 4:
                popAll(S);
                break;
            case 5:
                cout<<"End";
                break;
            default :
                cout<<"Invalid value"<<endl;
                break;
        }
    } while (choice != 5);

return 0;
}

Stack createStack(void){
    Stack S = new struct Node;

    if(S==NULL)
        cout<<"Out of space!!"<<endl;
    S->next = NULL;
    cout<<"...Create Stack Success!!\n";
    return S;
}

void push(Stack S,int value){
    Stack tmpCell = new struct Node;

    if(tmpCell == NULL){
        cout<<"Out of space!!"<<endl;
    }else{
        tmpCell->value = value;
        tmpCell->next = S->next;
        S->next = tmpCell;
    }
}

bool isEmty(Stack S){
    return S->next == NULL;
}

void top(Stack s){
    if(!isEmty(s))
        cout<<"Top : "<<s->next->value<<endl;
    else
        cout<<"Stack is empty"<<endl;
}

void pop(Stack s){
    if(isEmty(s))
        cout<<"Stack is empty"<<endl;
    else {
        Stack tmp = s->next;
        s->next = s->next->next;
        cout<<"pop : "<<tmp->value<<endl;
        delete tmp;
        cout<<"Success!!"<<endl;
    }
}

void popAll(Stack s){
    top(s);
    if(isEmty(s))
        cout<<"Stack is empty"<<endl;
    else
        while(!isEmty(s)){
            pop(s);
            top(s);
        }

}



