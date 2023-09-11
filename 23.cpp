#include <iostream>
#include<string>
using namespace std;

class SavingsAccount{
    public:
    const string name;
    const int accno;
    int balance;
    static int rate;
    static int totalInterest;
    
    SavingsAccount() : name("") , accno(0) {
        balance =0;
    }
    SavingsAccount( string n,  int acc, int bal) : name(n), accno(acc){
        bal = balance;
    }

    int withdraw(int amount){
        if (balance - amount < 1000){
            cout << "insufficient balance"<<endl;
            return balance;
        }
        return balance -= amount;
        
    }
    int deposit(int amount){
        return balance +=amount;
    }
    int interestpaid(){
        int interest = (rate)/100 * balance;
        totalInterest += interest;
        return interest;
    }
    void display(){
        cout <<"name: "<<name<<endl;
        cout << "account number: "<<accno<<endl;
        cout << "balance: " << balance << endl;
        cout << "interest paid: " << interestpaid() << endl;
        
    }
};

int SavingsAccount :: rate =7;
int SavingsAccount :: totalInterest=0;

int main(){
    const int size =10;
    SavingsAccount arr[size];
    for (int i=0; i<size; i++){
        string name = to_string(i+1);
        arr[i] = SavingsAccount(name, 1000000+i, 1000+i);
    }

}