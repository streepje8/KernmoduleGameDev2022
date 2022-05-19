#include <iostream>
#include <string>
#include "Vector3.h"
#include "Stacktracer.h"
#include "Game.h"
#include "Engine.h"
#include "MemoryManager.h"

int main()
{
    Game game = Game();
    try {
        game.Awake();
    }
    catch (std::exception exc) {
        try {
            game.Stop();
        }
        catch (std::exception excc) {
            Stacktracer::GetTracer().printException(exc);
            Stacktracer::GetTracer().printException(excc);
        }
        Stacktracer::GetTracer().printException(exc);
    }
    MemoryManager::GetInstance().Clean();
}