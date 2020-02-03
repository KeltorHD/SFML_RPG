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

	//accessors
	AttributeComponent* getAttributeComponent();

	//func
	void loseHp(const int hp);
	void gainHp(const int hp);
	void loseExp(const int exp);
	void gainExp(const int exp);
	void updateAttack();
	void updateAnimation(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget& target);
};


#endif // !PLAYER_H