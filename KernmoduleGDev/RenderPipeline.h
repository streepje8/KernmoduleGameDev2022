#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "CommonIncludes.h"
class RenderPipeline : public MemoryStorable
{
	public:
		virtual void Render(sf::RenderWindow* win) {};
};

