#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation from ( +, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << "Addition of " << num1 << " and " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Subtraction of " << num1 << " from " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Multiplication of " << num1 << " and " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Division of " << num1 << " by " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
        default:
            cout << "Invalid operation! Please choose +, -, *, or /." << endl;
            break;
    }

    return 0;
}
