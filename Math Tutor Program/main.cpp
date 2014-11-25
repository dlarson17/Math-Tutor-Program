//
//  main.cpp
//  Math Tutor Program
//
//  Created by Dane Larson on 2/14/14.
//  Copyright (c) 2014 Dane Larson. All rights reserved.
// do{       // This gives the user the option of trying again the problem they got wrong.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Hey Dane,
// You ask the user to enter "Y" or "N" for repeating the question.
// However, you only check for "y" or "n". Be careful with that.
// C++ doesn't recognize that Y and y are the same letter.
//-Hannah

int addition(int x, int y);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
void welcome();
char menu(char choice);
void again(int userAns, int correctAns, int x, int y, char a);
void tries (char type, int Tries[], int size);
void numberCorrect (char type, int Correct[], int size);

int Tries[4] = {0, 0, 0, 0}; // Arrays SPRINT 6!
int Correct[4] = {0, 0, 0, 0}; // Arrays

int main () // This is the opening screen for the program. It will show what the program will do for the user.
{
    

    // Setting up integers
    int userAns;
    char choice = 'b';
    int correctAns;
    welcome();
    char choice1 = menu(choice);
    char a;
    int c=0;
    while (c<=9){ //The while loop that gives the user 10 problems.
        c+=1;
        srand(time(NULL)); // Random number generator
        int x = rand() % 10;
        int y = (rand() % 9) + 1;
    
    
    switch (choice1) { // User choosing between math problems
        case '1':
            a = '+';
            cout << x << " + " << y << " = ";
            cin >> userAns;
            while (cin.fail()) {
                cout << "\nPlease enter an integer: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> userAns;
            }
            correctAns=addition(x, y);
            again(userAns, correctAns, x, y, a);//Function comes into play here.
            break;
        case '2':
            a = '-';
            cout << x << " - " << y << " = ";
            cin >> userAns;
            while (cin.fail()) {
                cout << "\nPlease enter an integer: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> userAns;
            }
            correctAns =subtraction(x,y);
            again(userAns, correctAns, x, y, a);//Function comes into play here.
            break;
        case '3':
            a = '*';
            cout << x << " * " << y << " = ";
            cin >> userAns;
            while (cin.fail()) {
                cout << "\nPlease enter an integer: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> userAns;
            }
            correctAns =multiplication(x,y);
            again(userAns, correctAns, x, y, a);//Function comes into play here.
            break;
        case '4':
            a = '/';
            cout << x << " / " << y << " = ";
            cin >> userAns;
            while (cin.fail()) {
                cout << "\nPlease enter an integer: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> userAns;
            }
            correctAns = division(x,y);
            again(userAns, correctAns, x, y, a);//Function comes into play here.
            break;
      
            
    }
}
    cout << "Correct: " << Correct[0] << endl; // displays how many the user got correct
    cout << "Tries: " << Tries[0] << endl; // displays how many tries the user did.
    
    return 0;
} // Functions below.

int addition(int x, int y) {
    int r = x+y;
    return r;
}

int subtraction(int a, int b) {
    int r = a-b;
    return r;
}

int multiplication(int a, int b) {
    int r = a*b;
    return r;
}

int division(int a, int b) {
    int r = a/b;
    return r;
}

void welcome() { // Sprint 5 Refractoring the welcome function
    cout << "Welcome to the Mathomatic Tutor Center 3000" << endl; // Welcoming screen. Sprint 1
    cout << "Mathomatic 3000 is the best for all your basic math needs: " << endl << endl;
    
    cout << "addition" << endl;
    cout << "subtract" << endl;
    cout << "division" << endl;
    cout << "multiplication" << endl << endl;
    
    string name; // Sprint 2
    cout << "What is your name? "; // showEquation
    getline(cin, name);
    
    cout << "Welcome " << name << "!";
}

char menu(char choice) { // Sprint 5 Refractoring the menu function
    do {
    cout << " Let's get started!" << endl << endl;
    cout << "Choose a type of math problem: " << endl;
    
    cout << "1) Addition" << endl; // Sprint 3. Menu for choosing.
    cout << "2) Subtraction" << endl;
    cout << "3) Multiplication" << endl;
    cout << "4) Division" << endl;
    cout << "===================" << endl;
    cout << "Enter 1,2,3,4 to choose: ";
    cin >> choice;
    cout << endl << endl;
        if (choice > '4' || choice < '1') {
            cout << "Please enter a valid number (1, 2, 3, 4)" << endl << endl;
        }
    }while (choice > '4' || choice < '1');
    return choice;
}

void again(int userAns, int correctAns, int x, int y, char a) {
    if (userAns != correctAns) {
        cout << "\nIncorrect. Try again? (Y/N) ";
        char more;
        cin >> more;
        cout << "\n";
        while (tolower(more) != 'n' && tolower(more) != 'y') {
            cout << "\nPlease enter Y (Yes) or N (No): ";
            cin >> more;
        }
        if (tolower(more) == 'y'){
            cout << x << " " << a << " " << y << " = ";
            cin >> userAns;
            while (cin.fail()) {
                cout << "\nPlease use an integer. Try again: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> userAns;
            }
            again(userAns, correctAns, x, y, a);
        }
        tries (a, Tries, 4); // The array that contains how many tries they did.
    }
    else {
        cout << "Excellent work my friend!\n\n";
        numberCorrect (a, Correct, 4); // The array that contains how many correct.
    }
}


void tries (char type, int Tries[], int size)
{
    if (type == '+')
        Tries[0] += 1;
    else if (type == '-')
        Tries[1] += 1;
    else if (type == '*')
        Tries[2] += 1;
    else
        Tries[3] += 1;
}

void numberCorrect (char type, int Correct[], int size)
{
    if (type == '+')
        Correct[0] += 1;
    else if (type == '-')
        Correct[1] += 1;
    else if (type == '*')
        Correct[2] += 1;
    else
        Correct[3] += 1;
}

void statements (int Correct[], int Tries[], char type) {
    if (Correct[0] > 0 || Tries[0] > 0) {
            cout << "Addition\n";
            cout << "Correct: " << Correct[0] << endl;
            cout << "Tries: " << Tries[0] << endl;
        }
    if else (Correct[1]
