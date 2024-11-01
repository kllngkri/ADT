#include <iostream>
using namespace std;

void print_all_list(int list[],int size){
    int mid = size/2;

    cout << "Print : ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "Print first half : ";
    for (int i = 0; i < mid; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "Print second half : ";
    for (int i = mid; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

void print_list(int list[],int size){
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

void del(int list[],int &size,int value) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] == value){
            index = i;
            break;
        }
    }

    for (int i = index; i < size ; i++) {
        list[i] = list[i+1];
    }
    size--;
}

void insert(int list[],int &size,int value){
    int index;
    index = size;

    for (int i = 0; i < size; i++) {
        if (value < list[i]){
            index = i;
            break;
        }
    }

    for (int i = size; i >= index ; i--)
        list[i + 1] = list[i];

    list[index] = value;
    size++;
}

int main(){
    int max_size = 10;
    int size = 0;
    int list[max_size];
    int choose;
    int value;

    do {
        cout << "===========Menu==========\n"
                "+\t1) Insert\t+\n"
                "+\t2) Delete\t+\n"
                "+\t3) Print \t+\n"
                "+\t4) Exit  \t+\n"
                "=========================\n";
        cout << "Please choose >";
        cin >> choose;

        switch (choose) {
            case 1:
                cout << "Enter :";
                cin >> value;
                insert(list,size,value);
                print_list(list,size);
                break;
            case 2:
                cout << "Delete :";
                cin >> value;
                del(list,size,value);
                print_list(list,size);
                break;
            case 3:
                print_all_list(list,size);
                break;

        }
    } while (choose != 4);

    return 0;
}



