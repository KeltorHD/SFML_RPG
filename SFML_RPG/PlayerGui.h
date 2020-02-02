#ifndef PLAYERGUI_H

#include "Player.h"

class Player;

class PlayerGui
{
private:
	Player* player;

	sf::Font font;

	/* EXP bar */


	/* HP Bar */
	std::string hpBarString;
	sf::Text HpBarText;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;

	float hpBarMaxWidth;

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