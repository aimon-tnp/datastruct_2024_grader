#include <iostream>

using namespace std;

int main(){
    int input;
    cout << "Enter your number: " << endl;
    cin >> input;

    if (input < 0){
        cout << "Your number is not a palindrome (Negative number)" << endl;
    } else {
        int originalInput = input;
        int reversedInput = 0;
        while (input != 0){
            int lastDigit = input % 10;
            reversedInput = reversedInput * 10 + lastDigit;
            input /= 10;
        }

        cout << "This is reversed-version of your input: " << reversedInput << endl;
        
        if (reversedInput == originalInput){
            cout << "Which is a palindrome" << endl;
        } else {
            cout << "Which is NOT a palindrome" << endl;
        }
    }
    
    return 0;
}
