#include "MemoryManager.h"
#include "Debug.h"

MemoryManager& MemoryManager::GetInstance()
{
	static MemoryManager instance;
	return instance;
}

MemoryManager::MemoryManager() 
{
	//lookupTable = std::map<int, MemoryList>();
}

void MemoryManager::PushFunction()
{
	scopeDepth++;
	lookupTable[scopeDepth] = new MemoryList();
}

void MemoryManager::PopFunction()
{
	GetInstance().CleanScope(scopeDepth);
	lookupTable.erase(scopeDepth);
	scopeDepth--;
}

void MemoryManager::Clean()
{
	for (int i = scopeDepth; i >= 0; i--) {
		GetInstance().CleanScope(scopeDepth);
	}
}

void MemoryManager::CleanScope(int scope) 
{
	if (lookupTable.count(scope)) {
		lookupTable[scope]->Discard();
		delete lookupTable[scope];
		lookupTable[scope] = nullptr;
	}
}

void MemoryManager::CleanOwner(void* owner)
{
	if(lookupTableOwned.count(pointer_to_string(owner)))
		lookupTableOwned[pointer_to_string(owner)]->Discard();
}
