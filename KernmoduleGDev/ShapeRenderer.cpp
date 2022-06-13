#include "ShapeRenderer.h"
#include "Quaternion.h"
#include "Macros.h"
#include "Math.h"
#include "Debug.h"

ShapeRenderer::ShapeRenderer(ShapeType type, Vector3 size)
{
	Debug::Log(std::to_string(type));
	Debug::Log(size.to_string());
	switch (type)
	{
		case ShapeRenderer::CIRCLE:
			shape = OCVAR(sf::CircleShape, new sf::CircleShape(size.x, size.y));
			break;
		case ShapeRenderer::RECTANGLE:
			shape = OCVAR(sf::RectangleShape, new sf::RectangleShape(size.to_SFVector2f()));
			break;
		case ShapeRenderer::TRIANGLE:
			shape = OCVAR(sf::CircleShape , new sf::CircleShape(size.x, 3));
			break;
		default:
			shape = OCVAR(sf::CircleShape, new sf::CircleShape(size.x,5));
			break;
	}
}

void ShapeRenderer::Render(sf::RenderWindow* win)
{
	shape->setPosition(transform->position.to_SFVector2f());
	shape->setRotation((Quaternion::ToEulerRad(transform->rotation) * Math::RAD_TO_DEG).z);
	
	//Error lies here \/
	win->draw(*shape);
}
