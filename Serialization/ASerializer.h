/*
 * ASerializer.h
 *
 *  Created on: Jun 16, 2015
 *      Author: oz
 */

#ifndef SERIALIZATION_ASERIALIZER_H_
#define SERIALIZATION_ASERIALIZER_H_

#include <string>

#define BOOST 1
#if BOOST
#include <boost/property_tree/ptree.hpp>
using boost::property_tree::ptree;
#endif


#include "ISerializer.h"

namespace Serialization{

class ASerializer: public ISerializer {
public:
	ASerializer(IElement* elm):m_element(elm){};
	virtual ~ASerializer(){};
protected :

#if BOOST
	 ptree m_pt;
#endif
	 std::string m_filePath;
	 Elements::IElement* m_element ;
};
}
#endif /* SERIALIZATION_ASERIALIZER_H_ */
