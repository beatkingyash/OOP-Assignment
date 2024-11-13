// CIA Practice  Assignment 

/*	To creat database of personal information [const & dest]
	ex. name, DOB, height, weight, driving L no., policy no.       */


#include<iostream>
#include<cstring>
using namespace std;

int i, n;

class PIS
{
	static int cnt;
	int pn, ht, wt;
	char *name, *dln, *add;
	
   public:
   	PIS()
   	{
   	  pn = 100;
   	  ht = 165;
   	  wt = 70;
   	  
   	  name = new char;
   	  dln = new char;
   	  add = new char;
   	  
   	  strcpy(dln,"ln 100");
   	  strcpy(name,"VVV");
   	  strcpy(add,"Nashik");
   	}
   	
   	PIS(int h, int w)
   	{
   	  ht = h;
   	  wt = w;
   	}
   	
   	PIS(PIS &ss)
   	{
   	  ht = ss.ht;
   	  wt = ss.wt;
   	}
   	
   	
   void accept()
   {
   	cnt++;
   	cout<<"\nEnter the name: ";
	cin>>name;
	cout<<"Enter the address: ";
	cin>>add;
	cout<<"Enter the Driving L No.: ";
	cin>>dln;
	cout<<"Enter the height: ";
	cin>>ht;
	cout<<"Enter the weight: ";
	cin>>wt;
	cout<<"Enter the policy no: ";
	cin>>pn;
   }
   
   void display();
   
  ~PIS()
  {
    delete name;
    delete add;
    delete dln;
    cout<<"\nDestructor is called.\n";
  }
  
  static void discnt()
  {
     cout<<"\nTotal record in database is: "<<cnt;
  }
  
  friend void search(PIS s[]);

}s[10];


int PIS::cnt;

void search(PIS s[])
{
  int p, flag = 0;
  cout<<"\nEnter the PN: ";
  cin>>p;
  
  
   for(i = 0; i < 10; i++)
   {
  if(s[i].pn == p)
  {
     flag = 1;
        break;
  }
  }
  
  if(flag == 1)
  {
        cout<<"\nRecord is Found.";
   }
  else
  {
     cout<<"\nRecord is Not Found.";
  }
}


inline void PIS::display()
{
   cout<<"\n"<<name<<"\t"<<add<<"\t"<<dln<<"\t"<<ht<<"\t"<<wt<<"\t"<<pn;
}



int main()
{
    int choice=1;

    while(choice != 5)
    {
        cout << "\n\nMenu.\n1.Accept the record.\n2.Display the record.\n3.count record.\n4.Search Record.\n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter the number of records you want to create: ";
            cin >> n;
            for(i = 0; i < n; i++)
            {
                s[i].accept();
            }
            break;

        case 2:
            cout << "\nName\tadd\tdriln\theit\tweit\tpolicn\n";
            for(i = 0; i < n; i++)
            {
                s[i].display();
            }
            break;
            
        case 3:
        	PIS::discnt();
        	break;
        	
        case 4:
        	search(s);
        	break;
        	
        case 5:
        	
            	choice=5;
            	break;

            default:
                cout << "Invalid choice\n";
                break;
            
            }
    }

    return 0;
}
