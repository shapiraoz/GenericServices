/*
 * XMLSerializer.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: oz
 */

#include "XMLSerializer.h"

namespace Serialization {


XMLSerializer::XMLSerializer( IElement* elm,const std::string & filePath):ASerializer(elm) {
	this->m_filePath = filePath;
}


XMLSerializer::XMLSerializer( IElement* elm) :ASerializer(elm)  {
	// TODO Auto-generated constructor stub

}

XMLSerializer::~XMLSerializer(){
	// TODO Auto-generated destructor stub
}

bool XMLSerializer::Serialize() {

	return false;
}

 IElement* XMLSerializer::DeSerialize(){

	return NULL;
}

 IElement* XMLSerializer::DeSerialize(const std::string& filePath )
 {
	 return NULL;
 }


 bool XMLSerializer::Serialize(const std::string& filePath ) {

 	return false;
 }






} /* namespace Serialization */
