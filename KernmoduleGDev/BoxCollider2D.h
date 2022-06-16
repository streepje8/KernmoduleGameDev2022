#pragma once
#include "Component.h"
class BoxCollider2D :
    public Component
{
	public:
		int width;
		int height;
		void Start() override;
		void Update() override;
		void OnCollision() override;
};

