#include <iostream>
using namespace std;

int main(){
 int first_num = 0,second_num = 1,next,term = 19;

    for (int i = 2; i <= term; i++) {
        next = first_num+second_num;
        first_num = second_num;
        second_num = next;
        cout << "F(" << i << ") = " << next << endl;
    }


    return 0;
}