#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "CommonIncludes.h"
#define KeyCode sf::Keyboard::Key
#define Input InputManager::GetInstance()

class InputManager
{
public:
	static InputManager& GetInstance();
	bool GetKey(sf::Keyboard::Key key);
	float GetAxis(std::string name);
};

