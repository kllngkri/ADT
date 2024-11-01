#include<iostream>

using namespace std;

struct record{
    int value;
    struct record* next;
};

struct record* insertCircular(int n,struct record* head){
    head = new struct record;
    head->value = 1;
    head->next = NULL;
    struct record* temp = head;

    for(int i = 2;i <= n;i++){

         temp->next = new struct record;
        temp = temp->next;
        temp->value = i;
        temp->next = nullptr;
    }
    temp->next = head;
    return head;
};


struct record* kill(struct record* head,int k){
    struct record* p = head;
    struct record* temp = NULL;


    while(p->next != p){

        for(int i = 1;i < k - 1;i++){
            p = p->next;
        }

        temp = p-> next;
        p->next = temp->next;
        delete temp;

        p = p->next;
    }

    return p;

};

int main(){

    struct record* head = insertCircular(5,head);
    struct record* p = head;


    head = kill(head,3);
    cout<<head->value;
    delete head;


return 0;
}
