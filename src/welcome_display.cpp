#include <iostream>
#include <string>
using namespace std;

void welcome_display() {
    cout << "=========================\n";
    cout << "        Welcome to       \n";
    cout << "       Demon's Hand      \n";
    cout << "=========================\n\n";
    cout << "Type anything to continue.\n";

    string ready;
    cout << "Are you ready?: ";
    cin >> ready;  // waits for user input (no need to use it)
}