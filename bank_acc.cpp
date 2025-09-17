#include <iostream>
#include <string>
using namespace std;

class account {
protected:
    string cust_name;
    int acc_no;
    string acc_type;
    float balance;
public:
    void init_account(string name, int no, string type, float bal) {
        cust_name = name;
        acc_no = no;
        acc_type = type;
        balance = bal;
    }
    void deposit(float amt) {
        balance += amt;
        cout << "Deposited: " << amt << endl;
    }
    void display_balance() {
        cout << "Account No: " << acc_no << ", Name: " << cust_name
             << ", Type: " << acc_type << ", Balance: " << balance << endl;
    }
    float get_balance() { return balance; }
    void set_balance(float bal) { balance = bal; }
};

class sav_acct : public account {
public:
    void compute_and_deposit_interest(float rate, int years) {
        float interest = balance * rate * years / 100;
        cout << "Interest: " << interest << endl;
        balance += interest;
    }
    void withdraw(float amt) {
        if (amt > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amt;
            cout << "Withdrawn: " << amt << endl;
        }
    }
};

class cur_acct : public account {
    float min_balance = 1000;
    float service_charge = 100;
public:
    void withdraw(float amt) {
        if (amt > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amt;
            cout << "Withdrawn: " << amt << endl;
            check_min_balance();
        }
    }
    void check_min_balance() {
        if (balance < min_balance) {
            cout << "Balance below minimum! Service charge imposed: " << service_charge << endl;
            balance -= service_charge;
        }
    }
};

int main() {
    sav_acct s;
    cur_acct c;

    // Initialize accounts
    s.init_account("Alice", 101, "Savings", 5000);
    c.init_account("Bob", 201, "Current", 2000);

    // Savings account operations
    s.deposit(1000);
    s.compute_and_deposit_interest(5, 2); // 5% for 2 years
    s.withdraw(2000);
    s.display_balance();

    // Current account operations
    c.deposit(500);
    c.withdraw(1800); // Should trigger penalty
    c.display_balance();

    return 0;
}