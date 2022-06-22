#include "CommonIncludes.h"
#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(std::string s)
{
	Sprite* spr = OCVAR(Sprite,new Sprite(s));
	this->sprite = spr;
}

void SpriteRenderer::Render(sf::RenderWindow* win)
{
	this->sprite->PrepareRender();
	sf::Vector2u texSize = this->sprite->sfTexture.getSize();
	this->sprite->sfSprite.setOrigin(texSize.x / 2, texSize.y / 2);
	this->sprite->sfSprite.setRotation(Math::MOD((Quaternion::ToEulerRad(transform->rotation) * Math::RAD_TO_DEG).z, 360));
	this->sprite->sfSprite.setPosition((((transform->position + Vector3(400, -200, 0)) * Vector3(1, -1, 1))).to_SFVector2f_dropZ());
	this->sprite->sfSprite.setScale(transform->scale.to_SFVector2f_dropZ());
	win->draw(this->sprite->sfSprite);
}