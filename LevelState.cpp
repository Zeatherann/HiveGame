#include "main.hpp"
LevelState::LevelState(const int& Level):Level(Level),StarField(sf::Points,STAR_FIELD_SIZE),AlienSpawn(0),AlienSpawnTimer(int FRAMES_PER_SECOND*(60-Level))
{
    for(unsigned int a=0u; a<STAR_FIELD_SIZE; ++a)
    {
        StarField[a]=sf::Vertex(sf::Vector2f(rand()%800,rand()%640),a%2u==0u?sf::Color::White:sf::Color::Yellow);
    }
    // Create starting asteroids (2+Level).
    Asteroids.resize(2+Level);
    for(shared_ptr<Asteroid>& Iter:Asteroids)Iter=shared_ptr<Asteroid>(new Asteroid(sf::Vector2f(rand()%800,rand()%640),as_Large));
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
    for(const shared_ptr<Asteroid>& Iter:Asteroids)
    {
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
    set<unsigned int>ToRemove;
    vector<shared_ptr<Asteroid>> NewAsteroids;
    for(unsigned int Index=0u; Index<Asteroids.size(); Index++)
    {
        shared_ptr<Asteroid>& First=Asteroids[Index];
        float Size1=First->Size==as_Large?48.f:First->Size==as_Medium?24.f:12.f;
        for(unsigned int Index2=Index; Index2<Asteroids.size(); Index2++)
        {
            shared_ptr<Asteroid>& Second=Asteroids[Index2];
            if(First!=Second&&First->Invuln==0&&Second->Invuln==0)
            {
                float Size2=Second->Size==as_Large?48.f:Second->Size==as_Medium?24.f:12.f;
                if(DistanceSquared(First->Location,Second->Location)<=(Size1+Size2)*(Size1+Size2))
                {
                    vector<shared_ptr<Asteroid>> New=Asteroid::Split(First);
                    vector<shared_ptr<Asteroid>> New2=Asteroid::Split(Second);
                    ToRemove.insert(Index);
                    ToRemove.insert(Index2);
                    NewAsteroids.insert(NewAsteroids.end(),New.cbegin(),New.cend());
                    NewAsteroids.insert(NewAsteroids.end(),New2.cbegin(),New2.cend());
                }
            }
        }
    }
    for(const unsigned int& Iter:ToRemove)
    {
        Asteroids.erase(Asteroids.begin()+Iter);
    }
    Asteroids.insert(Asteroids.end(),NewAsteroids.cbegin(),NewAsteroids.cend());
}
