// OOP Assignment No. 6

/* Create Television class to accept TV details like Model No. , Screen size , Price.
   Detect the exception in try block and throw in catch block, When ---
   1. Model No. > 4 digits
   2. 12 inches > Screen time > 70
   3. 0 > Price > 5000  		*/
   
   

#include<iostream>
using namespace std;

class Television
{
 int mn, sz, pz;
 
 public:
 
 friend void operator>>(istream&, Television &t1);
 friend void operator<<(ostream&, Television &t1);
}t1;


void operator>>(istream &din, Television& t1)
{
 int e;
 cout<<"\nEnter TV Model no.: ";
 din>>t1.mn;
 
 cout<<"Enter TV Screen size: ";
 din>>t1.sz;
 
 cout<<"Enter TV price: ";
 din>>t1.pz;
 
 
 try
 {
  if(t1.mn>9999 || t1.sz<12 || t1.sz>70 || t1.pz<0 || t1.pz>5000)
  {
    throw e;
  }
  
 
  }
  catch(int e)
  {
    cout<<"\nError Occurs.";
    t1.mn=0;
    t1.sz=0;
    t1.pz=0;
  }


}


void operator<<(ostream &dout, Television& t1)
{
 dout<<"\nTV model no. = "<<t1.mn;
 dout<<"\nTV screen size = "<<t1.sz;
 dout<<"\nTV price = "<<t1.pz;
}

int main()
{

 int ch;
 
 Television TV;
 
 while(true)
 {
   cout<<"\n\nMenu.\n1.Accept Record.\n2.Display Record.\n3.Exit.";
   cout<<"\nEnter your choice: ";
   cin>>ch;
   
   switch(ch)
   {
   case 1:
      cin>>TV;
      break;
      
   case 2:
      cout<<TV;
      break;
      
   case 3:
      return 0;
      
   default:
      cout<<"\nWrong choice.";
      break;
      
   }
 }
 
 return 0;

}
 

 

