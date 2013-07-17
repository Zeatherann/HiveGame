#ifndef LEVELSTATE_HPP
#define LEVELSTATE_HPP
class LevelState:public State
{
public:
    // Variables
    const int Level;
    sf::VertexArray StarField;
    int AlienSpawn;
    const int AlienSpawnTimer;
    /// shared_ptr<PlayerShip> Player;
    vector<shared_ptr<Asteroid>> Asteroids;
    /// vector<shared_ptr<AlienShip>> Aliens;
    /// vector<shared_ptr<Bullet>> Bullets;
    /// ...
    // Constructor
    LevelState(const int& Level=1);
    // Destructor
    virtual ~LevelState();
    // Functions
    void Render();
    void Update();
};
#endif // LEVELSTATE_HPP
