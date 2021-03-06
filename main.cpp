#include "main.hpp"

int main()
{
    srand(time(nullptr));
    /*
        Lets make use of int main by initializing the global variables (all found _G namespace).
        _G::Window will be our game's window and _G::CurrentState will be the first State that the game enters.
        Below will also be the game loop.
    */
    // ----- Initialize -----

    Textures["Asteroids.png"].loadFromImage(Images.Load("Asteroids.png"));
    _G::Window.create(sf::VideoMode(800,640,32),"HiveGame - Asteroids",sf::Style::Titlebar|sf::Style::Close);
    _G::Window.setFramerateLimit FRAMES_PER_SECOND;
    _G::CurrentState=shared_ptr<State>(new LevelState);

    // ----- Game Loop -----

    while(true)
    {
        // Clear _G::Window first with the given color from _G::CurrentState.

        _G::Window.clear(_G::CurrentState->Color);

        // Have the EventHandler of _G::CurrentState handle all received events.

        _G::CurrentState->Events.HandleEvents(_G::Window);

        // Check if _G::Window is no longer open, if it isn't open then end the program.

        if(!_G::Window.isOpen())return 0;

        // Update _G::CurrentState.

        _G::CurrentState->Update();

        // Draw the contents of _G::CurrentState.

        _G::CurrentState->Render();

        // Display the contents of _G::Window to the screen.

        _G::Window.display();

        // Check for a change in state (_G::FutureState isn't null).

        if(_G::FutureState!=nullptr)
        {
            _G::CurrentState=_G::FutureState;
            _G::FutureState=shared_ptr<State>(nullptr);
        }
    }
    return 0;
}

namespace _G
{
sf::RenderWindow Window;
shared_ptr<State> CurrentState(nullptr);
shared_ptr<State> FutureState(nullptr);
sf::Texture Rock;
} // namespace Global
