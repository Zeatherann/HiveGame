#include "main.hpp"

Object::Object(const sf::Texture& Texture,const sf::IntRect& SubRect,const sf::Vector2f Location,const sf::Vector2f Velocity,const sf::Vector2f Angle):
    Sprite(Texture,SubRect),Location(Location),Velocity(Velocity),Angle(Angle) {}

Object::~Object() {}

void Object::Update()
{
    Location+=Velocity;
    Angle.x+=Angle.y;
    Sprite.setRotation(Angle.x);
    Sprite.setPosition(Location);
}
