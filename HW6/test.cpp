#include<iostream>
using namespace std;

struct record{

    int value;
    struct record* next;

};


struct record* insertValue(struct record* head,int data){

    if(head == NULL){
        head = new struct record;
        head->value = data;
        head->next = NULL;
    }else{


        if(head->value > data){
            struct record* node = new struct record;
            node->value = data;
            node->next = head;
            head = node;
        }else{
            struct record* node = new struct record;
            node->value = data;
            node->next = NULL;

            struct record* p = head;

            while(p->next != NULL){
                if(data < p->next->value){
                    node->next = p->next;
                    p->next = node;
                    break;
                }
                p = p->next;
            }

            if(p->next == NULL){
                p->next = node;
            }else{
                return head;
            }
        }


    }

    return head;
}


int main(){
    struct record* head = NULL;
    head = insertValue(head,6);
    head = insertValue(head,4);
    head = insertValue(head,7);

    struct record* p = head;

    while(p != NULL){
        cout<<p->value<<endl;
        p->next = p;
    }






    return 0;
}
