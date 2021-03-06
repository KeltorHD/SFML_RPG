#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "Gui.h"

class PauseMenu
{
private:
	sf::Font& font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;


	std::map<std::string, gui::Button*> buttons;
	//func

public:
	PauseMenu(sf::RenderWindow& window, sf::Font& font);
	virtual ~PauseMenu();

	//accessor
	std::map<std::string, gui::Button*>& getButton();

	//func
	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key, float y, const std::string text);
	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderTarget& target);
};



#endif // !PAUSEMENU_H