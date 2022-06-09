#pragma once
#include "Renderer.h"
class ShapeRenderer :
    public Renderer
{
public:
	enum ShapeType {
		CIRCLE,
		RECTANGLE,
		TRIANGLE
	};
	sf::Shape* shape;
	ShapeRenderer(ShapeType type, Vector3 size = Vector3(1,1,1));
	void Render(sf::RenderWindow* win) override;
};

