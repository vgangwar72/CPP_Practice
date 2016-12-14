#include "list.h"

int main ()
{

	list <int> test;
	test.push_back (1);
	test.push_back (2);
	test.push_back (3);
	test.push_back (4);
	test.push_back (5);

	test.print ();

	list <int> copy_test = test;
	copy_test.print ();
}
