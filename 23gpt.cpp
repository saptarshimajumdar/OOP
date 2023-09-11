#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class SavingsAccount {
public:
    SavingsAccount(string& name, int accountNumber, double balance) 
        : accountHolderName(name), accountNumber(accountNumber), accountBalance(balance) {
        // Generate a random interest rate between 1% and 10%
        interestRate = (rand() % 10 + 1) / 100.0;
    }

    // Member function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            accountBalance += amount;
        }
    }

    // Member function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && accountBalance - amount >= 1000) {
            accountBalance -= amount;
        } else {
            std::cout << "Insufficient balance or invalid withdrawal amount." << std::endl;
        }
    }

    // Member function to calculate and deposit interest for one year
    void calculateAndDepositInterest() {
        double interest = accountBalance * interestRate;
        accountBalance += interest;
    }

    // Member function to display account information
    void displayAccountInfo() {
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Balance: Rs. " << accountBalance << std::endl;
    }

    // Getter function to retrieve the account balance
    double getBalance() const {
        return accountBalance;
    }

    // Static member function to get the total interest paid across all accounts
    static double getTotalInterestPaid() {
        return totalInterestPaid;
    }

private:
    std::string accountHolderName;
    int accountNumber;
    double accountBalance;
    double interestRate;

    // Static variable to keep track of total interest paid across all accounts
    static double totalInterestPaid;
};

// Initialize the static member variable totalInterestPaid
double SavingsAccount::totalInterestPaid = 0.0;

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Create 100 SavingsAccount objects with random balances
    SavingsAccount accounts[100];
    for (int i = 0; i < 100; ++i) {
        double balance = rand() % 99001 + 1000;  // Random balance between 1000 and 100000
        accounts[i] = SavingsAccount("Account Holder " + std::to_string(i + 1), i + 1, balance);
    }

    // Calculate and deposit interest for one year for each account
    for (int i = 0; i < 100; ++i) {
        accounts[i].calculateAndDepositInterest();
    }

    
    double totalInterest = 0.0;
    for (int i = 0; i < 100; ++i) {
        accounts[i].displayAccountInfo();
        totalInterest += (accounts[i].getBalance() - 1000) * accounts[i].interestRate;
    }

    std::cout << "Total Interest Paid to All Accounts: Rs. " << totalInterest << std::endl;

    return 0;
}
