// CHRISTO REJI SAM
// CYCLE 1
//Program 3: Define a class to represent bank account. Include members like name of
//depositor, account no, Type of account, balance amount in the account.
//Write C++ program with member functions to
//a)	Assign initial values
//b)	To deposit an account
//c)	To withdraw an amount after checking the balance
//d)	To display name and balance


// PROGRAM


#include <iostream> using namespace std;
class Bank
{
private:
      char name[30];
       int accountNumber;
       float balance;
       char accType[30];
public:
    void init()
    {
        cout << "\n Enter the Name of the Depositor: ";
        cin >> name;
        cout << "\n Enter the account number: ";
        cin >> accountNumber;
        cout << "\n Enter the type of Account: ";
        cin >> accType;
        balance = 2000; // Minimum Amount
        cout << "\n Initialized the bank Account with Minimum Balance: " << balance;
    }
    void accDetails()
    {
        cout << "\n ----Account Details----";
        cout << "\n Name: " << name;
        cout << "\n Balance: " << balance;
        cout << "\n -----------------------";
    }
    void deposit()
    {
        int depositedAmount;
        cout << "\n Enter the ammount to deposit to the account with account number:
" << accountNumber << endl;
       cin >> depositedAmount;
       if (depositedAmount < 0)
            cout << "\n Deposited money cannot be negative number! Try Again!";         else
        {
            balance += depositedAmount;
            cout << "\n Current Balance: ";
            accDetails();
        }
    }
    void withdraw()
    {
        int moneyWithdrawed;
        cout << "\n Current balance for account with account number" <<
accountNumber << endl;
        accDetails();
        cout << "\n Money to be withdrawn: ";
        cin >> moneyWithdrawed;
        if (moneyWithdrawed < 0)
            cout << "\n Money to Withdraw cannot be negative!";
        else if (balance - moneyWithdrawed < 2000)
            cout << "\n Insufficient Balance! Try Again!";
        else
        {
            balance -= moneyWithdrawed;
            cout << "\n Money Withdrawn Successfully";
            cout << "\n Current Balance: " << balance;
        }     }
} account;
int main()
{
    cout << "\n Enter the details of the account holder first: \n";
    account.init();
    char ch;
    int choice;
label:
    cout << "\n-------Bank Interface-------";
    cout << "\n 1. Deposit";
    cout << "\n 2. Withdraw";
    cout << "\n 3. Display Account Details";
    cout << "\n ---------------------------";
    cout << "\n Enter your choice: (1, 2 or 3)  ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        account.deposit();
        break;
    case 2:
        account.withdraw();
        break;
    case 3:
        account.accDetails();
        break;
    default:
        cout << "\n Invalid Choice! Try Again!";
    }
    cout << "\n Do you want to continue? (y/N)";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        goto label;
    return 0;
}
