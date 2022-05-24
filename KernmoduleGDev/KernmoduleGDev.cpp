#include <iostream>
#include <string>
#include "Vector3.h"
#include "Stacktracer.h"
#include "Game.h"
#include "Engine.h"
#include "MemoryManager.h"
#include "ParachutePanic.h"
#include "Debug.h"
#include "TestClass.h"

int main()
{
    Game* game = new ParachutePanic();	
    try {
        game->Awake();
    }
    catch (...) {
		std::exception_ptr exc = std::current_exception();
        try {
            game->Stop();
        }
        catch (...) {
            Stacktracer::GetTracer().printException(exc);
            Stacktracer::GetTracer().printException(std::current_exception());
        }
        Stacktracer::GetTracer().printException(exc);
    }
    delete game;
    MemoryManager::GetInstance().Clean();
}