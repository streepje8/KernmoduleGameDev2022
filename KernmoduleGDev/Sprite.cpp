#include "CommonIncludes.h"
#include "Sprite.h"

Sprite::Sprite(std::string filepath)
{
	this->antiAlias = false;
	this->tiled = false;
	if (!sfTexture.loadFromFile(filepath))
	{
		Debug::LogError("Could not load sprite from file: " + filepath);
		return;
	}
	sfSprite.setTexture(sfTexture);
}

void Sprite::PrepareRender()
{
	sfTexture.setSmooth(antiAlias);
	sfTexture.setRepeated(tiled);
}
