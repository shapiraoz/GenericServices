/*
 * UtilsFunctions.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: oz
 */

#include "UtilsFunctions.h"
#include <stdlib.h>
#ifdef BOOST
#include <boost/lexical_cast.hpp>
#endif

UtilsFunctions::UtilsFunctions() {
	// TODO Auto-generated constructor stub

}

UtilsFunctions::~UtilsFunctions() {
	// TODO Auto-generated destructor stub
}


int UtilsFunctions::GetRandomNumber()
{
	srand (time(NULL));
	return rand();
}

std::string UtilsFunctions::GetRandomNumberSTR()
{
#ifdef BOOST
	int number = GetRandomNumber();
	return boost::lexical_cast<std::string>(number);
#else
	char result[16];
	sprintf ( Result, "%d", Number );
	return result;
#endif


}
