////นาย เกรียงเดช เปี่ยมแจง
////6630300092
//
//#include <iostream>
//using namespace std;
//
//struct record{
//    int value;
//    record *next;
//    record *prv;
//};
//record *head,*tail;
//
//void insert(int value);
//void print_max_min();
//
//string menu = "=========================\n"
//              "          MENU         \n"
//              "1) Insert\n"
//              "2) Print min to max,max to min \n"
//              "3) Exit  \n";
//
//int main(){
//    int choice;
//
//    do {
//        cout<<menu;
//        cout<<"Please choose >";
//        cin>>choice;
//
//        switch (choice) {
//            case 1:
//                int value;
//                cout<<"Insert :";
//                cin>>value;
//                insert(value);
//                break;
//            case 2:
//                print_max_min();
//                break;
//            case 3:
//                cout<<"End!!";
//                break;
//            default:
//                cout<<"Invalid choice!!"<<endl;
//                break;
//        }
//    } while (choice != 3);
//    return 0;
//}
//
//void insert(int value){
//    record *pointer,*new_node;
//    new_node = new record;
//    new_node->value = value;
//    new_node->next = NULL;
//    new_node->prv = NULL;
//
//    if (head == NULL)
//    {
//        head = new_node;
//        tail = new_node;
//    }
//    else if (head->value > value)
//    {
//        new_node->prv = NULL;
//        new_node->next = head;
//        head->prv = new_node;
//        head = new_node;
//
//    }
//    else if (tail->value < value){
//        new_node->prv = tail;
//        tail->next = new_node;
//        tail = new_node;
//    }
//    else
//    {
//        pointer = head;
//        while (pointer->next->value < value)
//            pointer = pointer->next;
//        new_node->next = pointer->next;
//        pointer->next->prv = new_node;
//        new_node->prv = pointer;
//        pointer->next = new_node;
//
//    }
//
//}
//
//void print_max_min(){
//    record *pointer;
//    cout<<"Min to max : ";
//    pointer = head;
//    while (pointer){
//        cout<<pointer->value<<" ";
//        pointer = pointer->next;
//    }
//    cout<<endl;
//
//    cout<<"Min to max : ";
//    pointer = tail;
//    while (pointer){
//        cout<<pointer->value<<" ";
//        pointer = pointer->prv;
//    }
//    cout<<endl;
//}