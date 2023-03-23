//Project X
//Nicholas Ang
//Main function source file

#include <iostream>
#include <SmartPtr/SmartPtr.h>
using namespace std;
int main ()
{
cout << endl << "Testing SmartPtr Default ctor" << endl;
SmartPtr sp1;
sp1->setIntVal(1);
sp1->setDoubleVal(0.25);
cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
cout << endl << "Testing SmartPTr Copy ctor" << endl;

SmartPtr sp2 = sp1;
sp2->setIntVal(2);
sp2->setDoubleVal(0.5);
cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
cout << "Dereference Smart Pointer 2: " << *sp2 << endl;

cout << endl << "Testing SmartPtr Assignment operator" << endl;
SmartPtr sp3;
sp3 = sp1;
sp3->setIntVal(4);
sp3->setDoubleVal(0.0);
cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
cout << "Dereference Smart Pointer 2: " << *sp2 << endl;
cout << "Dereference Smart Pointer 3: " << *sp3 << endl;

cout << endl << "Testing SmartPtr Parameterized ctor with nullptr" << endl;
SmartPtr spNull(nullptr);

cout << endl << "Testing SmartPtr Copy ctor with nullptr SmartPtr" << endl;
SmartPtr spNull_cpy(spNull);

cout << endl << "Testing SmartPTr Assignment with nullptr SmartPtr" << endl;
SmartPtr spNull_assign;
spNull_assign = spNull;

cout << endl << "End-of-Scope, Destructors called in reverse order of SmartPtr creation" << endl << 
"(spNull_assign, spNull_cpy, spNull, sp3, sp2, sp1): " << endl;
return 0;
}
