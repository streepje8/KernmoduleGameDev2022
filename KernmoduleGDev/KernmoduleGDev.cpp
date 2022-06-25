#include "ParachutePanic.h"
#include "StreepEngine.h"
#include <chrono>

int main()
{
    Game* game = new ParachutePanic();
    std::srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    game->Setup();
    sf::RenderWindow window(sf::VideoMode(800, 400), game->windowTitle.c_str());
    game->Awake();
    window.setFramerateLimit(144);
    auto oldTime = std::chrono::high_resolution_clock::now();
    while (window.isOpen())
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        Time.time = clock() / 1000.0f;
        Time.deltaTime = (std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - oldTime).count()) / 10000000000.0f;
        Time.FPS = 1.0f / Time.deltaTime; 
        oldTime = std::chrono::high_resolution_clock::now();
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
    delete game;
    MemoryManager::GetInstance().Clean();
}