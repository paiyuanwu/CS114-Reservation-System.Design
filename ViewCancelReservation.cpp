// Member-function definitions for class ViewCancelReservation.
#include <iostream>
#include <iomanip>

using namespace::std;

#include "ViewCancelReservation.h"

extern int inputAnInteger( int begin, int end );

ViewCancelReservation::ViewCancelReservation( string userIDNumber,
                                              ReservationDatabase &theReservationDatabase )
   : Transaction( userIDNumber, theReservationDatabase )
{
}

// reservation enquiry/canceling
void ViewCancelReservation::execute()
{
   // 把原本的程式反註解回來

    ReservationDatabase x;//新增
    string id;//新增
    vector<Transaction>::iterator it ;
    int choice;
    if(getReservationDatabase().empty())//修改
    {
        cout << "You have no reservations! " << endl;
        
    }
    else //if(x.exist(id)) //if(resevationd.exite())  //修改
    {
        getReservationDatabase();

        do cout << "Choose a reservation to cancel(0: keep all reservations) :";
        while ((choice = inputAnInteger(0, 5)) == -1);//新增
        //ReservationDatabase::cancelReservation; //刪除
        if (choice == 0)//新增
            return;
       
        x.cancelReservation(id, choice); //新增
        cout << "Reservation Cancelled!" << endl;
        
    }

}