#pragma once
#include "Component.h"
class BoxCollider2D :
    public Component
{
	public:
		int width;
		int height;
		void Update() override;
};

