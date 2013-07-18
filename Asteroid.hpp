#ifndef ASTEROID_HPP
#define ASTEROID_HPP
enum AsteroidSize {as_Large,as_Medium,as_Small};
class Asteroid:public Object
{
public:
    static sf::Image Image;
    static sf::Texture Texture;
    static sf::IntRect TextureRect(AsteroidSize Size);
    static vector<shared_ptr<Asteroid>> Split(const shared_ptr<Asteroid>& self);
    // Variables
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
