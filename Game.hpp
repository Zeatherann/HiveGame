#ifndef GAME_HPP
#define GAME_HPP
class Game
{
public:
    sf::Window window;
    sf::Event event;

    AppState state;
    bool running;

public:
    Game();

    bool initialize();
    bool handleEvent(sf::Event& event);
    void update();
    void draw();
    void clean();

    int execute();
};
#endif // GAME_HPP
