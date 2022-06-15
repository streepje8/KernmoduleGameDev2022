#include "Input.h"
InputManager& InputManager::GetInstance()
{
	static InputManager instance;
	return instance;
}

bool InputManager::GetKey(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

float InputManager::GetAxis(std::string name)
{
	float input = 0;
	if (name == "horizontal") {
		input = input - (GetKey(KeyCode::A) || GetKey(KeyCode::Left));
		input = input + (GetKey(KeyCode::D) || GetKey(KeyCode::Right));
	}
	if (name == "vertical") {
		input = input - (GetKey(KeyCode::W) || GetKey(KeyCode::Up));
		input = input + (GetKey(KeyCode::S) || GetKey(KeyCode::Down));
	}
	return input;
}
