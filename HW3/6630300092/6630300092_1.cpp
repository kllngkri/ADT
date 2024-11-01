#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

int count_list(struct record *head);
void print_half(struct record *head);
bool found(record *head, int value);
struct record *insert(struct record *head, int value);
struct record *delete_list(struct record *head,int value);

void print_maxtomin_mintomax(record *head);

int main(){
    string menu = "=========================\n"
                  "          MENU         \n"
                  "=========================\n"
                  "1) Insert\n"
                  "2) Delete\n"
                  "3) Print min to max,max to min \n"
                  "4) Count\n"
                  "5) Print first half and second half\n"
                  "6) Find\n"
                  "7) Exit  \n";

    struct record *head = NULL;
    int choice;
    int value;

    do {
    cout << menu;
    cout << "Please choose >";
    cin >> choice;
        switch(choice) {
            case 1:
                cout << "Insert : ";
                cin >> value;
                head = insert(head, value);
                break;
            case 2:
                cout << "Delete : ";
                cin >> value;
                head = delete_list(head, value);
                break;
            case 3:
                print_maxtomin_mintomax(head);
                break;
            case 4:
                cout << "Count = " << count_list(head) << endl;
                break;
            case 5:
                print_half(head);
                break;
            case 6:
                cout << "Find :";
                cin >> value;
                if (found(head,value))
                    cout << "Found!!" << endl;
                else
                    cout << "Not found!!" << endl;
                break;
            case 7:
                cout << "END!!";
                break;
            default:
                cout << "Invalid value!! " << endl;
                break;
        }

    } while (choice != 7);
    return 0;
}

void print_maxtomin_mintomax(record *head) {
    struct record *pointer;
    int value[count_list(head)];
    int count = 0;
    pointer = head;

    cout << "Print min to max : ";
    while (pointer != NULL){
        cout << pointer -> value << " ";
        value[count] = pointer -> value;
        pointer = pointer -> next;
        count++;
    }
    cout << endl;

    cout << "Print max to min : ";
    for (int i = count - 1; i >= 0; i--) {
        cout << value[i] << " ";
    }
    cout << endl;
}

bool found(record *head, int value){
    record *pointer;
    pointer = head;

    while (pointer != NULL){
        if (pointer -> value == value)return true;
        pointer = pointer -> next;
    }

    return false;
}

struct record *delete_list(struct record *head,int value){
    struct record *pointer,*tmp;
    pointer = head;
    if (head -> value == value){
        tmp = head;
        head = head -> next;
        delete(tmp);
    }
    else
    {
        while (pointer != NULL){
            if (pointer -> next -> value == value ){
                tmp = pointer -> next;
                pointer -> next = pointer -> next -> next;
                delete(tmp);
                break;
            }
            pointer = pointer -> next;
        }
    }


    return head;
}

void print_half(struct record *head){
    struct record *pointer;
    int size = count_list(head);
    int mid = size/2;
    int count = 1;
    pointer = head;
    cout << "Print first half : ";
    while (count <= mid)
    {
        cout << pointer -> value << " ";
        pointer = pointer -> next;
        count++;
    }
    cout << endl ;

    cout << "Print second half : ";
    while (count <= size)
    {
        cout << pointer -> value << " ";
        pointer = pointer -> next;
        count++;
    }
    cout << endl ;
}

int count_list(struct record *head){
    struct record *pointer;
    int count = 0;
    pointer = head;

    if (head == NULL){
        return  0;
    }

    while (pointer != NULL){
        count++;
        pointer = pointer -> next;
    }
    return count;
}

struct record *insert(struct record *head, int value) {
    struct record *pointer, *new_node;

    new_node = new struct record;
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    }

    else if (head->value > value) {
        new_node->next = head;
        head = new_node;
    }

    else {
        pointer = head;
        while (pointer->next != NULL && pointer->next->value < value) {
            pointer = pointer->next;
        }
        new_node->next = pointer->next;
        pointer->next = new_node;
    }

    return head;
}
