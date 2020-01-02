#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"

class PauseMenu;
class Player;
class TileMap;

class GameState :
	public State
{
private:
	sf::View view;
	sf::RenderTexture renderTexture;
	sf::Sprite renderSprite;

	PauseMenu* pmenu;
	sf::Font font;
	Player* player;

	TileMap* tileMap;

	//Func
	void initView();
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPlayers();
	void initPauseMenu();
	void initTileMap();
public:
	GameState(StateData* state_data);
	virtual ~GameState();

	//func
	void updateView(const float& dt);
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updatePauseMenuButtons();
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};


#endif // !GAMESTATE_H