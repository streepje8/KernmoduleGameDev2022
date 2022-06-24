#pragma once
#include "Component.h"
#include "GameObject.h"
class BoxCollider2D :
    public Component
{
	public:
		int width;
		int height;
		GameObject* lastCollidedWith;
		void Update() override;
};

