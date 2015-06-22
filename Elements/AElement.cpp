/*
 * AElement.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: oz
 */
#include "AElement.h"

#include "../Serialization/ISerializer.h"

#include <string>
using namespace Serialization;

using namespace Elements ;
/*
template class AElement<std::string>;
template class AElement<int>;
*/
namespace Elements{
template <typename T>
bool AElement<T>::Save(){
	serialzersType::iterator it =  m_serializers.begin();
			for (; it != m_serializers.end(); ++it)
			{
				Serialization::ISerializer* item =  *it;
				item->Serialize();
			}
			return true;
}

template <>
bool AElement<std::string>::Save()
{
	serialzersType::iterator it =  m_serializers.begin();
		for (; it != m_serializers.end(); ++it)
		{
			Serialization::ISerializer* item =  *it;
			item->Serialize();
		}
		return true;
}
template <>
bool AElement<int>::Save(){
	serialzersType::iterator it =  m_serializers.begin();
		for (; it != m_serializers.end(); ++it){
			Serialization::ISerializer* item =  *it;
			item->Serialize();
		}
		return true;
}
}


