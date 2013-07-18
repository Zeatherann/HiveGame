#ifndef MAIN_HPP
#define MAIN_HPP
/// Defines
#define SFML_STATIC
#define FRAMES_PER_SECOND (60u)
#define STAR_FIELD_SIZE (512u)
/// Libraries
// Standard Library
#include <iostream>
#include <functional>
#include <set>
#include <map>
#include <memory>
// SFML
#include <SFML/Graphics.hpp>
// Boost
#include <boost/lexical_cast.hpp>
// -----
/// Namespaces
using namespace std;
using boost::lexical_cast;
/// Class Forward Declarations
class State;
/// Enumerations
/// Structs
/// Typedefs
/// Global Variables
namespace _G
{
extern sf::RenderWindow Window;
extern shared_ptr<State> CurrentState;
extern shared_ptr<State> FutureState;
} // namespace Global
/// Global Functions
inline float GetRandomFloat(){return float(rand())/float(RAND_MAX);}
inline float DistanceSquared(const sf::Vector2f& P1,const sf::Vector2f& P2){
    return (P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y);
}
#define Random (GetRandomFloat())
/// Project Files
#include "EventHandler.hpp"
#include "Asteroid.hpp"
#include "State.hpp"
#include "LevelState.hpp"
#endif // MAIN_HPP
