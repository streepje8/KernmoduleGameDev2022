#include "TestClass.h"
TestClass& TestClass::GetInstance()
{
	static TestClass instance;
	return instance;
}