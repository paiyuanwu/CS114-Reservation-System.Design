// Member-function definitions for class MakeReservation.
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

#include "MakeReservation.h"
#include "ReservationDatabase.h"

char branches[ 16 ][ 24 ] = { "", "Taipei Dunhua South", "Taipei SOGO",
                                  "Taipei Songjiang",    "Taipei Nanjing",
                                  "Taipei Zhonghua New", "Banqiao Guanqian",   
                                  "Yonghe Lehua",        "Taoyuan Zhonghua",    
                                  "Taoyuan Nankan",      "Zhongli Zhongyang",
                                  "Hsinchu Beida",       "Taichung Ziyou",
                                  "Chiayi Ren'ai",       "Tainan Ximen",
                                  "Kaohsiung Zhonghua New" };

extern int inputAnInteger( int begin, int end );

MakeReservation::MakeReservation( string userIDNumber,
                                  ReservationDatabase &theReservationDatabase )
   : Transaction( userIDNumber, theReservationDatabase )
{
}

// make reservation
void MakeReservation::execute()
{  //我把程式碼反註解回來。原本就寫好的
    string id, lacate;
    int hour, num;
    Date date;
    Reservation temp (id, lacate, date, hour, num);
    int choice;
    for (int i = 1; i < 16; i++)
        cout << i << ". " << branches[i] << endl;
    cout << endl;
    do
    {
        cout << "Enter your choice (0 to end): ";
        cout << endl;
    } while ((choice = inputAnInteger(1, 15)) == -1);
    temp.setBranch(branches[choice]);
    cout << endl;
    cout << "The current hour: " << "2021/01/10";
    cout << endl;
    cout << "Available days:" << endl;
    temp.setDate(date);
    do
    {
        cout << "Enter hour(0~23) :" << endl;
        cout << endl;
    } while ((hour = inputAnInteger(0,23 )) == -1);
    temp.setHour(hour);
    do
    {
        cout << " Enter the number of customers(1~20, 0 to end) :" << endl;
        cout << endl;
    } while ((num = inputAnInteger(0, 20)) == -1);
    temp.setNumCustomers(num);
    

  

}

void MakeReservation::computeCurrentDate( Date &currentDate, int &currentHour )
{
   int remainingSeconds = static_cast< int >( time( 0 ) ) + 8 * 60 * 60;

   int year = 1970;

   int secondsPerYear = 365 * 24 * 60 * 60;
   if( leapYear( year ) )
      secondsPerYear += 24 * 60 * 60;

   while( remainingSeconds >= secondsPerYear )
   {
      remainingSeconds -= secondsPerYear;
      year++;

      secondsPerYear = 365 * 24 * 60 * 60;
      if( leapYear( year ) )
         secondsPerYear += 24 * 60 * 60;
   }

   int days[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   if( leapYear( year ) )
      days[ 2 ] = 29;

   int month = 1;
   while( remainingSeconds >= days[ month ] * 24 * 60 * 60 )
   {
      remainingSeconds -= days[ month ] * 24 * 60 * 60;
      month++;
   }

   int day = remainingSeconds / ( 24 * 60 * 60 ) + 1;
   remainingSeconds %= 24 * 60 * 60;

   currentDate.setDate( year, month, day );

   currentHour = remainingSeconds / ( 60 * 60 );
//   currentHour = 23;
}

bool MakeReservation::leapYear( int year )
{
   return ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) );
}