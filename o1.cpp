#include <iostream>
using namespace std;

class mybank 
{
private:
    int accno, amt;
    string name;

public:
    void accept();
    void display();
    void withdraw();
    void deposit();
   //mybank() : accno(0), amt(0), name("") {}  // Constructor to initialize members
mybank()
{
accno=100;
amt=1000;
name="mybank";
}
} m[100];

void mybank::accept() 
{
    cout << "\nEnter your name: ";
    cin >> name;
    cout << "Enter the account no.: ";
    cin >> accno;
    cout << "Enter the amount: ";
    cin >> amt;
}

void mybank::display() 
{
    cout << "\n" << name << "\t" << accno << "\t" << amt;
}

void mybank::withdraw() 
{
    int ac, am;
    cout << "\nEnter account number: ";
    cin >> ac;
    

    bool found = false;
    for (int i = 0; i < 100; i++) 
    {
        if (m[i].accno == ac) 
        {
            found = true;
            
            cout << "Enter amount you want to withdraw: ";
    	    cin >> am;
    	    
            if (am <= m[i].amt) 
            {
                m[i].amt -= am;
                cout << "The withdrawal amount is: " << am;
                cout << "\nThe present balance in account no " << ac << " is " << m[i].amt;
            } 
            
            else 
            {
                cout << "Insufficient funds.";
            }
            break;
        }
    }
    
    if (!found) 
    {
        cout << "Account not found.\nPlease Enter Valid Account Number.";
    }
}

void mybank::deposit() 
{
    int acc, amt;
    cout << "\nEnter account no: ";
    cin >> acc;
    

    bool found = false;
    for (int i = 0; i < 100; i++) 
    {
        if (m[i].accno == acc) 
        {
            found = true;
            
            cout << "Enter amount you want to deposit: ";
    	    cin >> amt;
    	    
            m[i].amt += amt;
            cout << "The deposited amount is: " << amt;
            cout << "\nThe present balance in account no " << acc << " is " << m[i].amt;
            break;
         }
     }
    
    if (!found) 
    {
        cout << "Account not found.\nPlease Enter Valid Account Number.";
    }
}


int main() 
{
    int n, choice =1;

    while (choice != 5) 
    {
        cout << "\n\nMenu.\n1. Accept data\n2. Display data\n3. Withdraw amount\n4. Deposit amount\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter the number of accounts you want to create: ";
                cin >> n;
                for (int i = 0; i < n; i++) 
                {
                    m[i].accept();
                }
                break;

            case 2:
                cout << "\nName\tAccNo\tAmount";
                for (int i = 0; i < 100; i++) 
                {
                    m[i].display();
                }
                break;

            case 3:
                m[0].withdraw();  
                break;

            case 4:
                m[0].deposit();   
                break;

            case 5:
            	choice=5;
            	break;

            default:
                cout << "Invalid choice";
                break;
        }
    }

    return 0;
}

