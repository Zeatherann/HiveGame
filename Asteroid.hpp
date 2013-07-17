#ifndef ASTEROID_HPP
#define ASTEROID_HPP
class Asteroid{
public:
    // Variables
    sf::Sprite Sprite;
    sf::Vector2f Location;
    sf::Vector2f Velocity;
    int Size;
    // Constructor
    Asteroid(const sf::Vector2f& Location,const int& Size);
    // Destructor
    ~Asteroid();
    // Functions
    void Update();
};
#endif // ASTEROID_HPP
