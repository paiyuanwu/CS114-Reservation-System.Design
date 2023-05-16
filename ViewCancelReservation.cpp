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
   // ��쥻���{���ϵ��Ѧ^��

    ReservationDatabase x;//�s�W
    string id;//�s�W
    vector<Transaction>::iterator it ;
    int choice;
    if(getReservationDatabase().empty())//�ק�
    {
        cout << "You have no reservations! " << endl;
        
    }
    else //if(x.exist(id)) //if(resevationd.exite())  //�ק�
    {
        getReservationDatabase();

        do cout << "Choose a reservation to cancel(0: keep all reservations) :";
        while ((choice = inputAnInteger(0, 5)) == -1);//�s�W
        //ReservationDatabase::cancelReservation; //�R��
        if (choice == 0)//�s�W
            return;
       
        x.cancelReservation(id, choice); //�s�W
        cout << "Reservation Cancelled!" << endl;
        
    }

}