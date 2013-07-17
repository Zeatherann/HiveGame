#include "main.hpp"
LevelState::LevelState(const int& Level):Level(Level),StarField(sf::Points,STAR_FIELD_SIZE),AlienSpawn(0),AlienSpawnTimer(int FRAMES_PER_SECOND*(60-Level))
{
    for(unsigned int a=0u; a<STAR_FIELD_SIZE; ++a)
    {
        StarField[a]=sf::Vertex(sf::Vector2f(rand()%800,rand()%640),a%2u==0u?sf::Color::White:sf::Color::Yellow);
    }
    // Create starting asteroids (2+Level).
    Asteroids.resize(2+Level);
    for(shared_ptr<Asteroid>& Iter:Asteroids)Iter=shared_ptr<Asteroid>(new Asteroid(sf::Vector2f(rand()%800,rand()%640),3));
    // Create Player.

    // Create Events.
    Events.AddEvent(sf::Event::Closed,[](const sf::Event& __unused__)->void {_G::Window.close();});

    Events.AddEvent(sf::Event::KeyPressed,[this](const sf::Event& __unused__)->void {Asteroids.clear();});

    // Set Title.
    _G::Window.setTitle("Hive Game - Asteroids: Level "+lexical_cast<string>(Level));
}

LevelState::~LevelState() {}

void LevelState::Render()
{
    // Render StarField.
    _G::Window.draw(StarField);
    // Render Asteroids.
    for(const shared_ptr<Asteroid>& Iter:Asteroids){
        _G::Window.draw(Iter->Sprite);
    }
    // Render Aliens.
    // Render Players.
    // Render Bullets.
}

void LevelState::Update()
{
    if(++AlienSpawn==AlienSpawnTimer)
    {
        AlienSpawn=0;
        // Spawn Alien.
    }
    // Update Asteroids.
    for(const shared_ptr<Asteroid>& Iter:Asteroids)Iter->Update();
    // Update Aliens.
    // Update Bullets.
    if(Asteroids.size()<1u)_G::FutureState=shared_ptr<State>(new LevelState(Level+1));
}
