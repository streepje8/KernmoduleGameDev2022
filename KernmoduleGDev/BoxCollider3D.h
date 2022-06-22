#pragma once
#include "Component.h"
class BoxCollider3D :
    public Component
{
	public:
		int width;
		int height;
		int depth;
		void Update() override;
};

