#include "Game.h"
#include "BuildInRenderer.h"

Game::Game()
{
	this->name = "";
	this->windowTitle = "streep game";
	ExitOnEscape = true;
	renderer = BuildInRenderer();
}
