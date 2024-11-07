// OOP Assignment No.4



#include <iostream>
using namespace std;


class Student	// Base class student
{
protected:
    int roll;

public:
    string prn, name, address, Class;

    void accept();
};


class Test : virtual public Student 	// Derived class test from the base class student
{
public:
    int DSPS_CIA, OOP_CIA, COA_CIA, DM_CIA, DELD_CIA;
    int DSPS_ES, OOP_ES, COA_ES, DM_ES, DELD_ES;

    void acceptMarks();
};


class Sport : public virtual Student 	// sports class derived from student class
{
public:
    string sportName, sportGrade;

    void acceptSportDetails();
};


class Result : public Test, public Sport 	// result class derived from test and sport
{
public:
    void displayAll();
};

void Student::accept() 
{
    cout << "\nEnter the name of the student: ";
    cin >> name;
    cout << "Enter the PRN: ";
    cin >> prn;
    cout << "Enter the address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter the Class: ";
    cin >> Class;
    cout << "Enter the Roll no.: ";
    cin >> roll;
}

void Test::acceptMarks() 
{
    cout << "Enter the Marks of CIA Exam out of 40:\n";
    cout << "DSPS: ";
    cin >> DSPS_CIA;
    cout << "OOP: ";
    cin >> OOP_CIA;
    cout << "COA: ";
    cin >> COA_CIA;
    cout << "DM: ";
    cin >> DM_CIA;
    cout << "DELD: ";
    cin >> DELD_CIA;

    cout << "\nEnter the Marks of END SEMESTER Exam out of 60:\n";
    cout << "DSPS: ";
    cin >> DSPS_ES;
    cout << "OOP: ";
    cin >> OOP_ES;
    cout << "COA: ";
    cin >> COA_ES;
    cout << "DM: ";
    cin >> DM_ES;
    cout << "DELD: ";
    cin >> DELD_ES;
}

void Sport::acceptSportDetails() {
    cout << "Enter the sport name and the grade: ";
    cin >> sportName >> sportGrade;
}

void Result::displayAll() 
{
    cout<<"\n"<<name<<"\t"<<prn<<"\t"<<address<<"\t"<<Class<<"\n";
    cout << "\nSUBJECT NAME \t MAXIMUM MARKS \t OBTAIN MARKS\n";
    cout << "DSPS \t\t 100 \t\t" << DSPS_CIA + DSPS_ES << endl;
    cout << "OOP \t\t 100 \t\t" << OOP_CIA + OOP_ES << endl;
    cout << "COA \t\t 100 \t\t" << COA_CIA + COA_ES << endl;
    cout << "DM \t\t 100 \t\t" << DM_CIA + DM_ES << endl;
    cout << "DELD \t\t 100 \t\t" << DELD_CIA + DELD_ES << endl;
    cout << sportName << "\t\t- \t\t" << sportGrade << endl;
}

int main() 
{
    Result students[100];
    int choice, count = 0;
    string s1, s2, s3;

    while (true) 
    {
        cout << "\nMenu\n";
        cout << "1. Accept data of the student\n";
        cout << "2. Enter the marks of the student\n";
        cout << "3. Enter the sport details\n";
        cout << "4. Display the result of the student\n";
        cout << "5. Display all students details\n";
        cout << "6. Exit\n";
        
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        
        case 1:
            cout << "How many students data you want to accept: ";
            cin >> count;
            for (int i = 0; i < count; i++) 
            {
                students[i].accept();
            }
            break;
            
        case 2:
            cout << "Enter the PRN number of the student: ";
            cin >> s1;
            for (int i = 0; i < count; i++) 
            {
                if (s1 == students[i].prn) 
                {
                    students[i].acceptMarks();
                    break;
                }
            }
            break;
            
        case 3:
            cout << "Enter the PRN number of the student: ";
            cin >> s2;
            
            for (int i = 0; i < count; i++) 
            {
                if (s2 == students[i].prn) 
                {
                    students[i].acceptSportDetails();
                    break;
                }
            }
            break;
            
        case 4:
            cout << "Enter the PRN number of the student: ";
            cin >> s3;
            
            for (int i = 0; i < count; i++) 
            {
                if (s3 == students[i].prn) 
                {
                    students[i].displayAll();
                    break;
                }
            }
            break;
            
        case 5:
            for (int i = 0; i < count; i++) 
            {
                students[i].displayAll();
            }
            break;
            
        case 6:
               return 0;
        default:
            cout << "Wrong Choice! Try again.\n";
            break;
        }
    }

    return 0;
}
