/*
 * UtilsFunctions.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: oz
 */

#include "UtilsFunctions.h"
#include <stdlib.h>


#include <boost/lexical_cast.hpp>


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
	int number = GetRandomNumber();
	return boost::lexical_cast<std::string>(number);

}
