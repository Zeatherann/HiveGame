#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include "AppState.h"

class Game {
	public:
		sf::Window window;
		sf::Event event;

		AppState state;
		bool running;
		
	public:
		Game();
		
		bool initialize();
		bool handleEvent(sf::Event& event);
		void update();
		void draw();
		void clean();
		
		int execute();
};

#endif