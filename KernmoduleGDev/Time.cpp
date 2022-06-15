#include "Time.h"

Time& Time::GetInstance()
{
	static Time instance;
	return instance;
}
