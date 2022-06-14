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
			shape = OCVAR(sf::CircleShape, new sf::CircleShape(size.x, size.y));
			break;
		case ShapeRenderer::RECTANGLE:
			shape = OCVAR(sf::RectangleShape, new sf::RectangleShape(size.to_SFVector2f()));
			break;
		case ShapeRenderer::TRIANGLE:
			shape = OCVAR(sf::CircleShape, new sf::CircleShape(size.x, 3)); // , )
			break;
		default:
			shape = OCVAR(sf::CircleShape, new sf::CircleShape(size.x,5));
			break;
	}
	Debug::Log(std::to_string(type));
	Debug::Log(size.to_string());
}

void ShapeRenderer::Render(sf::RenderWindow* win)
{
	shape->setPosition(sf::Vector2f(50, 50));
	shape->setRotation(Math::MOD((Quaternion::ToEulerRad(transform->rotation) * Math::RAD_TO_DEG).z, 360));
	shape->setPosition(sf::Vector2f(0, 0));
	shape->setPosition(transform->position.to_SFVector2f());
	
	//Error lies here \/
	win->draw(*shape);
}
