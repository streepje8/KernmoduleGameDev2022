#include <iostream>
#include <string>
#include "Vector3.h"
#include "Stacktracer.h"
#include "Game.h"
#include "Engine.h"
#include "MemoryManager.h"
#include "ParachutePanic.h"
#include "Debug.h"
#include <SFML/Graphics.hpp>
#include "SceneManager.h"


int main()
{
    Game* game = new ParachutePanic();
    game->Setup();
    sf::RenderWindow window(sf::VideoMode(800, 400), game->windowTitle.c_str());
    #if _DEBUG
        game->Awake();
        while (window.isOpen())
        {
            sf::Event winEvent;
            while (window.pollEvent(winEvent))
            {
                if (winEvent.type == sf::Event::Closed)
                    window.close();
                if (winEvent.type == sf::Event::KeyPressed)
				{
					if (winEvent.key.code == sf::Keyboard::Escape)
						if(game->ExitOnEscape)window.close();
				}
            }
            game->Update();
            Scene* s = SceneManager::GetInstance().GetCurrentScene();
			List<GameObject*>* objects = s->GetObjects();
            for (int i = 0; i < objects->count(); i++) {
                List<Component*>* components = objects->get(i)->GetAllComponents();
                for (int j = 0; j < components->count(); j++) {
					components->get(j)->Update();
                }
            }
            window.clear();
            game->renderer->Render(&window);
            window.display();
        }
        game->Stop();
    #else
        try {
            game->Awake();
            while (window.isOpen())
            {
                sf::Event winEvent;
                while (window.pollEvent(winEvent))
                {
                    if (winEvent.type == sf::Event::Closed)
                        window.close();
                    if (winEvent.type == sf::Event::KeyPressed)
                    {
                        if (winEvent.key.code == sf::Keyboard::Escape)
                            if (game->ExitOnEscape)window.close();
                    }
                }
                game->Update();
                window.clear();
                game->renderer.Render(&window);
                window.display();
            }
            game->Stop();
        }
        catch (...) {
            std::exception_ptr exc = std::current_exception();
            Stacktracer::GetTracer().printException(exc);
            try {
                game->Stop();
            }
            catch (...) {
                Stacktracer::GetTracer().printException(std::current_exception());
            }
        }
    #endif
    delete game;
    MemoryManager::GetInstance().Clean();
}