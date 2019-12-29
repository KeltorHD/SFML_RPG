#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"

class GameState :
	public State
{
private:
	PauseMenu* pmenu;
	sf::Font font;
	Player* player;

	TileMap* tileMap;

	//Func
	void initFonts();
	void initKeybinds();
	void initTextures();
	void initPlayers();
	void initPauseMenu();
	void initTileMap();
public:
	GameState(StateData* state_data);
	virtual ~GameState();

	//func

	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updatePauseMenuButtons();
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};


#endif // !GAMESTATE_H