#include "stdafx.h"
#include "Player.h"

//init func
void Player::initVariables()
{
	this->attacking = false;
}

void Player::initComponents()
{
	
}


//const / destr
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 86.f, 65.f, 86.f, 120.f);
	this->createMovementComponent(350.f, 1500.f, 500.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1);

	this->animationComponent->addAnimation("IDLE", 11.f, 0, 0, 13, 0, 192, 192);
	this->animationComponent->addAnimation("WALK", 6.f, 0, 1, 11, 1, 192, 192);
	this->animationComponent->addAnimation("ATTACK", 5.f, 0, 2, 13, 2, 192*2, 192);
}

Player::~Player()
{

}

//accessors
AttributeComponent* Player::getAttributeComponent()
{
	return this->attributeComponent;
}

//func
void Player::loseHp(const int hp)
{
	this->attributeComponent->hp -= hp;
	if (this->attributeComponent->hp < 0)
		this->attributeComponent->hp = 0;
}

void Player::gainHp(const int hp)
{
	this->attributeComponent->hp += hp;
	if (this->attributeComponent->hp > this->attributeComponent->hpMax)
		this->attributeComponent->hp = this->attributeComponent->hpMax;
}

void Player::loseExp(const int exp)
{
	this->attributeComponent->exp -= exp;
	if (this->attributeComponent->exp < 0)
		this->attributeComponent->exp = 0;
}

void Player::gainExp(const int exp)
{
	this->attributeComponent->gainExp(exp);
}

void Player::updateAttack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->sprite.setOrigin(0.f, 0.f);
		this->sprite.setScale(1.f, 1.f);
		this->attacking = true;
	}
}

void Player::updateAnimation(const float& dt)
{
	if (this->attacking)
	{
		

		//animate and check for animation end
		if (this->animationComponent->play("ATTACK", dt, true))
		{
			this->attacking = false;

			//set origin on direction
			if (this->sprite.getScale().x > 0.f) //facing left
			{
				this->sprite.setOrigin(0.f, 0.f);

			}
			else //facing right
			{
				this->sprite.setOrigin(258.f, 0.f);
			}
		}
	}

	if (this->movementComponent->getState(IDLE))
	{
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		if (this->sprite.getScale().x < 0.f)
		{
			this->sprite.setOrigin(0.f, 0.f);
			this->sprite.setScale(1.f, 1.f);
		}
		this->animationComponent->play("WALK", dt);//, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		if (this->sprite.getScale().x > 0.f)
		{
			this->sprite.setOrigin(258.f, 0.f);
			this->sprite.setScale(-1.f, 1.f);
		}
		this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		/*this->sprite.setOrigin(258.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);*/
		this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		/*this->sprite.setOrigin(258.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);*/
		this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
}

void Player::update(const float& dt)
{
	this->attributeComponent->update();

	this->movementComponent->update(dt);

	this->updateAttack();

	this->updateAnimation(dt);
	
	this->hitboxComponent->update();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	this->hitboxComponent->render(target);
}