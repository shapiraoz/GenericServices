/*
 * XMLSerializer.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: oz
 */

#include "XMLSerializer.h"
#include  <vector>
#include "../Utils/UtilsFunctions.h"


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

	return this->Serialize(m_filePath);
}

 IElement* XMLSerializer::DeSerialize()
 {

	return NULL;
}

 IElement* XMLSerializer::DeSerialize(const std::string& filePath )
 {

	 if (filePath.empty()) return false;
	 read_xml(filePath, m_pt);
	// m_pt.get

	 return NULL;
 }


 bool XMLSerializer::Serialize(const std::string& filePath ) {

	 if (m_element==NULL || filePath.empty()) return false;
	 	try
	 	{
	 		ptree & node =  m_pt.add("Element",m_element->GetDataSting());
	 		m_pt.add("Element.<xmlattr>.ID",UtilsFunctions::GetRandomNumberSTR());// replace in random...
	 		m_pt.add("Element.<xmlattr>.Name",m_element->GetName());
	 		m_pt.add("Element.<xmlattr>.Type",m_element->GetDataTypeStr());

	 		std::vector<IElement*> subelm = m_element->GetElemnets();

	 		std::vector<IElement*>::const_iterator it = subelm.begin();
	 		for (;it != subelm.end();++it ){

	 			IElement* elm = *it;
	 			node.add("Element",elm->GetDataSting());
	 			node.add("Element.<xmlattr>.Id",elm->GetIdStr());
	 			node.add("Element.<xmlattr>.Name",elm->GetName());
	 			//node.add_child("Elements",subNode);

	 		}
	 		//boost::property_tree::xml_writer_settings<char> settings('\t', 1);

	 		write_xml(m_filePath,m_pt);//,std::locale(),settings);
	 	} catch(...){

	 		return false;
	 	}


	 	return true;
 }






} /* namespace Serialization */
