#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


class Player :
	public Entity
{
private:
	//var

	//init func
	void initVariables();
	void initComponents();
public:
	Player(float x, float y, sf::Texture& texture);
	virtual ~Player();

	//func

};


#endif // !PLAYER_H