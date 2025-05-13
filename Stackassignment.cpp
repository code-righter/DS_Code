#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

void parenthesis() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty()) {
                cout << "Invalid String" << endl;
                return;
            }

            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{')) {
                st.pop();
            } else {
                cout << "Invalid String" << endl;
                return;
            }
        }else {
            cout<<"Invalid String"<<endl;
            return ;
        }
    }

    if (st.empty()) {
        cout << "Valid String" << endl;
    } else {
        cout << "Invalid String" << endl;
    }
}

int pr(char ch) {
    if (ch == '^') return 3;
    else if (ch == '/' || ch == '*') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string ans = "";

    for (char ch : s) {
        if (isalnum(ch)) {
            ans += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();  // Pop the '('
        } else {
            while (!st.empty() && pr(ch) <= pr(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << ans << endl;
    return ans;
}

void evalPostfix(string& postStr) {
    stack<int> s;

    for (char c : postStr) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            if (s.size() < 2) {
                cout << "Invalid postfix expression!" << endl;
                return;
            }
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                case '^': s.push(pow(operand1, operand2)); break;
                default: 
                    cout << "Unknown operator: " << c << endl;
                    return;
            }
        }
    }

    if (s.size() == 1) {
        cout << "Result of Postfix Evaluation: " << s.top() << endl;
    } else {
        cout << "Invalid postfix expression!" << endl;
    }
}


string postfixToInfix(string postfix) {
    stack<string> st;

    for (char ch : postfix) {
        // If operand, push as string
        if (isalnum(ch)) {
            st.push(string(1, ch));
        }
        // If operator, pop two operands and combine
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (st.size() < 2) {
                cout << "Invalid postfix expression!" << endl;
                return "";
            }

            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string expr = "(" + op1 + ch + op2 + ")";
            st.push(expr);
        }
    }

    // Final result
    if (st.size() != 1) {
        cout << "Invalid postfix expression!" << endl;
        return "";
    }

    cout << "Infix Expression: " << st.top() << endl;
    return st.top();
}


int main() {
    int choice;
    string s;

    do {
        cout << "\n\nEnter the choice against the following option:\n";
        cout << "1. Implementation of Matching Parenthesis Problem\n";
        cout << "2. Conversion of Infix to Postfix\n";
        cout << "3. Evaluation of Postfix\n";
        cout << "4. Conversion of Postfix to Infix" << endl;
        cout << "5. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                parenthesis();
                break;

            case 2:
                cout << "\nEnter the infix expression: ";
                cin >> s;
                infixToPostfix(s);
                break;

            case 3:
                cout << "\nEnter the postfix expression: ";
                cin >> s;
                evalPostfix(s);
                break;

            case 4:
                cout << "\nEnter the postfix string to convert to infix: ";
                cin >> s;
                postfixToInfix(s);
                break;
            
            case 5: 
                cout<<"Exiting"<<endl;
                choice = 5;
                break;


            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
