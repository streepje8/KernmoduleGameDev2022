#include "Game.h"
#include "BuildInRenderer.h"
#include "Macros.h"

Game::Game()
{
	this->name = "";
	this->windowTitle = "streep game";
	ExitOnEscape = true;
	renderer = NVAR(BuildInRenderer);
}
