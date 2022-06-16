#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
class Sprite : public MemoryStorable
{
	public:
		sf::Sprite sfSprite;
		sf::Texture sfTexture;
		bool antiAlias;
		bool tiled;
		Sprite(std::string filepath);
		void PrepareRender();
};