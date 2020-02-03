#ifndef PLAYERGUI_H

#include "Player.h"

class Player;

class PlayerGui
{
private:
	Player* player;

	sf::Font font;

	/* EXP bar */
	std::string expBarString;
	sf::Text expBarText;
	sf::RectangleShape expBarBack;
	sf::RectangleShape expBarInner;
	float expBarMaxWidth;

	/* HP Bar */
	std::string hpBarString;
	sf::Text HpBarText;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;
	float hpBarMaxWidth;


	//func
	void initFont();
	void initExpBar();
	void initHpBar();
public:
	PlayerGui(Player* player);
	~PlayerGui();

	//func
	void updateHpBar();
	void updateExpBar();
	void update(const float& dt);

	void renderHpBar(sf::RenderTarget& target);
	void renderExpBar(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

#endif // !PLAYERGUI_H