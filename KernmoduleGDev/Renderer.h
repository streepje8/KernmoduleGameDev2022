#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
class Renderer :
    public Component
{
	public:
		virtual void Render(sf::RenderWindow* win) {};
};

