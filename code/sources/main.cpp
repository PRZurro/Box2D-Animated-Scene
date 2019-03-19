#include "internal/declarations/Declarations.hpp"

#include "SampleScene.hpp"
#include "ContactListener.hpp"
#include "GameController.hpp"

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace prz;
using namespace sf;
using namespace std;

namespace prz
{


    shared_ptr< b2World > create_physics_world (float world_width, float world_height)
    {
        // Se crea el mundo físico:

        shared_ptr< b2World > physics_world(new b2World(b2Vec2(0, -100.f)));

        // CÍRCULO
        {
            // Se crea el body a partir de una definición de sus características:

            b2BodyDef body_definition;

            body_definition.type = b2_dynamicBody;
            body_definition.position.Set (world_width / 2.f, world_height / 2.f);           // Posición inicial absoluta

            b2Body * body = physics_world->CreateBody (&body_definition);

            // Se añande una fixture al body:

            b2CircleShape body_shape;

            body_shape.m_radius = 25.f;

            b2FixtureDef body_fixture;

            body_fixture.shape       = &body_shape;
            body_fixture.density     = 1.00f;
            body_fixture.restitution = 0.75f;
            body_fixture.friction    = 0.50f;

            body->CreateFixture (&body_fixture);
        }

        // CUADRADO
        {
            // Se crea el body a partir de una definición de sus características:

            b2BodyDef body_definition;

            body_definition.type = b2_dynamicBody;
            body_definition.position.Set (world_width / 2.f, world_height / 2.f + 200.f);   // Posición inicial absoluta
            body_definition.angle = 0.4f;

            b2Body * body = physics_world->CreateBody (&body_definition);

            // Se añande una fixture al body:

            b2PolygonShape body_shape;

            body_shape.SetAsBox (25.f, 25.f);

            b2FixtureDef body_fixture;

            body_fixture.shape       = &body_shape;
            body_fixture.density     = 1.00f;
            body_fixture.restitution = 0.50f;
            body_fixture.friction    = 0.50f;

            body->CreateFixture (&body_fixture);
        }

        // SUELO
        {
            // Se crea el body a partir de una definición de sus características:

            b2BodyDef body_definition;

            body_definition.type = b2_staticBody;
            body_definition.position.Set (0.f, 50.f);                                       // Posición inicial absoluta
            body_definition.angle = -45.f;

            b2Body * body = physics_world->CreateBody (&body_definition);

            // Se añande una fixture al body:

            b2EdgeShape body_shape;

            body_shape.Set (b2Vec2(0.f, 0.f), b2Vec2(world_width, 0.f));                    // Coordenadas locales respecto al centro del body

            b2FixtureDef body_fixture;

            body_fixture.shape = &body_shape;

            body->CreateFixture (&body_fixture);
        }

        return physics_world;
    }
}

int main ()
{
    RenderWindow window(VideoMode(800, 600), "Pablo Rodriguez: Box2D Animated Scene", Style::Titlebar | Style::Close, ContextSettings(32));

	window.setVerticalSyncEnabled(true);

	SampleScene sampleScene(0.0f, -100.f);

	GameController gameController(sampleScene);

	//ContactListener<GameController> contactListener (GameController::handle_contact, &gameController);

    bool running = true;

    Clock timer;
    float deltaTime = 0.017f;          // ~60 fps

    do
    {
        timer.restart ();

        // Process window events:

        Event event;

        while (window.pollEvent (event))
        {
            if (event.type == Event::Closed)
            {
                running = false;
            }
        }

        // Update:

		sampleScene.update(deltaTime);
        // Render:

        window.clear ();

		sampleScene.render(window);

        window.display ();

        deltaTime = (deltaTime + timer.getElapsedTime ().asSeconds ()) * 0.5f;
    }
    while (running);

    return EXIT_SUCCESS;
}
