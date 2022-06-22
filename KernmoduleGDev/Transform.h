#pragma once
#include "Vector3.h"
#include "Quaternion.h"
#include "MemoryManager.h"
#include "MemoryStorable.h"
struct Transform : public MemoryStorable {
public:
	Vector3 position;
	Quaternion rotation;
	Vector3 scale;
	Transform() {
		position = Vector3(0, 0, 0);
		rotation = Quaternion::Identity();
		scale = Vector3(1, 1, 1);
	}
	virtual ~Transform()
	{
		MemoryManager::GetInstance().CleanOwner(this);
	}
};