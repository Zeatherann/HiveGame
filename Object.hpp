#ifndef OBJECT_HPP
#define OBJECT_HPP
class Object
{
public:
    // Variables
    sf::Sprite Sprite;
    sf::Vector2f Location;
    sf::Vector2f Velocity;
    sf::Vector2f Angle;
    // Constructor
    Object(const sf::Texture& Texture,const sf::IntRect& SubRect,const sf::Vector2f Location,const sf::Vector2f Velocity,const sf::Vector2f Angle);
    // Destructor
    virtual ~Object();
    // Functions
    virtual void Update();
};
#endif // OBJECT_HPP
