#include <iostream>
using namespace std;

struct record{
    int value;
    record *next;
    record *prv;
};

int main(){
    record *head = NULL;
    record *tail = NULL;
    record *node;
    int value;

    cout << "Enter :";
    cin >> value;
    node = new record;
    node -> value = value;
    node -> next = NULL;
    node -> prv = NULL;
    head = node;
    tail = node;

    cout << "Print form head : " << head -> value << endl;
    cout << "Print form tail : " << tail -> value << endl;

    delete node;

    return  0;
}