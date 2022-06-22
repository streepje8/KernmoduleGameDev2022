#include "TimeManager.h"

TimeManager& TimeManager::GetInstance()
{
	static TimeManager instance;
	return instance;
}
