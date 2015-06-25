/*
 * XMLSerializer.h
 *
 *  Created on: Jun 16, 2015
 *      Author: oz
 */

#ifndef SERIALIZATION_XMLSERIALIZER_H_
#define SERIALIZATION_XMLSERIALIZER_H_


#include <string>
#include "ASerializer.h"
#include <boost/property_tree/xml_parser.hpp>

using namespace Elements;
namespace Serialization {

class XMLSerializer: public ASerializer {
public:
	XMLSerializer( IElement* elm) ;
	XMLSerializer( IElement* elm,const std::string & filePath);
	virtual ~XMLSerializer();

	virtual bool Serialize() ;
	virtual IElement* DeSerialize() ;

	virtual IElement* DeSerialize(const std::string& filePath);
	virtual bool Serialize(const std::string& filePath);

};

} /* namespace Serialization */

#endif /* SERIALIZATION_XMLSERIALIZER_H_ */
