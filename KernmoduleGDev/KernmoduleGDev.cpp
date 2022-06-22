#include "ParachutePanic.h"
#include "StreepEngine.h"

int main()
{
    Game* game = new ParachutePanic();
    game->Setup();
    sf::RenderWindow window(sf::VideoMode(800, 400), game->windowTitle.c_str());
    game->Awake();
    Scene* s = SceneManager::GetInstance().GetCurrentScene();
    List<GameObject*>* objects = s->GetObjects();
    for (int i = 0; i < objects->count(); i++) {
        List<Component*>* components = objects->get(i)->GetAllComponents();
        for (int j = 0; j < components->count(); j++) {
            components->get(j)->Start();
        }
    }
    double oldTime = 0;
    while (window.isOpen())
    {
        double currentTime = clock();
        Time.time = currentTime / 1000.0f;
        Time.deltaTime = (currentTime - oldTime) / 1000.0f;
        Time.FPS = 1.0f / Time.deltaTime; 
        oldTime = clock();
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