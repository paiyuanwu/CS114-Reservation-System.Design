// Member-function definitions for class Login.
#include <iostream>
#include <string>
using namespace::std;

#include "Login.h"
#include "Transaction.h"
#include "MakeReservation.h"
#include "ViewCancelReservation.h"

extern int inputAnInteger( int begin, int end );

Login::Login( MemberDatabase &theMemberDatabase, ReservationDatabase &theReservationDatabase )
   : memberDatabase( theMemberDatabase ),
     reservationDatabase( theReservationDatabase ),
     currentIDNumber( "" ) // no current ID number to start
{
}

void Login::execute()
{
    
    cout << "Enter your ID number: ";
    
    string id, password;
    do 
    {
        cin >> id;
    } while (inputAnInteger(0, 12) == -1);
   //cin.ignore();
   // cout << endl;
    if (memberDatabase.exist(id)==true)
    {
           // do
           // {
                cout << "Enter your password: ";
                cin >> password;
                cout << "Invalid password!" << endl;//新增

           // } while (inputAnInteger(0, 24) == -1);//刪除
            if (memberDatabase.authenticateUser(id, password))
            {
                performTransactions();
            }
        
    }
    else
        cout << "You are not a member!" << endl;
   cin.ignore();
}

// display the submenu and perform transactions
void Login::performTransactions()
{
    MakeReservation ln(currentIDNumber, reservationDatabase);
    int choice;
    bool userExited = false;
    while (!userExited)
    {
        // show main menu and get user selection
        cout << "1 - Make Reservation" << endl
            << "2 - Reservation Enquiry / Canceling" << endl
            << "3 - End" << endl
            << endl;
        do
        {
            cout << "Enter your choice (1~3): ";
            //cin >> choice;
        } while ((choice = inputAnInteger(1, 3)) == -1);
        //cin.ignore();

       
        switch (choice)
        {
           
        case 1:
            ln.execute();//修改
            break;
        case 2:
            reservationDatabase.displayReservationInfo(currentIDNumber);//新增
            //cout << "//ViewCancelReservation execute();";//註解
            break;
        case 3: 
            cout << "\nThank you! Goodbye!\n\n";
            userExited = true; // this session should end
            break;
        default: 
            cout << "\nIncorrect choice!" << endl;
            break;
        }
    }
   
}