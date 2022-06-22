#include "ShapeRenderer.h"
#include "Quaternion.h"
#include "Macros.h"
#include "Math.h"
#include "Debug.h"

ShapeRenderer::ShapeRenderer(ShapeType type, Vector3 size)
{
	switch (type)
	{
		case ShapeRenderer::CIRCLE:
			shape = VAR(sf::CircleShape, new sf::CircleShape(size.x, size.y));
			break;
		case ShapeRenderer::RECTANGLE:
			shape = VAR(sf::RectangleShape, new sf::RectangleShape(size.to_SFVector2f()));
			break;
		case ShapeRenderer::TRIANGLE:
			shape = VAR(sf::CircleShape, new sf::CircleShape(size.x, 3));
			break;
		default:
			shape = VAR(sf::CircleShape, new sf::CircleShape(size.x,5));
			break;
	}
	shape->setOrigin(sf::Vector2f(size.x, size.y));
}

void ShapeRenderer::Render(sf::RenderWindow* win)
{
	shape->setRotation(Math::MOD((Quaternion::ToEulerRad(transform->rotation) * Math::RAD_TO_DEG).z, 360));
	shape->setPosition((((transform->position + Vector3(400, -200,0)) * Vector3(1,-1,1))).to_SFVector2f_dropZ());
	win->draw(*shape);
}
