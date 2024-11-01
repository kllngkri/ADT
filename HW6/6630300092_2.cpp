#include<iostream>
using namespace std;

struct Node {
    string value;
    struct Node* next;
};
typedef struct Node* Stack;

Stack push(string value, Stack s);
Stack pop(Stack s);
string top(Stack s);
bool isEmpty(Stack s);

bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    Stack s = NULL;
    string infix = "";

    cout << "input : ";
    while (infix != ".") {
        cin >> infix;

        if (isNumber(infix)) {
            cout << infix << " ";
        } else {
            if (isEmpty(s)) {
                s = push(infix, s);
            } else {
                if (infix == "(") {
                    s = push(infix, s);
                } else if (infix == ")") {
                    while (top(s) != "(") {
                        cout << top(s) << " ";
                        s = pop(s);
                    }
                    s = pop(s); // pop '('
                } else {
                    while (!isEmpty(s) && ((infix == "+" || infix == "-") && (top(s) == "*" || top(s) == "/" || top(s) == "+" || top(s) == "-"))
                                         || ((infix == "*" || infix == "/") && (top(s) == "*" || top(s) == "/"))) {
                        cout << top(s) << " ";
                        s = pop(s);
                    }
                    s = push(infix, s);
                }
            }
        }
    }

    while (!isEmpty(s)) {
        cout << top(s) << " ";
        s = pop(s);
    }

    return 0;
}

Stack push(string value, Stack s) {
    struct Node* node = new struct Node;
    node->value = value;
    node->next = s;
    s = node;
    return s;
}

Stack pop(Stack s) {
    struct Node* tmp = s;
    if (isEmpty(s)) {
        cout << "Stack Underflow" << endl;
        return s;
    }
    s = s->next;
    delete tmp;
    return s;
}

string top(Stack s) {
    return s->value;
}

bool isEmpty(Stack s) {
    return s == NULL;
}
