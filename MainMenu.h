#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

class MainMenu {
public:
	enum MenuResult {Nothing, Exit, Play};

	struct MenuItem {
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& renderWindow);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& renderWindow);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;
};

