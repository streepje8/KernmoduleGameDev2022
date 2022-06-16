#pragma once
#include "List.h"
#include "MemoryStorable.h"
#include <string>
#include <typeinfo>
#include <map>
#include "CommonUtil.h"

#include "Debug.h"

struct MemoryItem
{
public:
	MemoryStorable* pointer;
	void Discard() {
		delete pointer;
		pointer = nullptr;
	}
};

class MemoryList
{
	public: 
	List<MemoryItem*>* items;
	MemoryList() {
		items = new List<MemoryItem*>();
	}
	virtual ~MemoryList() {
		delete items;
	}
	void Discard() {
		for (int i = items->count() - 1; i >= 0; i--) {
			items->get(i)->Discard();
			delete items->get(i);
		}
	}
};

class MemoryManager
{
	private:
		int scopeDepth;
		std::map<int, MemoryList*> lookupTable;
		std::map<std::string, MemoryList*> lookupTableOwned;
		MemoryManager();
	public:
		static MemoryManager& GetInstance();
		void PushFunction();
		void PopFunction();
		void Clean();
		void CleanScope(int scope);
		void CleanOwner(void* owner);
		template<typename T>
		MemoryItem* AllocateScoped(MemoryStorable obj) {
			MemoryItem* item = new MemoryItem();
			item->pointer = (MemoryStorable*)new T(obj);
			lookupTable[scopeDepth]->items->add(item);
			return item;
		}

		MemoryItem* AllocateOwned(MemoryStorable obj, void* owner) {
			MemoryItem* item = new MemoryItem();
			item->pointer = new MemoryStorable(obj);
			if (!lookupTableOwned.count(pointer_to_string(owner))) {
				lookupTableOwned[pointer_to_string(owner)] = new MemoryList();
			}
			lookupTableOwned[pointer_to_string(owner)]->items->add(item);
			return item;
		}

		MemoryItem* AllocateOwned(MemoryStorable* obj, void* owner) {
			MemoryItem* item = new MemoryItem();
			item->pointer = obj;
			if (!lookupTableOwned.count(pointer_to_string(owner))) {
				lookupTableOwned[pointer_to_string(owner)] = new MemoryList();
			}
			lookupTableOwned[pointer_to_string(owner)]->items->add(item);
			return item;
		}
};