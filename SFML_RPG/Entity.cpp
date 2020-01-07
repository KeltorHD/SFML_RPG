#include "stdafx.h"
#include "Entity.h"

void Entity::initVariables()
{
	this->hitboxComponent = NULL;
	this->animationComponent = NULL;
	this->movementComponent = NULL;
}

Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->hitboxComponent;
	delete this->movementComponent;
	delete this->animationComponent;
}

//component func

void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

void Entity::createHitboxComponent(sf::Sprite& Sprite,
	float offset_x, float offset_y,
	float width, float height)
{
	this->hitboxComponent = new HitboxComponent(this->sprite, offset_x, offset_y, width, height);
}

const sf::Vector2f& Entity::getPosition() const
{
	if (this->hitboxComponent)
		return this->hitboxComponent->getPosition();
	
	return this->sprite.getPosition();
}

const sf::FloatRect& Entity::getGlobalBounds() const
{
	if (this->hitboxComponent)
		return this->hitboxComponent->getGlobalBounds();

	return this->sprite.getGlobalBounds();
}

//func

void Entity::setPosition(const float x, const float y)
{
	if (this->hitboxComponent)
		return this->hitboxComponent->setPosition(x,y);
	else 
		this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y, const float& dt)
{
	if (this->movementComponent)
		this->movementComponent->move(dir_x, dir_y, dt); //sets velocity
	else
		this->sprite.move(dir_x * dt, dir_y * dt);
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget& target)
{
	
}
