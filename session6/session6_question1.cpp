#include <iostream>
#include "addressType.h"
#include "extPersonType.h"

int main()
{
	extPersonType me(
		"Bryn",
		"Ghiffar",
		6, 6, 2001,
		"friend",
		"Bell St",
		"Stanford",
		"York",
		"123ABC",
		"123123123");
	me.print();
}