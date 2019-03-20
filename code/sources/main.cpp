#include "internal/declarations/Declarations.hpp"

#include "SampleScene.hpp"
#include "ContactListener.hpp"
#include "GameController.hpp"

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#define WINDOW_WIDTH 800 
#define WINDOW_HEIGHT 600

namespace prz
{
	int main()
	{
		RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pablo Rodriguez: Box2D Animated Scene", Style::Titlebar | Style::Close, ContextSettings(32));
		window.setVerticalSyncEnabled(true);

		SampleScene sampleScene(0.0f, -100.f, WINDOW_WIDTH, WINDOW_HEIGHT);

		GameController gameController(sampleScene);
		ContactListener<GameController> contactListener(&GameController::handle_contact, &gameController);

		bool running = true;

		Clock timer;
		float deltaTime = 0.017f;          // ~60 fps

		do
		{
			timer.restart();

			// Process window events:

			Event event;

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					running = false;
				}
			}

			// Update:

			//sampleScene.update(deltaTime);
			//// Render:

			//window.clear();

			//sampleScene.render(window);

			//window.display();

			deltaTime = (deltaTime + timer.getElapsedTime().asSeconds()) * 0.5f;
		} while (running);

		return EXIT_SUCCESS;
	}
}

