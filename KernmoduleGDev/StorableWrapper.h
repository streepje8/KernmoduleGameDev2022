#pragma once
#include "MemoryStorable.h"
template<typename T>
class StorableWrapper : public MemoryStorable {
			
	public:
		T* wrappedobj;
		StorableWrapper(T* object) {
			wrappedobj = object;
		}
		virtual ~StorableWrapper() {
			delete wrappedobj;
		}
};