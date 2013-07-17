#include "main.hpp"
Asteroid::Asteroid(const sf::Vector2f& Location,const int& Size):Sprite(_G::Rock),Location(Location),Velocity(rand()%Size*2-Size,rand()%Size*2-Size),Size(Size) {
    Sprite.setOrigin(16.f,16.f);
}

Asteroid::~Asteroid(){}

void Asteroid::Update(){
    Location=Location+Velocity;
    if(Location.x>800.f)Location.x-=800.f;
    if(Location.y>640.f)Location.y-=640.f;
    if(Location.x<0.f)Location.x+=800.f;
    if(Location.y<0.f)Location.y+=640.f;
    Sprite.setPosition(Location);
}
