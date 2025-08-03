#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Check username validity (alphanumeric only)
bool isValidUsername(const string& username) {
    if (username.empty()) return false;
    for (int i = 0; i < username.length(); i++) {
        if (!isalnum(username[i])) return false;
    }
    return true;
}

// Check password strength (at least 6 chars, contains letters and digits)
bool isStrongPassword(const string& password) {
    if (password.length() < 6) return false;
    bool hasLetter = false, hasDigit = false;
    for (int i = 0; i < password.length(); i++) {
        if (isalpha(password[i])) hasLetter = true;
        if (isdigit(password[i])) hasDigit = true;
    }
    return hasLetter && hasDigit;
}

// Check if username already exists
bool isDuplicateUsername(const string& username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) return true;
    }
    return false;
}

// Registration function
void registerUser() {
    string username, password;

    cout << "\n-- Registration --\n";
    cout << "Enter username (no spaces, only letters and numbers): ";
    cin >> username;

    if (!isValidUsername(username)) {
        cout << "Error: Invalid username format.\n";
        return;
    }

    if (isDuplicateUsername(username)) {
        cout << "Error: Username already taken.\n";
        return;
    }

    cout << "Enter password (min 6 characters, must include letters and numbers): ";
    cin >> password;

    if (!isStrongPassword(password)) {
        cout << "Error: Weak password.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        cout << "Registration successful.\n";
    } else {
        cout << "Error: Could not open file to save data.\n";
    }
    file.close();
}

// Login function
void loginUser() {
    string username, password, u, p;
    bool found = false;

    cout << "\n-- Login --\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found)
        cout << "Login successful. Welcome, " << username << "!\n";
    else
        cout << "Error: Invalid username or password.\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n==== LOGIN SYSTEM ====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

