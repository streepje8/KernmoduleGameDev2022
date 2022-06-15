#pragma once
#include "Component.h"
#include "CommonIncludes.h"

class Renderer :
    public Component
{
	public:
		virtual void Render(sf::RenderWindow* win) {};
};

