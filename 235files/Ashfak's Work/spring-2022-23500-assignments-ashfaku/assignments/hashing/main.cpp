#include <iostream>
#include "Node.h"
#include "Dictionary.h"
#include "Person.h"
#include "OList.h"
using std::cout;
using std::endl;
int main()
{
	Dictionary *d = new Dictionary();
	Person *p = new Person("People", "Idk", 1);
	try
	{
		//Check Insertions and Searches
		d->insertPerson(p);
		cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << endl;
		p = new Person("Ianame", "P.", 2);
		d->insertPerson(p);
		cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << endl;
		p = new Person("UTurn", "Turn", 3);
		d->insertPerson(p);
		cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << endl;
		p = new Person("Item", "Poke", 4);
		d->insertPerson(p);
		cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << endl;

		p = new Person("Win", "Lose", 5);
		d->insertPerson(p);
		cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << endl;
		cout << "Getting keys: " << d->getKeys() << endl;
		p = new Person("DNEXIST", ".", 6);
		cout << "Retrieving Nonexisting Person: " << d->retrievePerson(p)->get_name() << endl;
	}
	catch(...)
	{
		cout << "Got a person that is not in the list" << endl;
	}
	delete d;
	delete p;
	return 0;
}

