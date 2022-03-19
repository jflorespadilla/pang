#include "Game.h"

void Game::Start() {
	if (_gameState != Uninitialized) {
		return;
	}

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");
	_gameState = Game::ShowingSplash;

	while (!IsExiting()) {
		GameLoop();
	}
	_mainWindow.close();
}

bool Game::IsExiting() {
	if (_gameState == Game::Exiting) {
		return true;
	}
	return false;
}

void Game::GameLoop() {
	sf::Event currentEvent;
	
	switch (_gameState) {
		case Game::showingMenu:
			ShowMenu();
			break;

		case Game::ShowingSplash:
			ShowSpashScreen();
			break;

		case Game::Playing:
			sf::Event currentEvent;
			while (_mainWindow.pollEvent(currentEvent)) {
				_mainWindow.clear(sf::Color(0, 0, 0));
				_mainWindow.display();
				if (currentEvent.type == sf::Event::Closed) {
					_gameState = Game::Exiting;
				}
				if (currentEvent.type == sf::Event::KeyPressed) {
					if (currentEvent.key.code == sf::Keyboard::Escape) {
						ShowMenu();
					}
				}
			}
			break;
	}
}

void Game::ShowSpashScreen() {
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::showingMenu;
}

void Game::ShowMenu() {
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		_gameState = Game::Playing;
		break;
	}
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;