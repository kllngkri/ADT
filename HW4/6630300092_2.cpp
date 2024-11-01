//นาย เกรียงเดช เปี่ยมแจง
//6630300092

#include <iostream>
using namespace std;

const int end_term = -99,init = -1000;
int factor = init,pow = init;
int term = 1;
bool is_factor = term % 2 != 0;

struct record{
    int factor;
    int pow;
    record *next;
};

record *sum_head = nullptr;

void sum_polynomial();
void input_and_add_term();
void init_term();
void print_result();

int main()
{
    cout<<"Input P1 :";
    input_and_add_term();

    cout<<"Input P2 :";
    input_and_add_term();

    cout<<"Output   : ";
    print_result();

    return 0;
}

void print_result() {
    record *pointer;
    pointer = sum_head;
    while (pointer != nullptr)
    {

        if (pointer->pow == 0)
            cout<<pointer->factor;
        else if (pointer -> factor == 1)
            cout<<"x^"<<pointer->pow;
        else if (pointer->pow == 1)
            cout<<pointer->factor<<"x^";
        else
            cout<<pointer->factor<<"x^"<<pointer->pow;

        if (pointer->next != nullptr && pointer->next->factor >= 0)
            cout<<"+";
        pointer = pointer->next;
    }
    cout << endl;

}

void input_and_add_term()
{
    int input = 0;
    while (input != end_term){
        is_factor = term % 2 != 0;
        cin>>input;
        if (is_factor)
            factor = input;
        else
            pow = input;

        if (pow!=init && factor!=init)
        {
            sum_polynomial();
            init_term();
        }
        term++;
    }
    term = 1;
}

void sum_polynomial() {
    record *new_term = new record;
    new_term->factor = factor;
    new_term->pow = pow;
    new_term->next = nullptr;

    if (sum_head == nullptr) {
        sum_head = new_term;
    } else if (sum_head->pow < new_term->pow) {
        new_term->next = sum_head;
        sum_head = new_term;
    } else {
        record *pointer = sum_head;

        while (pointer->next != nullptr && pointer->next->pow > new_term->pow) {
            pointer = pointer->next;
        }


        if (pointer->pow == new_term->pow) {
            pointer->factor += new_term->factor;
            delete new_term;
        } else if (pointer->next != nullptr && pointer->next->pow == new_term->pow) {
            pointer->next->factor += new_term->factor;
            delete new_term;
        } else {
            new_term->next = pointer->next;
            pointer->next = new_term;
        }
    }
}


void init_term()
{
    factor = init;
    pow = init;
}
