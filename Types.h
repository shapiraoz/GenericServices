#ifndef __TYPES_H__
#define __TYPES_H__



#include <map>
#include <string>


class Types{
public :
	static Types& GetInstance();
	std::string GetType(std::string name);
	~Types();
private :
	Types();
	static Types* m_instance;
	std::map<std::string,std::string> m_types;


};

;


#endif
