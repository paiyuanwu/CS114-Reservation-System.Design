// Member-function definitions for class Registration.
#include <iostream>
using namespace::std;

#include "Registration.h"

Registration::Registration( MemberDatabase &theMemberDatabase )
   : memberDatabase( theMemberDatabase )
{
}

void Registration::execute()
{
    string id, password, name;
    MemberInfo temp(id, name,password);
    cout << "Input your ID Number: ";
    cin >> id;
    temp.setIDNumber(id);
    if (memberDatabase.exist(id))
        cout << "You are already a member! " << endl;
    else
    {
        cout << "Input your Name: ";
        cin >> name;
        temp.setName(name);
        cout << "Choose a password: ";
        cin >> password;
        temp.setPassword(password);
        memberDatabase.pushBack(temp);
        cout << "Registration Completed!" << endl;
    }
}