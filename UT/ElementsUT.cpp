
#include <string>
#include <iostream>
#include <stdio.h>
#include "../Elements/AElement.h"
#include "../Serialization/XMLSerializer.h"


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

template<class T, class U>
bool testConcarnetElemnets(const T& data1, const U& data2)
{
	PRINT_LINE;
	bool ret=true;
	std::cout<<"test ConcarnetElemnets..."<<std::endl;

	IElement* elmA = new AElement<T>(data1);

	IElement* subElmA = new AElement<U>(data2);
	std::cout << "data on subElmA is " <<*((U*)subElmA->GetData()) <<std::endl;
	elmA[0]=subElmA;
	U* dataSubA=(U*) elmA[0].GetData();
	ret= (*dataSubA ==data2);

	std::cout << "test result sub elements by operators  ..." << (ret? "success" : "failed")<<std::endl;
	PRINT_LINE;
#define TEST_NUM_DATA 8
	std::cout <<"testing regular sub element using..." <<std::endl;
	elmA->AddElemnet(1,new AElement<T>(TEST_NUM_DATA));
	ret= (elmA->GetElement(1) && (*(T*)(elmA->GetElement(1)->GetData()))==TEST_NUM_DATA);
	std::cout << "results or normal subTesting ..."<<(ret ? "success" : "failed" )<<std::endl;

	return ret;
}

template<class T, class U>
void runToStringTest(T dataA,U dataB){
	//IElement* ae = new AElement<T>(dataA);
	AElement<T> t(dataA);
	IElement* typeB = new AElement<U>(dataB);
	t.AddElemnet(0,typeB);
	t.AddElemnet(1,new AElement<T>(dataA));
	t[1]->AddElemnet(0,new AElement<T>(dataA));

	//IElement* temp =new  AElement<T>(dataA);



	//a[1]=
	//a[1][0]= new AElement<T>(dataA); this sould work...
	std::cout<<"result print :" <<t.ToString();
}

int main()
{
	int t;




	testAbstartInterger<int>(6);
	testAbstartInterger<std::string>("koko");
	testConcarnetElemnets<int,std::string>(5,"colo");
	runToStringTest<int,std::string>(2,"sos");
	IElement* aq = new AElement<int>(5);
	aq->AddElemnet(new AElement<std::string> ("koko"));
	Serialization::ISerializer* ser = new Serialization::XMLSerializer(aq,"test.xml");
	ser->Serialize();
	//std::cin>>t;
}
