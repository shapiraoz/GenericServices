/*
 * IElement.h
 *
 *  Created on: Apr 17, 2015
 *      Author: oz
 */

#ifndef ELEMENTS_IELEMENT_H_
#define ELEMENTS_IELEMENT_H_
#include <vector>

#include <stddef.h>

namespace Elements{



typedef int KeyType;

class IElement {
public:


	virtual ~IElement(){};
	virtual void* GetData() const= 0;
	virtual void SetData(const void * data) = 0;
	virtual std::vector<IElement*> GetElemnets() const= 0;
	virtual bool AddElemnet(KeyType key,const IElement& element) =0;
	virtual void GetElemnets(IElement** pOutElements) const= 0;
	virtual IElement* GetElement(const KeyType key) =0;
	virtual IElement* Clone() const= 0;
	virtual IElement* operator[] (KeyType key) = 0;
	virtual void operator = (void* data)=0;
	virtual void operator = (IElement* elm)=0;

};

};





#endif /* ELEMENTS_IELEMENT_H_ */
