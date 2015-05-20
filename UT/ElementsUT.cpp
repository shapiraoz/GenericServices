
#include <string>
#include <iostream>
#include <stdio.h>
#include "../Elements/AElement.h"

using namespace Elements;

#define LINE "==============================================="
#define PRINT_LINE std::cout <<LINE  <<std::endl


//move to templet function.
template<class T>
bool testAbstartInterger(const T& item)
{
	bool ret=true;
	PRINT_LINE;
	std::cout<<"item is " <<item <<std::endl;
	std::cout<<"testing inserting and getting value"<<std::endl;

	IElement* testInterFace = new AElement<T>();
	testInterFace->SetData(&item);
	T* testVal=(T*) testInterFace->GetData();
	ret &= (*testVal== item);
	std::cout<<" set-get return :" << ((ret)? "pass" : "failed") << std::endl;
	if (!ret) return false;

	PRINT_LINE;
	std::cout <<"testing clone..."<<std::endl;
	IElement* cloneObj = testInterFace->Clone();
	printf("testInterFace address =0x%p when cloneObj is 0x%p\n",testInterFace,cloneObj);
	ret&=(testInterFace!=cloneObj);
	std::cout<<"clone object "<<(  !ret? " failed": "success" )<<std::endl;
	if (!ret) return false;
	PRINT_LINE;
	std::cout<<"testing values..."<<std::endl;
	ret&= (*((T*)testInterFace->GetData())== *((T*)cloneObj->GetData()));
	std::cout <<"values are " << (ret? "the same " : "not same!" )<< std::endl;
	std::cout <<"testInterFace value is " <<(*(T*)testInterFace->GetData())<<" while cloneObj value is " << (*(T*)cloneObj->GetData())<<std::endl;

	return ret;
}

int main()
{
	int t;
	testAbstartInterger<int>(6);
	testAbstartInterger<std::string>("koko");
	std::cin>>t;
}
