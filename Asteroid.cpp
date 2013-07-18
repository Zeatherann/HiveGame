#include "main.hpp"
sf::Image Asteroid::Image;
sf::Texture Asteroid::Texture;
Asteroid::Asteroid(const sf::Vector2f& Location,AsteroidSize Size):
    Sprite(Texture,TextureRect(Size)),Location(Location),Velocity(Random*6.f-3.f,Random*6.f-3.f),Angle(Random*360.f,Random*4.f-2.f),Size(Size),Invuln(30)
{
    switch(Size)
    {
    case as_Large:
        Sprite.setOrigin(64.f,64.f);
        break;
    case as_Medium:
        Sprite.setOrigin(32.f,32.f);
        break;
    default:
        Sprite.setOrigin(16.f,16.f);
        break;
    }
    Sprite.setPosition(Location);
    Sprite.setColor(sf::Color::Red);
}

Asteroid::~Asteroid() {}

void Asteroid::Update()
{
    if(Invuln){
        if(--Invuln==0){
            Sprite.setColor(sf::Color::White);
        }
    }
    Location=Location+Velocity;
    Angle.x+=Angle.y;
    Sprite.setRotation(Angle.x);
    if(Location.x>800.f)Location.x-=800.f;
    if(Location.y>640.f)Location.y-=640.f;
    if(Location.x<0.f)Location.x+=800.f;
    if(Location.y<0.f)Location.y+=640.f;
    Sprite.setPosition(Location);
}

sf::IntRect Asteroid::TextureRect(AsteroidSize Size)
{
    int Rand;
    switch(Size)
    {
    case as_Large:
        //if(rand()%2==0){
        return sf::IntRect(0,0,128,128);
        /*}else{
            return {0,128,128,128}AsteroidSize;
        }*/
    case as_Medium:
        Rand=rand()%4;
        switch(Rand)
        {
        case 0:
            return sf::IntRect(128,0,64,64);
        case 1:
            return sf::IntRect(192,0,64,64);
        case 2:
            return sf::IntRect(128,64,64,64);
        default:
            return sf::IntRect(192,64,64,64);
        }
    default:
        Rand=rand()%4;
        switch(Rand)
        {
        case 0:
            return sf::IntRect(192,192,32,32);
        case 1:
            return sf::IntRect(224,192,32,32);
        case 2:
            return sf::IntRect(192,224,32,32);
        default:
            return sf::IntRect(224,224,32,32);
        }
    }
}

vector<shared_ptr<Asteroid>> Asteroid::Split(const shared_ptr<Asteroid>& self){
    if(self->Size==as_Small)return vector<shared_ptr<Asteroid>>();
    AsteroidSize NewSize=self->Size==as_Large?as_Medium:as_Small;
    return {shared_ptr<Asteroid>(new Asteroid(self->Location,NewSize)),shared_ptr<Asteroid>(new Asteroid(self->Location,NewSize))};
}
