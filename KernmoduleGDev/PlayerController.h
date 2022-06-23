#pragma once
#include "StreepEngine.h"
class PlayerController :
    public Component
{
	private:
		int direction;
	public:
		Rigidbody2D* rb;
		void Start() override;
		void Update() override;	
};

