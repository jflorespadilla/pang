#include "Game.h"
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"

void Game::Start() {
	if (_gameState != Uninitialized) {
		return;
	}

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pang!");
	
	SFMLSoundProvider soundProvider;
	ServiceLocator::RegisterServiceLocator(&soundProvider);
	ServiceLocator::GetAudio()->PlaySong("Soundtrack.ogg", true);

	PlayerPaddle* player1 = new PlayerPaddle();
	player1->SetPosition((SCREEN_WIDTH/2), 700);

	AIPaddle* player2 = new AIPaddle();
	player2->SetPosition((SCREEN_WIDTH / 2), 100);

	GameBall* ball = new GameBall();
	ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);

	_gameObjectManager.paddle1 = player1;
	_gameObjectManager.paddle2 = player2;
	_gameObjectManager.ball = ball;

	_gameState = Game::ShowingSplash;

	while (!IsExiting()) {
		GameLoop();
	}
	_mainWindow.close();
}

sf::RenderWindow& Game::GetWindow() {
	return _mainWindow;
}

sf::Time& Game::GetElapsedTime() {
	sf::Time time = _clock.getElapsedTime();
	_clock.restart();
	return time;
}

GameObjectManager Game::GetGameObjectManager() {
	return _gameObjectManager;
}

bool Game::IsExiting() {
	return _gameState == Game::Exiting;
}

void Game::GameLoop() {
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);

	switch (_gameState) {
		case Game::showingMenu:
			ShowMenu();
			break;

		case Game::ShowingSplash:
			ShowSpashScreen();
			break;

		case Game::Playing:
				_mainWindow.clear(sf::Color(0, 0, 0));
				_gameObjectManager.UpdateAll();
				_gameObjectManager.DrawAll(_mainWindow);
				_mainWindow.display();
				if (currentEvent.type == sf::Event::Closed) {
					_gameState = Game::Exiting;
				}
				if (currentEvent.type == sf::Event::KeyPressed) {
					if (currentEvent.key.code == sf::Keyboard::Escape) {
						ShowMenu();
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
	switch (result) {
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
sf::Clock Game::_clock;
GameObjectManager Game::_gameObjectManager;