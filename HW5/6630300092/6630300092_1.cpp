#include<iostream>

using namespace std;

struct record {
    int value;
    struct record *next;
    struct record *prv;
};
typedef struct record *Record;

void insertValue(Record *head, Record *tail, int value);
void deleteValue(Record *head, Record *tail, int value);
void printSeries(Record *head, Record *tail);
int countIndex(Record *head);

int main() {
    int choice;
    int value;
    Record head = NULL, tail = NULL;

    do {
        cout << "========================\n"
                "          MENU            \n"
                "========================\n"
                "1) Insert\n"
                "2) Delete\n"
                "3) Print min to max,Print Max to min\n"
                "4) Count \n"
                "5) Exit\n";
        cout << "Please choose > ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Insert : ";
                cin >> value;
                insertValue(&head, &tail, value);
            }
            cout << endl;
            break;
            case 2:
                cout << "Delete : ";
                cin >> value;
                deleteValue(&head, &tail, value);
                break;
            case 3:
                printSeries(&head, &tail);
                break;
            case 4:
                cout << "Size = " << countIndex(&head) << endl;
                break;
            case 5:
                cout << "Exit!!" << endl;
                break;
            default :
                cout<<"Invalid value"<<endl;
                break;
        }
    } while (choice != 5);
    return 0;
}

void insertValue(Record *head, Record *tail, int value) {
    Record newNode = new struct record;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prv = NULL;


    if (*head == nullptr) {
        *head = newNode;
        *tail = newNode;

    } else if ((*head)->value > value) {
        newNode->next = *head;
        (*head)->prv = newNode;
        *head = newNode;

    } else if ((*tail)->value < value) {
        newNode->next = (*tail)->next;
        newNode->prv = *tail;
        (*tail)->next = newNode;
        *tail = newNode;

    } else {
        Record p = *head;
        while (p->next != nullptr && p->next->value < value) {
            p = p->next;
        }
        newNode->next = p->next;
        newNode->prv = p;
        if (p->next != nullptr) {
            p->next->prv = newNode;
        }
        p->next = newNode;
    }
}

void deleteValue(Record *head, Record *tail, int value) {
    int countStart = countIndex(head);

    if (*head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Record p = *head;

    while (p != NULL && p->value != value) {
        p = p->next;
    }


    if (p == NULL) {
        cout << "Fail!!" << endl;
        return;
    }

    if (p == *head && p == *tail) {
        *head = NULL;
        *tail = NULL;

    } else if (p == *head) {
        *head = (*head)->next;
        (*head)->prv = NULL;

    } else if (p == *tail) {
        *tail = (*tail)->prv;
        (*tail)->next = NULL;

    } else {
        p->prv->next = p->next;
        p->next->prv = p->prv;
    }

    delete p;


    if (countStart != countIndex(head)) {
        cout << "Success!!" << endl;
    } else {
        cout << "Fail!!" << endl;
    }
}

void printSeries(Record *head, Record *tail) {
    Record min = *head, max = *tail;

    cout << "Print min to max : ";
    while (min != NULL) {
        cout << min->value << " ";
        min = min->next;
    }
    cout << endl;

    cout << "Print max to min : ";
    while (max != NULL) {
        cout << max->value << " ";
        max = max->prv;
    }
    cout << endl;
}

int countIndex(Record *head) {
    int countOfValue = 0;
    Record p = *head;

    while (p != NULL) {
        countOfValue += 1;
        p = p->next;
    }

    return countOfValue;
}
