#include <iostream>
#include <iomanip>
#include <fstream>
using namespace::std;

#include "Login.h"
#include "Registration.h"
#include "MemberDatabase.h"
#include "ReservationDatabase.h"

// input an integer in the range [ begin, end ]
int inputAnInteger( int begin, int end );

int main()
{
   cout << "Welcome to the Cashbox Party World!\n";

   MemberDatabase memberDatabase; // member information database
   ReservationDatabase reservationDatabase; // reservation information database
   Login login( memberDatabase, reservationDatabase );
   Registration registration( memberDatabase );

   bool userExited = false; // user has not chosen to exit
   int choice;

   // loop while user has not chosen option to exit system
   while( !userExited )
   {
      // show main menu and get user selection
      cout << "\n1 - Login";
      cout << "\n2 - Registration";
      cout << "\n3 - End\n\n";

      do
      {
          cout << "Enter your choice (1~3): ";
          //cin >> choice;
      }
      while( ( choice = inputAnInteger( 1, 3 ) ) == -1 );
      //cin.ignore();

      // decide how to proceed based on user's menu selection
      switch( choice )
      {
         // user chose to perform one of three transaction types
         case 1:
            // create new Login transaction
            login.execute();
            break;
         case 2:
            // create new Registration transaction
            registration.execute();
            break;
         case 3: // user chose to terminate session
            cout << "\nThank you! Goodbye!\n\n";
            userExited = true; // this session should end
            break;
         default: // user did not enter an integer from 1-3
            cout << "\nIncorrect choice!" << endl;
            break;
      }
   }

   system( "pause" );
}

int inputAnInteger( int begin, int end )
{
    char string[80];
    cin.getline(string, 80, '\n');

    if (strlen(string)=='0')
       exit(0);

    for (int i = 0; i < strlen(string); i++)
        if (string[i] < '0' || string[i]>'9')
            return -1;

   int temp= atoi(string);
   if (temp < begin || temp >end)
    return -1;
 
}