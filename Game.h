#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SplashScreen.h"
#include "MainMenu.h"

class Game {
public:
	static void Start();

private:
	static bool IsExiting();
	static void GameLoop();

	static void ShowSpashScreen();
	static void ShowMenu();

	enum GameState {Uninitialized, ShowingSplash, Paused,
									showingMenu, Playing, Exiting };
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};

