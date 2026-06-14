// ==============================================
// ATM SYSTEM SIMULATION
// Description: A console-based ATM system with PIN verification,
//              balance management, deposit, withdrawal, and mini statement.
// ==============================================

#include<iostream>
using namespace std;

int main(){

  // ========== VARIABLE DECLARATIONS ==========
  int pin, attempts = 0;           // PIN input and attempt counter
  int fixedpin = 1234;             // Predefined correct PIN
  float balance = 5000.0;          // User's current balance
  float amount = 0;                // Generic amount variable (reserved)
  float deposit, withdraw;         // Deposit and withdrawal amounts
  char lastTransactionType = 'N';  // 'D' for Deposit, 'W' for Withdraw, 'N' for None
  float lastTransactionAmount = 0; // Stores last transaction amount
  bool isRunning = true;           // Controls main menu loop

  // ========== WELCOME SCREEN ==========
  cout<< "*************************************\n\t Welcome to ATM\t\n*************************************\n ";
  cout<< "Please enter your 4-digit PIN. \n";

  // ========== PIN VERIFICATION LOOP ==========
  // Allows 3 attempts before locking the ATM
  while(attempts < 3){
    cout<<"Enter PIN: ";
    cin>>pin;

    if (pin == fixedpin){
        cout<<"PIN Verified Successfully!\n";
        break;                     // Exit loop on successful verification
    } else {
        attempts++;
        cout<<"Incorrect PIN. Attempts left: "<< (3 - attempts) << "\n";
    }
  }

  // ========== LOCK ATM AFTER 3 FAILED ATTEMPTS ==========
  if (attempts == 3){
    cout<<"\nToo many wrong Attempts. ATM Locked.\n\tStart Again!!";
     return 0;                    // Exit program
  }

  // ========== MAIN MENU LOOP ==========
  int choice;
  do{
  cout<<"\nMAIN MENU\n";
  cout<<"1. Check Balance\n";
  cout<<"2. Deposit Money\n";
  cout<<"3. Withdraw Money\n";
  cout<<"4. Mini Statement\n";
  cout<<"5. Exit\n";
  cout<<"Enter your Choice: ";
  cin>>choice;

  switch (choice){

    // ---------- CASE 1: CHECK BALANCE ----------
    case 1:
    cout<<"Your current balance is: "<<balance<<endl;
    break;

    // ---------- CASE 2: DEPOSIT MONEY ----------
    case 2:
    cout<<"Enter amount to deposit: ";
    cin>>deposit;

    // Validate deposit amount
    if(deposit <= 0){
      cout<<"Invalid amount. Try again.\n";
    } else if (deposit > 5000) {                   
      cout<<"Error: You cannot deposit more than 5000 at once!\n";
    } else {
      balance = balance + deposit;                  // Update balance
      lastTransactionType = 'D';                    // Record transaction type
      lastTransactionAmount = deposit;              // Record transaction amount
      cout << "Deposit successful! New Balance: "<<balance<<endl;
    } 
    break;

    // ---------- CASE 3: WITHDRAW MONEY ----------
    case 3:
    cout <<"Enter amount to withdraw: ";
    cin >> withdraw;

    // Check sufficient balance and valid amount
    if (withdraw > 0 && withdraw <= balance) {
      balance = balance - withdraw;                 // Deduct from balance
      lastTransactionType = 'W';                    // Record transaction type
      lastTransactionAmount = withdraw;             // Record transaction amount
      cout<< "Withdraw Done! Remaining Balance: "<< balance << endl;
    } else {
      cout<<"Invalid amount. Insufficient balance or wrong input. Try again!\n";
    }
    break;

    // ---------- CASE 4: MINI STATEMENT ----------
    case 4:
    if(lastTransactionType == 'N'){
      cout<<"No Transaction performed yet.\n";
    } else {
      // Display last transaction details
      cout<<"Last transaction: ";
      if(lastTransactionType == 'D')
        cout<<"Deposit: ";
      else if (lastTransactionType == 'W')
        cout << "Withdraw: ";
      cout << lastTransactionAmount << endl;

      // Demonstrating increment/decrement operators
      cout << "Balance Preview (Postfix ++): " << balance++ << endl;
      cout << "Balance after Postfix: " << balance << endl;
      cout << "Balance Preview (Prefix --): " << --balance << endl;
      cout << "Balance after Prefix: " << balance << endl;
    }
    break;   

    // ---------- CASE 5: EXIT ----------
    case 5:
    cout<<"Thank you for using my ATM. Goodbye!\n*************************************\n";
    isRunning = false;                               // Exit the loop
    break;

    // ---------- DEFAULT: INVALID INPUT ----------
    default:
    cout<<"Invalid choice. Please try again.\n";
  }
 }
  while(isRunning);                                   // Repeat until user chooses Exit

  return 0;                                           // Successful program termination
}
