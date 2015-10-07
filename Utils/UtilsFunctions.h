/*
 * UtilsFunctions.h
 *
 *  Created on: Oct 7, 2015
 *      Author: oz
 */

#ifndef UTILS_UTILSFUNCTIONS_H_
#define UTILS_UTILSFUNCTIONS_H_
#include <string>


class UtilsFunctions {
public:
	UtilsFunctions();
	virtual ~UtilsFunctions();
	static int  GetRandomNumber();
	static std::string GetRandomNumberSTR();

};

#endif /* UTILS_UTILSFUNCTIONS_H_ */
