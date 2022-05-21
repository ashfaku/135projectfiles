#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "Dictionary.h"
#include "OList.h"
#include "Person.h"

TEST_CASE("")
{
	Dictionary *d = new Dictionary();
	Person *p = new Person("People", "Hmm", 1);
	d->insertPerson(p);
	CHECK(d->retrievePerson(p)->get_name() == "People, Hmm");
	p = new Person("Mark", "K.", 2);
	d->insertPerson(p);
	CHECK(d->retrievePerson(p)->get_name() == "Mark, K.");

	p = new Person("Uturn", "Name", 3);
	d->insertPerson(p);
	CHECK(d->retrievePerson(p)->get_name() == "Uturn, Name");

	p = new Person("J", "I", 4);
	d->insertPerson(p);
	CHECK(d->retrievePerson(p)->get_name() == "J, I");

	p = new Person("P", "Q", 5);
	d->insertPerson(p);
	CHECK(d->retrievePerson(p)->get_name() == "P, Q");
	delete d;
	delete p;
}
