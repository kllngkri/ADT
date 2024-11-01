#include <iostream>
#include <stack>

using namespace std;
int main() {
    stack
    int num;
    cout << "input :";
    cin >> num;


    for (int i = 1; i <= num; i++) {
        for (int j = i; j <= num  ; j++) {
            for (int k = i; k <= j ; k++) {
                cout << k;
            }
            cout << " ";
        }
        cout << endl;
    }

    for (int i = num; i >= 1; i--) {
        for (int j = i; j >= 1  ; j--) {
            for (int k = i; k >= j ; k--) {
                cout << k;
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
