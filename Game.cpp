#include "main.hpp"

Game::Game() : Window(),Running(false),IsPaused(false),State(as_Null),Events()
{
}

bool Game::initialize()
{
    Window=shared_ptr<sf::RenderWindow>(new sf::RenderWindow( {800,640,32},"HiveGame - Asteroids"));

    // Configure window
    Window->setFramerateLimit(60);
    Window->setVerticalSyncEnabled(true);
    Window->setKeyRepeatEnabled(false); // Trust me we want it to be false.

    // Add Window Closed event, as well as Window Lose Focus/Gain Focus for auto pausing.
    Events.AddEvent(sf::Event::Closed,[this](const sf::Event& _unused_)->void {Window->close();Running=false;});
    Events.AddEvent(sf::Event::LostFocus,[this](const sf::Event& _unused_)->void {pause();});
    Events.AddEvent(sf::Event::GainedFocus,[this](const sf::Event& _unused_)->void {resume();});

    return true;
}

void Game::pause()
{
    IsPaused=true;
}
void Game::resume()
{
    IsPaused=false;
}

void Game::handleEvents()
{
    Events.HandleEvents(*Window.get());
}

void Game::clear()
{
    switch (State)
    {
    case as_Null:
    default:
        Window->clear();
    }
}

void Game::update()
{
    switch (State)
    {
    case as_Null:
    default:
        ;
    }
}

void Game::draw()
{
    switch (State)
    {
    case as_Null:
    default:
        Window->display();
    }
}

void Game::clean()
{
    // Nothing to clean at the moment.
}

int Game::execute()
{
    Running = initialize();

    while (Running)
    {
        clear();
        handleEvents();
        if(!Running)
        {
            break;
        }
        if(!IsPaused)
        {
            update();
        }
        draw();
    }

    clean();

    return 0;
}
