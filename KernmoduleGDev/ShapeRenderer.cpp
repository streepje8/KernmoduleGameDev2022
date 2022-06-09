#include "ShapeRenderer.h"
#include "Quaternion.h"
#include "Macros.h"
#include "Math.h"

ShapeRenderer::ShapeRenderer(ShapeType type, Vector3 size)
{
	switch (type)
	{
		case ShapeRenderer::CIRCLE:
			shape = OCVAR(sf::CircleShape, sf::CircleShape(size.x, size.y));
			break;
		case ShapeRenderer::RECTANGLE:
			shape = OCVAR(sf::RectangleShape, sf::RectangleShape(size.to_SFVector2f()));
			break;
		case ShapeRenderer::TRIANGLE:
			shape = OCVAR(sf::CircleShape, sf::CircleShape(size.x,3));
			break;
		default:
			shape = OCVAR(sf::CircleShape, sf::CircleShape(size.x,5));
			break;
	}
}

void ShapeRenderer::Render(sf::RenderWindow* win)
{
	shape->setPosition(transform->position.to_SFVector2f());
	shape->setRotation((Quaternion::ToEulerRad(transform->rotation) * Math::RAD_TO_DEG).z);
	win->draw(*shape);
}
