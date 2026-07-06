#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char accountHolder[50];
    double balance;
    char accountType[20];
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Limit reached.\n");
        return;
    }
    
    BankAccount newAccount;
    newAccount.accountNumber = totalAccounts + 1001;
    
    printf("Enter account holder name: ");
    fgets(newAccount.accountHolder, sizeof(newAccount.accountHolder), stdin);
    newAccount.accountHolder[strcspn(newAccount.accountHolder, "\n")] = 0;
    
    printf("Enter initial balance: ");
    scanf("%lf", &newAccount.balance);
    getchar();
    
    printf("Enter account type (Savings/Checking): ");
    fgets(newAccount.accountType, sizeof(newAccount.accountType), stdin);
    newAccount.accountType[strcspn(newAccount.accountType, "\n")] = 0;
    
    accounts[totalAccounts] = newAccount;
    totalAccounts++;
    printf("Account created successfully! Account Number: %d\n\n", newAccount.accountNumber);
}

void displayAllAccounts() {
    if (totalAccounts == 0) {
        printf("No accounts found.\n\n");
        return;
    }
    
    printf("\n========== All Bank Accounts ==========\n");
    for (int i = 0; i < totalAccounts; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder: %s\n", accounts[i].accountHolder);
        printf("Balance: $%.2f\n", accounts[i].balance);
        printf("Account Type: %s\n", accounts[i].accountType);
        printf("-----------------------------------\n");
    }
    printf("\n");
}

void deposit(int accountNumber, double amount) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Deposited $%.2f successfully! New balance: $%.2f\n\n", 
                       amount, accounts[i].balance);
            } else {
                printf("Invalid amount. Please enter a positive value.\n\n");
            }
            return;
        }
    }
    printf("Account not found.\n\n");
}

void withdraw(int accountNumber, double amount) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrawn $%.2f successfully! New balance: $%.2f\n\n", 
                       amount, accounts[i].balance);
            } else if (amount > accounts[i].balance) {
                printf("Insufficient balance. Current balance: $%.2f\n\n", 
                       accounts[i].balance);
            } else {
                printf("Invalid amount. Please enter a positive value.\n\n");
            }
            return;
        }
    }
    printf("Account not found.\n\n");
}

void checkBalance(int accountNumber) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Holder: %s\n", accounts[i].accountHolder);
            printf("Account Balance: $%.2f\n\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n\n");
}

int main() {
    int choice, accountNumber;
    double amount;
    
    printf("========== Bank Account System ==========\n\n");
    
    while (1) {
        printf("Menu:\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Check Balance\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAllAccounts();
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                getchar();
                deposit(accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);
                getchar();
                withdraw(accountNumber, amount);
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                getchar();
                checkBalance(accountNumber);
                break;
            case 6:
                printf("Thank you for using Bank Account System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    
    return 0;
}
