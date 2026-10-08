/*
 * Exercise: Const, References and Initializer Lists
 *
 * Create a class called BankAccount with the following private members:
 *
 * - string owner
 * - int accountNumber
 * - double balance
 *
 * The class must provide:
 *
 * 1. A constructor that receives all three values.
 *    Use a member initializer list to initialize the members.
 *
 * 2. Getters:
 *    - getOwner()
 *    - getAccountNumber()
 *    - getBalance()
 *
 *    The getters must be const member functions.
 *
 * 3. A method:
 *    - deposit(double amount)
 *
 *    This method must add the amount to the account balance.
 *
 * 4. A method:
 *    - withdraw(double amount)
 *
 *    This method must subtract the amount from the balance only if
 *    there is enough money available.
 *
 * 5. A function outside the class:
 *
 *    void printAccount(const BankAccount& account)
 *
 *    This function must display all account information without
 *    modifying the object.
 *
 * In main():
 * - Create a BankAccount object using the constructor.
 * - Display the account using printAccount().
 * - Deposit some money.
 * - Display the account again.
 * - Withdraw some money.
 * - Display the account again.
 *
 * Requirements:
 * - The data members must be private.
 * - Use a member initializer list in the constructor.
 * - Getters must be const member functions.
 * - printAccount() must receive the object using const reference.
 * - Do not access private members directly from main().
 * - Do not create a copy of the BankAccount inside printAccount().
 */

#include <iostream>
#include <string>

using namespace std;


class BankAccount{

    private:
        string owner;
        int accountNumber;
        double balance;
    
    public:
        BankAccount(string owner, int accountNumber, double balance) 
            : owner(owner),
              accountNumber(accountNumber),
              balance(balance)
        {}
        
        string getOwner() const;
        int getaccountNumber() const;
        double getBalance() const;
        void depositValue(double value);
        void withdrawValue(double value);        
};

string BankAccount::getOwner() const{
    return this->owner;
}

int BankAccount::getaccountNumber() const{
    return this->accountNumber;
}

double BankAccount::getBalance() const{
    return this->balance;
}

void BankAccount::depositValue(double value){
    this->balance += value;
}

void BankAccount::withdrawValue(double value){
    if (this->balance >= value){
        this->balance -= value;
    }
}

void printAccount(const BankAccount& account){
    cout<<"Informações da conta"<<endl;
    cout<<"Owner: "<< account.getOwner()<<" Numero da conta: "<<account.getaccountNumber()<<" Saldo: "<<account.getBalance()<<endl;
}

int main(void){

    BankAccount conta = {"Fabricio",12345, 10000};

    printAccount(conta);
    conta.depositValue(500);
    printAccount(conta);
    conta.withdrawValue(500);
    printAccount(conta);

    return 0;
}