/*
 * Iserializer.h
 *
 *  Created on: Jun 14, 2015
 *      Author: oz
 */

#ifndef SERIALIZATION_ISERIALIZER_H_
#define SERIALIZATION_ISERIALIZER_H_


#include "../Elements/IElement.h"
#include <string>


using namespace Elements;
namespace Serialization {

enum ESerizationTargets {
	eXML,
	Emax
};

struct SerializationTo {
	ESerizationTargets target;
	std::string path;
};

class ISerializer{
public :

	virtual ~ISerializer(){};
	virtual bool Serialize() =0;
	virtual Elements::IElement* DeSerialize() = 0;

	virtual IElement* DeSerialize(const std::string& filePath) =0;
	virtual bool Serialize(const std::string& filePath)=0;




};


}




#endif /* SERIALIZATION_ISERIALIZER_H_ */
