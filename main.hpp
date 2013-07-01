#ifndef MAIN_HPP
#define MAIN_HPP
/// Defines
//#define TESTRUN
#define SFML_STATIC
/// Libraries
// Standard Library
#include <iostream>
#include <functional>
#include <set>
#include <map>
#include <memory>
// SFML
#include <SFML/Graphics.hpp>
// -----
/// Namespaces
using namespace std;
/// Class Forward Declarations
#ifdef TESTRUN
class State;
#endif
/// Enumerations
/// Structs
/// Typedefs
/// Global Variables
#ifdef TESTRUN
namespace _G
{
extern sf::RenderWindow Window;
extern shared_ptr<State> CurrentState;
extern shared_ptr<State> FutureState;
} // namespace Global
#endif
/// Global Functions
/// Project Files
#include "EventHandler.hpp"
#ifndef TESTRUN
#include "AppState.hpp"
#include "Game.hpp"
#else
#include "State.hpp"
#endif
#endif // MAIN_HPP
