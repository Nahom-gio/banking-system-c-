#include <iostream>
#include <string>
#include <random>

using namespace std;

// Global variables to store account information
string customerName;
string customerAddress;
string accountType;
double accountBalance = 0;

// Functions to display the main menu
void displayMainMenu() {
    cout << "Welcome To Our Bank" << endl;
    cout << "Main Menu:" << endl;
    cout << "1. Open Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Transfer Money" << endl;
    cout << "6. Display Account" << endl;
    cout << "7. Exit" << endl;
}

// Functions to call display main menu
void goBackToMainMenu() {
    displayMainMenu();
}

// Function that asks to go back to the main menu or exit
void goBackToMainMenuOrExit() {
    int choice;
    cout << "Do you want to go back to the main menu? (1 for Yes, 2 for No): ";
    cin >> choice;
    if (choice == 1) {
        cout << "";
    } else {
        cout << "Exiting the program. Thank you for using our banking system. Goodbye!" << endl;
        exit(0);
    }
}

// Function to open a new account
void openAccount() {
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter your address: ";
    getline(cin, customerAddress);
    cout << "What type of account do you want to open? (Savings or Current): ";
    cin >> accountType;
    cout << "Enter initial deposit amount: ";
    cin >> accountBalance;
    cout << "Your account has been created successfully." << endl;

    random_device rd;  // Obtain a random number from hardware
    mt19937 gen(rd());  // Seed the generator
    // Define the distribution
    uniform_int_distribution<> dis(10000000, 99999999);  // Range of 8-digit numbers
    // Generate and output the random number
    int randomNum = dis(gen);

    cout <<"****Based on the information provided, here are your account details**** " <<endl;
    cout <<"\t ____________________________________" <<endl;
    cout << "\t Account Holder Name: " << "["<< customerName << "]"<<endl;
    cout << "\t Your Account Number: " << "[" << randomNum <<"]"<< endl;
    cout << "\t Your Current Balance is: " <<"[" <<accountBalance<< "]"<<endl;
    cout <<"\t ____________________________________"<<endl;
    cout << "Thank you for opening an account.";
}

// Function to deposit money into the account
void depositMoney() {
    double amount;
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    accountBalance += amount;
    cout << "Your total deposit amount is now: " << accountBalance << endl;
}

// Function to display account details
void displayAccount() {
    cout << "Name: " << customerName << endl;
    cout << "Address: " << customerAddress << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Balance: " << accountBalance << endl;
}

// Function to withdraw money from the account
void withdrawMoney() {
    int amount;
    cout << "Enter the amount you want to withdraw: ";
    cin >> amount;
    if (amount <= accountBalance) {
        accountBalance -= amount;
        cout << "Withdrawal successful. Remaining balance: " << accountBalance << endl;
    } else {
        cout << "Insufficient funds for withdrawal." << endl;
    }
}

// Function to check account balance
void checkBalance() {
    cout << "Your current balance is: " << accountBalance << endl;
}

// Function to transfer money to another account
void transferMoney() {
    string recipientName;
    int transferAmount;
    cout << "Enter recipient's name: ";
    cin.ignore();
    getline(cin, recipientName);
    cout << "Enter the amount you want to transfer: ";
    cin >> transferAmount;
    if (transferAmount <= accountBalance) {
        accountBalance -= transferAmount;
        cout << "Transfer of $" << transferAmount << " to " << recipientName
             << " successful. Remaining balance: " << accountBalance << endl;
    } else {
        cout << "Insufficient funds for transfer." << endl;
    }
}

int main() {
    int choice;

    do {
        // Display menu options
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                openAccount();
                goBackToMainMenuOrExit();
                break;
            case 2:
                depositMoney();
                goBackToMainMenuOrExit();
                break;
            case 3:
                withdrawMoney();
                goBackToMainMenuOrExit();
                break;
            case 4:
                checkBalance();
                goBackToMainMenuOrExit();
                break;
            case 5:
                transferMoney();
                goBackToMainMenuOrExit();
                break;
            case 6:
                displayAccount();
                goBackToMainMenuOrExit();
                break;
            case 7:
                cout << "Thank you for using our banking system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
