#include <iostream>
using namespace std;

struct record{
    char code;
    struct record *next;
};

struct record *insert(struct record *head, char code);

void print_list(record *pRecord);

int main(){
    string menu = "=========================\n"
                  "          MENU         \n"
                  "=========================\n"
                  "1) Input secret code \n"
                  "2) Decode\n"
                  "3) Exit \n";
    int choose;
    string code;
    struct record *head = NULL;


    do {
        cout << menu << endl;
        cout << "Please choose >";
        cin >> choose;

        switch (choose) {
            case 1:
                cout << "CODE :";
                cin >> code;
                for (int i = 0; i < code.size(); i++) {
                    head = insert(head,code[i]);
                }
                break;
            case 2:
                cout << "Answer :";
                print_list(head);
                break;
            case 3:
                cout << "End!!";
                break;

        }
    } while (choose != 3);
    return 0;
}

void print_list(record *pRecord) {
    record *pointer;
    pointer = pRecord;

    while (pointer != NULL){
        cout << pointer -> code;
        pointer = pointer -> next;
    }
    cout << endl;
}

struct record *insert(struct record *head,char code) {
    struct record *new_node;
    new_node = new struct record;
    new_node -> next = NULL;
    new_node -> code = code;

    if (head == NULL) {
        head = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
    return head;
}