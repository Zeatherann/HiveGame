#include "main.hpp"

Game::Game() : state(as_Null),running(false)
{
}

bool Game::initialize()
{
    window.create(sf::VideoMode(640, 480), "HiveGame");

    // Configure window
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(true); // Might not need this.

    return true;
}

bool Game::handleEvent(sf::Event& event)
{
    switch (state)
    {
    case as_Null:
        break;
    default:
        break;
    }

    return false;
}

void Game::update()
{
    switch (state)
    {
    case as_Null:
        break;
    default:
        break;
    }
}

void Game::draw()
{
    switch (state)
    {
    case as_Null:
        break;
    default:
        break;
    }
}

void Game::clean()
{
    // Nothing to clean at the moment.
}

int Game::execute()
{
    running = initialize();

    while (running)
    {
        while (window.pollEvent(event))
        {
            handleEvent(event);
        }

        update();
        draw();
    }

    clean();

    return 0;
}
