#include<iostream>
using namespace std;

struct Node{
    char symbol;
    struct Node* next;
};

typedef struct Node* Stack;



void push(Stack &s,char symbol);
void pop(Stack &s);
char top(Stack &s);
bool isOpenSymbol(char symbol);
bool isEmpty(Stack s);
bool isConsistent(char top,char ch);
string checkSymbol(string symbol);


int main(){
    string symbol = "";
    Stack s = NULL;
    int i = 0;
    char ch = '\0';



    cout<<"Input : ";
    cin>>symbol;

    while(ch != '.'){

        if(isOpenSymbol(symbol[i])){
            push(s,symbol[i++]);
        }else{
            ch = symbol[i];

            if(isConsistent(top(s),ch)){
                pop(s);
                i++;
            }else{

                if(symbol.size() == 3){
                    cout<<"Error! Inconsistent symbol";
                    return 0;
                }else if(isEmpty(s)){
                    cout<<"Error! no open symbol";
                    return 0;
                }

            }
        }
    }

    if(!isEmpty(s))
            cout<<"Error! Excess symbols";
        else
            cout<<"PASS!!";

    return 0;
}

char top(Stack &s){
    return s->symbol;
}

void push(Stack &s,char symbol){
    Stack node = new struct Node;
    node->symbol = symbol;
    node->next = NULL;

    if(s == NULL)
        s = node;
    else{
        node->next = s;
        s = node;
    }
}

void pop(Stack &s){
    struct Node* temp = s;
    s = s->next;
    delete temp;
}

bool isOpenSymbol(char symbol){
    return symbol == '(' || symbol == '{' || symbol == '[';
}

bool isConsistent(char top,char ch){
    return (top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']');
}

bool isEmpty(Stack s){
    return s == NULL;
}


string checkSymbol(string symbol){
    return "";
}
