#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player :
	public Entity
{
private:
	//var
	bool attacking;

	//init func
	void initVariables();
	void initComponents();
public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();

	//func
	void updateAttack();
	void updateAnimation(const float& dt);
	virtual void update(const float& dt);
};


#endif // !PLAYER_H