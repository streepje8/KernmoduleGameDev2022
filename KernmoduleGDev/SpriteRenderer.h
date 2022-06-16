#pragma once
#include "Renderer.h"
#include "Sprite.h"
class SpriteRenderer :
    public Renderer
{
private:
    Sprite* sprite;
public:
    SpriteRenderer(std::string s);
    void Render(sf::RenderWindow* win) override;
};

