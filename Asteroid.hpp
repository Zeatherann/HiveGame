#ifndef ASTEROID_HPP
#define ASTEROID_HPP
enum AsteroidSize{as_Large,as_Medium,as_Small};
class Asteroid
{
public:
    static sf::Image Image;
    static sf::Texture Texture;
    static sf::IntRect TextureRect(AsteroidSize Size);
    static vector<shared_ptr<Asteroid>> Split(const shared_ptr<Asteroid>& self);
    // Variables
    sf::Sprite Sprite;
    sf::Vector2f Location;
    sf::Vector2f Velocity;
    sf::Vector2f Angle;
    AsteroidSize Size;
    int Invuln;
    // Constructor
    Asteroid(const sf::Vector2f& Location,AsteroidSize Size);
    // Destructor
    ~Asteroid();
    // Functions
    void Update();
};
#endif // ASTEROID_HPP
