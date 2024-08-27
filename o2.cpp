// OOP Assignment No.2

// Enter the book details like title, author, publisher, price and no of copies 0f each book.  Search the particular book and accept that copied, if available then display the   total price of book copies. 


#include <iostream>
#include <cstring>
using namespace std;

int n;

class books 
{
    int pz, sp;
    char *tt, *aut, *pub;

public:
    books(); // Constructor
    
    ~books(); // Destructor
    
    void accept();
    void display();
    void search();
}b[100];

books::books() 
{
    // Allocate memory for strings
    tt = new char;
    aut = new char;
    pub = new char;
}

books::~books() 
{
    // Deallocate memory
    delete[] tt;
    delete[] aut;
    delete[] pub;
}

void books::accept() 
{
    cout << "\nEnter the Title: ";
    cin >> tt;
    cout << "Enter the Author Name: ";
    cin >> aut;
    cout << "Enter the Publisher Name: ";
    cin >> pub;
    cout << "Enter the price: ";
    cin >> pz;
    cout << "Enter the No of copies: ";
    cin >> sp;
}

void books::display() 
{
    cout << "\n" << tt << "\t" << aut << "\t" << pub << "\t" << pz << "\t" << sp;
}

void books::search() 
{
    int f = 0, total, cp = 0;
    char *t, *a;
    t = new char;
    a = new char;

    cout << "Enter the title of the book you want to search: ";
    cin >> t;
    cout << "Enter the author of the book: ";
    cin >> a;

    for (int i = 0; i < n; i++) 
    {
        if (strcmp(t, b[i].tt) == 0 && strcmp(a, b[i].aut) == 0) 
        {
            f = 1;
            cout << "\nBook present in the shop.";
            cout << "\nEnter the number of copies: ";
            cin >> cp;

            if (cp <= b[i].sp) 
            {
                total = b[i].pz * cp;
                cout << "The total price of book copies is: " << total << endl;
                b[i].sp -= cp;
            } 
            else 
            {
                cout << "Not enough copies are available." << endl;
            }
            break;
        }
    }

    if (!f) 
    {
        cout << "Given book is not available." << endl;
    }
}

int main() 
{
    int choice=1;

    while (choice != 4) 
    {
        cout << "\n\nMenu.\n1. Accept Book Record.\n2. Display Record.\n3. Search\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter the number of records you want to create: ";
                cin >> n;
                for (int i = 0; i < n; i++) 
                {
                    b[i].accept();
                }
                break;

            case 2:
                cout << "\nName\tAuthor\tPublisher\tPrice\tCopies";
                for (int i = 0; i < n; i++) 
                {
                    b[i].display();
                }
                break;

            case 3:
                b[0].search();  // Updated to correct function call
                break;

           case 4:
        	
            	choice=4;
            	break;

            default:
                cout << "Invalid choice\n";
                break;
        }

     
    }

    return 0;
}
