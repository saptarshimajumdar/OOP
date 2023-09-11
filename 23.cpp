#include<string>
#include<iostream>
#include<random>
#include<vector>
using namespace std;

class SavingsAccount{
    public:
    string name;
    const int accno;
    double balance;
    static int accnumbers;
    static double rate;
    static double totalInterest;
    
    

    SavingsAccount(  string n, double bal) : name(n), accno(accnumbers) ,balance(bal){
       accnumbers++;
    }

    double withdraw(double amount){
        if (balance - amount < 1000){
            cout << "insufficient balance"<<endl;
            return balance;
        }
        return balance -= amount;
        
    }
    double deposit(double amount){
        return balance +=amount;
    }
    double interestpaid(){
        double interest = (rate)/100 * balance;
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

double SavingsAccount :: rate =7.0;
double SavingsAccount :: totalInterest=0.0;
int SavingsAccount :: accnumbers=100001;

int main(){

    const int size =3;
    vector <SavingsAccount *> accounts;
    string name;
    for (int i  = 0; i < size; i++){
        cout << "enter name for the account " << SavingsAccount::accnumbers << endl;
        cin >> name;
        SavingsAccount* temp = new SavingsAccount(name, 1000+i);
        accounts.push_back(temp);
    }

    for (int i  = 0; i < size ;i++){
        accounts[i]->display();
    }
    cout << "total interest paid out = "<< SavingsAccount:: totalInterest << endl;
}
