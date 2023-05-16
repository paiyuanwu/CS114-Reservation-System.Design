// Member-function definitions for class ReservationDatabase.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace::std;
#include "ReservationDatabase.h"

ReservationDatabase::ReservationDatabase()
{
   loadReservations();
}

ReservationDatabase::~ReservationDatabase()
{
   saveReservations();
}

bool ReservationDatabase::empty()
{
   return ( reservations.size() == 0 );
}

bool ReservationDatabase::exist( string IDNumber )
{
	vector<Reservation>::iterator it = reservations.begin();
	for (; it != reservations.end(); it++)
		if (it->getIDNumber() == IDNumber)
			return true;
	return false;
}

bool ReservationDatabase::allowed( string IDNumber, Date date, int hour )
{
	vector<Reservation>::iterator it = reservations.begin();
	for (; it != reservations.end(); it++)
	{
		if (it->getIDNumber() == IDNumber)
		{
			if (it->getDate() == date)
			{
				if (it->getHour() == hour)
					return true;
				else
					return false;
			}
		}
	}	
	return false;
}

int ReservationDatabase::displayReservationInfo( string IDNumber )
{
	vector<Reservation>::iterator it = reservations.begin();
	cout <<  "               Branch         Date    Hour    No of Customers" << endl;
	for (int i =0; it != reservations.end(); it++)
	{
		if (it->getIDNumber() == IDNumber)
		{
		   //<<i  //刪除
			/*cout<< setw(9) << it->getBranch() << setw(3)
			   << setw(3) << it->getDate() << setw(3)
			   << setw(3) << it->getHour() << setw(3)
			   << setw(3) << it->getNumCustomers() << endl;*/  //修改改用下面的方法加速訂正，但我知道如何使用「t->getDate()」這種東西
			cout<<"  "<< it->getBranch()<<"    "<< it->getDate()<<"      "<< it->getHour() <<"                 "<< it->getNumCustomers() <<2 << endl;
		   i++;
		}
	}
	return 0;
}

void ReservationDatabase::cancelReservation( string IDNumber, int n )
{
	vector<Reservation>::iterator it = reservations.begin();
	for (int i = 0,j=1; i < reservations.size(); i++,it++)
	{
		if (it->getIDNumber() == IDNumber&&j==n)
		{
			reservations.erase(it);
			
		}
		else
			j++;
	}

}

void ReservationDatabase::pushBack( Reservation newReservation )
{
   reservations.push_back( newReservation );
}

void ReservationDatabase::loadReservations()
{
	Reservation temp;
	ifstream file("ReservationInfo.dat", ios::in || ios::binary);
		while (file.peek()!=EOF)
		{
			file.read(reinterpret_cast<char*>(&temp), sizeof(Reservation));
			reservations.push_back(temp);
		}
		file.close();
}

void ReservationDatabase::saveReservations()
{
	ofstream file("ReservationInfo.dat", ios::out|| ios::binary);
	for(int i=0;i<reservations.size();i++)
	{
		file.write(reinterpret_cast<char*>(&reservations[i]), sizeof(Reservation));
	}
	file.close();
}