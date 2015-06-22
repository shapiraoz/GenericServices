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
#include <typeinfo>
#include "IElement.h"
#include <sstream>



namespace Elements{

//typedef SubElmsType
typedef std::map<KeyType,IElement*> subElmType;
typedef std::vector<Serialization::ISerializer*> serialzersType;


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

	virtual IElement* Clone() const{
		IElement* cloneElm = new AElement<T>(m_data);
		subElmType::const_iterator it = m_subElements.begin();
		for(;it !=m_subElements.end();++it)
		{
			cloneElm->AddElemnet(it->first,it->second->Clone());
		}
		return cloneElm;
	}

	virtual void GetElemnets(IElement** pOutElements) const //need to add this
	{
		std::vector<IElement*> retElm = GetElemnets();
		if (retElm.size()>0)
			pOutElements=&retElm[0];
	}

	virtual bool AddElemnet(KeyType key,const IElement* element){
		IElement* cloneObj = element->Clone();
		m_subElements.insert(std::make_pair(key,cloneObj));
		return true;
	}

	virtual IElement* GetElement(KeyType key)  {
		if (key>=0)
			return m_subElements[key];

		return NULL;
	}

	bool RegisterSerializer(Serialization::ISerializer * serializer){
		if (serializer!=NULL){
			m_serializers.push_back(serializer);
		return true;
		}
		return false;
	}

	virtual bool Save();

	virtual IElement* operator[](KeyType key){

		IElement* retElm=GetElement(key);

		if (!retElm){
				AddElemnet(key,new AElement<T>());
		}
		return  m_subElements[key];

	}


	virtual IElement* operator = (const IElement* elm){
		if (elm){
			m_data= *((T*)elm->GetData());
		}
		return this;
	}

	virtual std::string ToString()
	{
		std::stringstream strStream;
		if (m_subElements.size()==0){
			strStream<<m_data <<std::endl;

		}
		else {
			strStream<<"data:" <<m_data<<std::endl;
			strStream<<"\t|__sub Elements:" <<std::endl;
			subElmType::const_iterator it = m_subElements.begin();
			for (; it!=m_subElements.end(); ++it){
				strStream<<"["<<it->first<<"]"<<"|__"<<it->second->ToString();
			}
		}
		return strStream.str();
	}

	virtual IElement* operator = (std::pair<KeyType, IElement*> elm) {
		this->m_subElements.insert(elm);
		return this;
	}

protected :


private :
	void SetDataElm(IElement* elm)
	{
		if (elm)
		{
			this->m_data = (*(T*)elm->GetData());
		}
	}

	T m_data;
	subElmType m_subElements ;
	serialzersType m_serializers;
};

}; //Elements
#endif /* ELEMENTS_AELEMENT_H_ */
