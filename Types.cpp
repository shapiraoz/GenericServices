/*
 * Tyeps.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: oz
 */
#include "Types.h"
#include <typeinfo>


Types*  Types::m_instance = NULL;
Types::Types(){

	m_types[typeid(int).name()]="int";
	m_types[typeid(std::string).name()]="std::string";
	m_types[typeid(float).name()]="float";
}

Types& Types::GetInstance(){
	if (m_instance==NULL)
	{
		m_instance = new Types();
	}
	return *m_instance;
}

std::string Types::GetType(std::string name){
	if (m_types.find(name) == m_types.end()) return "";
	return m_types[name];
}




