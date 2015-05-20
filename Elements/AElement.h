/*
 * AElement.h
 *
 *  Created on: Apr 17, 2015
 *      Author: oz
 */

#ifndef ELEMENTS_AELEMENT_H_
#define ELEMENTS_AELEMENT_H_

#include <stddef.h>
#include <map>
#include <utility>
#include <vector>

#include "IElement.h"


namespace Elements{





//typedef SubElmsType
typedef std::map<KeyType,IElement*> subElmType;

template <typename T>
class AElement: public IElement {




public:
	AElement(){}
	AElement(const T& data):m_data(data){};


	virtual void* GetData() const {return (void*)&m_data;};
	virtual void SetData(const T& data) {m_data=data;};
	virtual void SetData(const void* data){
		T* newData= (T*)data;
		m_data =*newData;
	}

	virtual std::vector<IElement*> GetElemnets() const
	{
		std::vector<IElement*> retElms;
		subElmType::const_iterator it= m_subElements.begin();

		for (;it!= m_subElements.end();++it)
		{
			Elements::IElement* item = it->second;
			retElms.push_back(item);
		}

		return retElms;
	}

	virtual void GetElemnets(IElement** pOutElements) const //need to add this
	{
		std::vector<IElement*> retElm = GetElemnets();
		if (retElm.size()>0)
			pOutElements=&retElm[0];
	}


	virtual bool AddElemnet(KeyType key,const IElement& element){
		IElement* cloneObj = element.Clone();
		m_subElements.insert(std::make_pair(key,cloneObj));
		return true;
	}

	virtual IElement* GetElement(KeyType key)  {
		if (key>=0)
			return m_subElements[key];

		return NULL;
	}

	virtual Elements::IElement* GetElement(const void * key)  {
		if (key==NULL) return NULL;

		KeyType x= *((KeyType*)key);
		if (x>0){

			return m_subElements[x];

		}
		return NULL;

	}


	virtual AElement<T>* Clone() const{
		return new AElement<T>(*this);
	}
	//virtual void MergeElements(const std::map<K,EleType>& elements) ;

private :


	T m_data;
	subElmType m_subElements ;



};

}; //Elements
#endif /* ELEMENTS_AELEMENT_H_ */
