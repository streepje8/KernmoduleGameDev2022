#pragma once
#include "Vector3.h"
#include "Quaternion.h"
#include "MemoryStorable.h"
struct Transform : public MemoryStorable {
public:
	Vector3 position;
	Quaternion rotation;
	Vector3 scale;
	virtual ~Transform()
	{
		MemoryManager::GetInstance().CleanOwner(this);
	}
};