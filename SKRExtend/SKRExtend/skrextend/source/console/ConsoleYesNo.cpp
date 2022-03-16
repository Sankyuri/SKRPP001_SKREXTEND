#include <iostream>
#include "../../include/console/ConsoleYesNo.h"




// Ask YesNo in [Y/N].
// If user was answered Yes then return true,
// answered No then return false.
bool skrex::ConsoleYesNo::ask()
{
	while (true)
	{
		std::string strin;
		std::cin >> strin;
		char c = '\0';
		for (unsigned int i = 0; i < strin.size(); ++i)
		{
			c = strin[i];
			if ( ! std::isspace( c ))
			{
				break;
			}
		}
		switch ( std::tolower( c ) )
		{
			case 'y':
				return true;
			case 'n':
				return false;
			// If strin is empty or c is not [Y/N].
			default:
				continue;
		}
	}
}



