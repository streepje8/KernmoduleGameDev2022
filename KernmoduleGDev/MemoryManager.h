#pragma once
#include "List.h"
#include <map>

struct MemoryItem
{
	void* pointer;
	public:
	void Discard() {
		delete pointer;
	}
};

class MemoryList
{
	List<MemoryItem> items;
	public: 
	void Discard() {
		for (int i = items.count() - 1; i >= 0; i--) {
			items.get(i).Discard();
		}
	}
};

class MemoryManager
{
	private:
		int scopeDepth;
		std::map<int, MemoryList> lookupTable;
		std::map<void*, MemoryList> lookupTableOwned;
		MemoryManager();
	public:
		static MemoryManager& GetInstance();
		void PushFunction();
		void PopFunction();
		void Clean();
		void CleanScope(int scope);
		void CleanOwner(void* owner);
		template<typename T>
		MemoryItem AllocateScoped(T obj) {
			MemoryItem item = new MemoryItem();
			item.pointer = new T(obj);
			lookupTable[scopeDepth].items.add(item);
			return item;
		}
		template<typename T, typename TT>
		MemoryItem AllocateOwned(T obj, void* owner) {
			MemoryItem item = new MemoryItem();
			item.pointer = new T(obj);
			if (!lookupTableOwned.count(owner)) {
				lookupTableOwned[owner] = new MemoryList();
			}
			lookupTableOwned[owner].items.add(item);
			return item;
		}
};
