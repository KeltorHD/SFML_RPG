#ifndef PLAYERGUI_H

#include "Player.h"

class Player;

class PlayerGui
{
private:
	Player* player;

	sf::Font font;

	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;

	//func
	void initFont();
	void initHpBar();
public:
	PlayerGui(Player* player);
	~PlayerGui();

	//func
	void updateHpBar();
	void update(const float& dt);
	void renderHpBar(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

#endif // !PLAYERGUI_H