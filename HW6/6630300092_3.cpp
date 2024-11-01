#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

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
int evaluatePostfix(const string expression);

int main() {
    string expression;
    cout << "Input : ";
    getline(cin, expression);


    if (!expression.empty() && expression.back() == '.') {
        expression.pop_back();
    }

    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;

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
    if (!isEmpty(s)) {
        return s->value;
    }
    return "";
}

bool isEmpty(Stack s) {
    return s == NULL;
}

int evaluatePostfix(const string expression) {
    Stack s = NULL;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {

            s = push(token, s);
        } else {

            int operand2 = stoi(top(s));
            s = pop(s);
            int operand1 = stoi(top(s));
            s = pop(s);

            int result;
            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else if (token == "/") {
                result = operand1 / operand2;
            } else {
                cout << "Unknown operator: " << token << endl;
                return -1;
            }


            s = push(to_string(result), s);
        }
    }


    if (!isEmpty(s)) {
        int finalResult = stoi(top(s));
        s = pop(s);
        return finalResult;
    }

    cout << "Stack is empty after evaluation" << endl;
    return -1;
}
