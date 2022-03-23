#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SplashScreen.h"
#include "MainMenu.h"
#include "PlayerPaddle.h"
#include "GameObjectManager.h"

class Game {
public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	const static sf::Keyboard& GetInput();
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:
	static bool IsExiting();
	static void GameLoop();

	static void ShowSpashScreen();
	static void ShowMenu();

	enum GameState {Uninitialized, ShowingSplash, Paused,
									showingMenu, Playing, Exiting };
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static GameObjectManager _gameObjectManager;

};

