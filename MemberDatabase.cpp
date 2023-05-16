// Member-function definitions for class MemberDatabase.
#include <iostream>
#include <fstream>
using namespace::std;

#include "MemberDatabase.h"

MemberDatabase::MemberDatabase()
{
   loadFromMemberFile();
}

MemberDatabase::~MemberDatabase()
{
   saveToMemberFile();
}

// returns true if userPassword match that of an Account with userIDNumber
bool MemberDatabase::authenticateUser( string userIDNumber, string userPassword )
{
	vector<MemberInfo>::iterator it = members.begin();
	for (; it != members.end(); it++)
	{
		if (it->getIDNumber() == userIDNumber)
		{
			if (it->getPassword()== userPassword)
			{
					return true;		
			}
			else
				return false;
		}
	}
	return false;

}

// returns true if there is an Account containing userIDNumber
bool MemberDatabase::exist( string &userIDNumber )
{
	vector<MemberInfo>::iterator it = members.begin();
	for (; it != members.end(); it++)
		if (it->getIDNumber() == userIDNumber)	
			return true;
	return false;
}

// add newMember at the end of members
void MemberDatabase::pushBack( MemberInfo &newMember )
{
   members.push_back( newMember );
}

// loads members from the file MemberInfo.dat
void MemberDatabase::loadFromMemberFile()
{
	MemberInfo temp;
	//MemberDatabase temp;
	ifstream file("MemberInfo.dat", ios::in || ios::binary);
	while (file.peek() != EOF)
	{
		file.read(reinterpret_cast<char*>(&temp), sizeof(MemberInfo));
		members.push_back(temp);
	}
	file.close();
}

// stores members into the file MemberInfo.dat
void MemberDatabase::saveToMemberFile()
{
	ofstream file("MemberInfo.dat", ios::out || ios::binary);
	for (int i = 0; i < members.size(); i++)
	{
		file.write(reinterpret_cast<char*>(&members[i]), sizeof(MemberInfo));
	}
	file.close();
}