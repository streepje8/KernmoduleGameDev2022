#pragma once
#include "StreepEngine.h"
class PlayerController :
    public Component
{
	public:
		Rigidbody2D* rb;
		void Start() override;
		void Update() override;
		void OnCollision() override;
	
};

