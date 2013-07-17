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
extern sf::Texture Rock;
} // namespace Global
/// Global Functions
/// Project Files
#include "EventHandler.hpp"
#include "Asteroid.hpp"
#include "State.hpp"
#include "LevelState.hpp"
#endif // MAIN_HPP
