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
/*
	virtual IElement* operator[] (IElement* elm)
	{
		subElmType::const_iterator it = m_subElements.begin();
		for (;it != m_subElements.end();++it)
		{
			if (it->second==elm)
			{
				return it->second;
			}
		}
		return NULL;
	}
*/

	virtual IElement* operator[](KeyType key){

		IElement* retElm=GetElement(key);

		if (!retElm){
				AddElemnet(key,new AElement<T>());
		}
		return  m_subElements[key];

	}
/*
	virtual void operator=(void* data){

		   T *d = (T*)data;
		   if (d)
			   m_data=*d;
	}
*/
	/*virtual IElement* operator=(IElement* elm){
		if (elm)
		{
			this->m_data = (*(T*)elm->GetData());

		}
		return this;
	}*/

	virtual IElement* operator = (const IElement* elm){
		if (elm){
			m_data= *((T*)elm->GetData());
		}
		return this;
	}
	/*
	virtual IElement* operator = (const AElement<T> & elm)
	{
		SetDataElm(*elm);
		return this;

	}*/


	//virtual void MergeElements(const std::map<K,EleType>& elements) ;


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
};

}; //Elements
#endif /* ELEMENTS_AELEMENT_H_ */
