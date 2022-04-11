#include "MainMenu.h"
#include "ServiceLocator.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& renderWindow) {
    sf::Texture image;
    image.loadFromFile("MainMenu.png");
    sf::Sprite sprite(image);

    MenuItem playButton;
    playButton.rect.top = 145;
    playButton.rect.left = 0;
    playButton.rect.height = 235;
    playButton.rect.width = 1023;
    playButton.action = Play;

    MenuItem exitButton;
    exitButton.rect.left = 0;
    exitButton.rect.top = 383;
    exitButton.rect.width = 1023;
    exitButton.rect.height = 177;
    exitButton.action = Exit;

    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);

    renderWindow.draw(sprite);
    renderWindow.display();


    return GetMenuResponse(renderWindow);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y) {
    std::list<MenuItem>::iterator it;

    for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
        sf::Rect<int> menuItemRect = (*it).rect;
        if (menuItemRect.top < y && menuItemRect.top + menuItemRect.height  > y
            && menuItemRect.left < x && menuItemRect.width > x) {
            return (*it).action;
        }
    }

    return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& renderWindow) {
    sf::Event menuEvent;

    while (true) {
        while (renderWindow.pollEvent(menuEvent)) {
            if (menuEvent.type == sf::Event::MouseButtonPressed) {
                if (ServiceLocator::GetAudio()->IsSongPlaying()) {
                    ServiceLocator::GetAudio()->StopAllSounds();
                }
                return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
            if (menuEvent.type == sf::Event::Closed) {
                return Exit;
            }
        }
    }
}