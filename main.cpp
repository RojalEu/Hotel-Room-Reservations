 /*========================================================================================================================================================
Authors: Jacqueline Comrie, Rojal Euter, Jamie Chevannes, Kadecia Briscoe, Jevaughn Dawes, Salema Afflick, Ryheem Clarke
Date:May 17, 2021
Purpose: To write a C++ program that reserve rooms in a hotel.
=========================================================================================================================================================*/




#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

class HotelRoom
{
public:
    //Accessor functions
    int Get_Number();                                   // Note that this will get the room number
    int Get_Capacity();                                // Note that this will get the maximum room capacity
    int Get_Status();                                 // Note that this will get the status of the room
    int Get_Rate();                                  //Note that this will get the room rate
    int Change_Status(int capacity);                //Note that this will change the status of the room

    //void Add_Room();                            //Note that this  allows receptionist to add rooms
    void Change_Rate(double Rate);               //Note that this will change room rate depending on season
    void Reserve_Room();                        //Note that this will reserves a room
    void Modify_Room();                        //Note that this  modifies room by amount of guests
    void View_Room ();                        //Note that this displays the available room

HotelRoom() {
    room_num=0;
    room_cap=0;
    daily_rate=150;
    occup_stat=0;
    season="Peak";
}
HotelRoom(int set_roomnum, int capacity, double room_rate)   //Note that this is constructor with 3 arguments
{

   room_num=set_roomnum;
   room_cap=capacity;
   daily_rate=room_rate;
   occup_stat=0;
   if (room_rate>150)             // Note that this if statement, if greater then 150 it will print season peak, if not it will print non-peak

   {
       season="Peak";
   }
   else {
    season="Non-Peak";
   }

}
private:
    int room_index;
    int room_num;
    int room_cap;
    int occup_stat;
    double daily_rate;
    string season;
};

void Add_Room(list<HotelRoom> &R)
{
    int Rnum, Rcap, season;
    double rate;
    int choice = 99;
    if(R.empty()) {

    while ( choice == 99)
    {
            cout << "\n\n\t\t\tADD ROOM\t\t\t\n\n";
            cout << "The room number for this room is: ";
            Rnum =  R.size()+1;
            cout << Rnum <<endl;
            cout << "Enter the maximum number of persons the room can accommodate: ";
            cin >> Rcap;
            cout << "Please enter Season 1- Peak, 2- Non-Peak: ";
            cin >> season;
                if(season == 1)
                {
                    rate = 175.00;
                }
                else
                {
                    rate = 150.00;
                }

            cout<<"\n Room Added Successfully!"<<endl;
            R.push_back(HotelRoom(Rnum, Rcap, rate));
            cout<<"Do You wish to Add another Room? Yes- 99  0- No"<<endl;
            cin >> choice;

            cout<<"Current Room List"<<endl;
            for(HotelRoom h : R) {
                h.View_Room();
            }
        }
    }
}



int main()
{
    list<HotelRoom> RoomList;

        //Note that this  void menu() will;
       // Create A fix Hotel Room Size of 10
      // HotelRoom Hotelroom1(147, 2, 175);
     //  HotelRoom Hotelroom2 (147, 2, 175);
    //   HotelRoom Hotelroom3 (10, 1, 150);

    int choice;

    do{
    int roomnum;

    cout<<" \n **************WELCOME TO THE HOTEL ROOM RESERVATION APP*******************"<<endl;
    cout<<" Select an option"<<endl;
    cout<<"0. Add a room"<<endl;
    cout<<"1. Reserve a room"<<endl;
    cout<<"2. Modify a room"<<endl;
    cout<<"3. View room"<<endl;
    cout<<"4. EXIT"<<endl;
    cin>>choice;

            if(choice == 0) {
                Add_Room(RoomList);
            }
            else if(choice == 1)
            {
                cout<<"--- Current Room List ---"<<endl;
                if(RoomList.empty()) {
                 cout<<"Please add some rooms."<<endl;
                 }
                 else {
                    for(HotelRoom h : RoomList) {
                    h.View_Room();
                }
                cout<<"\n Please enter the room number to Reserve: " ;
                cin>>roomnum;
                // Note that this will fetch the iterator of element with value 'the'
               for(HotelRoom &h : RoomList) {
                    if(h.Get_Number() == roomnum) {
                        h.Reserve_Room();
                    }
                }
                 }

            }
            else if(choice == 2)
            { cout<<"--- Current Room List ---"<<endl;
                if(RoomList.empty()) {
                 cout<<"Please add some rooms."<<endl;
                } else {
                for(HotelRoom h : RoomList) {
                    h.View_Room();
                }
                cout<<"\n Please enter the room number to Modify Season: " ;
                cin>>roomnum;
                //Note that this will fetch the iterator of element with value 'the'
               for(HotelRoom &h : RoomList) {
                    if(h.Get_Number() == roomnum) {
                        h.Modify_Room();
                    }
                }
                }
            }
              else if(choice == 3)
            {
                cout<<"--- Current Room List ---"<<endl;
                if(RoomList.empty()) {
                 cout<<"Please add some rooms."<<endl;

                } else {
                for(HotelRoom h : RoomList) {
                    h.View_Room();
                }
                }
            }

        }
        while (choice != 4);


   return 0;
}

void HotelRoom::View_Room()
{

    cout<<"\n Room Number: " << room_num;                                  //Note that this will display the room number
    cout<<"\t \n Capacity: "<<room_cap;                                   //Note that this will display the total capacity for the room
    cout<<"\t \n Rate: "<<daily_rate;                                    //Note that this will display the rate for the room
    cout<<"\t \n Season: "<<season<<endl;                               //Note that this will display the season
}
int HotelRoom::Get_Number()
{
    return room_num;
}

int HotelRoom::Get_Capacity()
{
    return room_cap;
}
int HotelRoom::Get_Status()
{
    return occup_stat;
}
int HotelRoom::Get_Rate()
{
    return daily_rate;
}
int HotelRoom::Change_Status(int capacity)
{
    if (capacity > room_cap)
    {
        return -1;
    }
    occup_stat=capacity;

    return 1;
}
void HotelRoom::Change_Rate(double Rate)
{
   daily_rate=Rate;
   if (Rate>150)
    season="Peak";

}

void HotelRoom::Reserve_Room()
{
   int num_guest;
   do {
   cout<<"Please enter the number of guests(number of guests should not exceed room capacity: "<< room_cap << ") : " <<endl;//ask to enter number of guests
   cin>>num_guest ;
   }
while (num_guest>room_cap);

Change_Status(num_guest);
View_Room();
                    //Note that this will change status of room to reflect the number of guests that just checked in

                   //Note that this will display information in a nice format
}
void HotelRoom::Modify_Room()
{
    double rate;
    int season;
    cout << "Please enter Season 1-Peak, 2-Off Peak";
            cin >> season;
                if(season == 1)
                {
                    rate = 175.00;
                }
                else
                {
                    rate = 150.00;
                }
    Change_Rate(rate);
    Reserve_Room();
}
