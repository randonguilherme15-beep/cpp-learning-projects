#include <iostream>

using namespace std;
int main() {
    int choice;
int number1;
float number2;

cout << "Enter first number: " << endl;
cin >> number1;
cout << "Enter second number: " << endl;
cin >> number2;
   
    cout << "1 = Addition" << endl;  
    cout << "2 = Subtraction" << endl;  
     cout << "3 = Multiplication" << endl;  
     cout << "4 = Division" << endl;  
     cin >> choice;

switch (choice)
{
case 1: 
cout << "Result: " << number1 + number2 << endl;
    /* code */
    break;
case 2:
cout << "Result: " << number1 - number2 << endl;
    /* code */
    break;
case 3:
cout << "Result: " << number1 * number2 << endl;
    /* code */
    break;
case 4:
if (number2 != 0) {
    cout << "Result: " << number1 / number2 << endl;
} else {
    cout << "Error: Division by zero is not allowed." << endl;
}
    /* code */
    break;

default:
    break;
}

return 0;

}
