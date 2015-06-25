/*
 * IElement.h
 *
 *  Created on: Apr 17, 2015
 *      Author: oz
 */

#ifndef ELEMENTS_IELEMENT_H_
#define ELEMENTS_IELEMENT_H_
#include <vector>
#include <map>
#include <string>


#include <stddef.h>



typedef int KeyType;
namespace Serialization {
class ISerializer; //forward declaration
}
struct SerializationTo;

namespace Elements{

class IElement {
public:


	virtual ~IElement(){};
	virtual void* GetData() const= 0;
	virtual std::string GetDataSting() const =0;
	virtual void SetData(const void * data) = 0;
	virtual std::vector<IElement*> GetElemnets() const= 0;
	virtual bool AddElemnet(KeyType key,const IElement* element) =0;
	virtual bool AddElemnet(IElement* element) =0;
	virtual void GetElemnets(IElement** pOutElements) const= 0;
	virtual IElement* GetElement(const KeyType key) =0;
	virtual IElement* Clone() const= 0;
	virtual IElement* operator[] (const KeyType key ) = 0;
	virtual bool RegisterSerializer(Serialization::ISerializer * serializer) =0;
	virtual bool Save() = 0;
	virtual bool ChangeName(const std::string & name) =0;
	virtual std::string GetName() const =0;
	virtual KeyType GetId() const= 0;
	virtual std::string GetIdStr() const =0;
	virtual IElement* operator = (const IElement* elm)=0;
	virtual IElement* operator = (std::pair<KeyType, IElement*> elm) =0;
	virtual std::string ToString()=0;
};


struct pair{

	KeyType key;
	IElement* elm;

public:
	pair(KeyType key_t, IElement* elm_t){
		key= key_t;
		elm =elm_t;
	}};


};





#endif /* ELEMENTS_IELEMENT_H_ */
