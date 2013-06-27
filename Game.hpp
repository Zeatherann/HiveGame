#ifndef GAME_HPP
#define GAME_HPP
class Game
{
public:
    // Variables
    shared_ptr<sf::RenderWindow> Window;
    bool Running; // What is this going to be used for?
    bool IsPaused;
    AppState State; // I'm sure we can come up of a better method?
    EventHandler Events;
    // Constructor
    Game();
    // Functions
    bool initialize();
    void handleEvents();
    void update();
    void clear();
    void draw();
    void clean();

    void pause();
    void resume();

    int execute();
};
#endif // GAME_HPP
