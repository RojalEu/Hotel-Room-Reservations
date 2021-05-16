# Hotel-Room-Reservations
//Ryheem Clarke
//may 12, 2021
//objective:  function to view room details.



#include <iostream>

using namespace std;


void display()
{
    cout<< "this function call works"<< endl;
}


//FUNCTION FOR DISPLAYING A PURTICULAR CUSTOMER`S RECORD


void hoteldisplay()
{

    system("cls");

    fin("Record.dat",ios::in);
    int r,flag;

    cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
    cin>>r;

    while(!fin.eof())
{

    fin.read((char*)this,sizeof(hotel));
    if(room_no==r)
{

  system("cls");
cout<<"\n Cusromer Details";
cout<<"\n ----------------";
cout<<"\n Room no:      "<<room_no;
cout<<"\n Name:         "<<name;
cout<<"\n Address:      "<<address;
cout<<"\n Phone no:     "<<phone;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";

getch();
fin.close();
}


//END OF DISPLAY FUNCTION

//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


void hotelrooms()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;

}

cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();

}



int main(){

    cout << "***ROOM VIEW***" << endl;
    
    int room_no;
    char name[30];
    char address[50];
    char phone[10];
    int room_capacity[6];
    int capacity_status[0];
    double daily_rate;
    
    
    display();
    hoteldisplay();
    hotelrooms();
    return 0;
}
