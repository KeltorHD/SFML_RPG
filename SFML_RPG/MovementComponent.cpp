#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, 
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}


//FUNC
void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	//acceleration
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{
	/*
	Decelerate the sprite and controls the maximum velocity.
	Move the Sprite.
	*/
	if (this->velocity.x > 0.f) //chek for positive x
	{
		//max velocity check
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = maxVelocity;

		//deceleration
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else if (this->velocity.x < 0.f) //check for negative x
	{
		//max velocity check
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -maxVelocity;

		//deceleration
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	if (this->velocity.y > 0.f) //chek for positive y
	{
		//max velocity check
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = maxVelocity;

		//deceleration
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f) //check for negative y
	{
		//max velocity check
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -maxVelocity;

		//deceleration
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}

	//final move
	this->sprite.move(this->velocity * dt); //uses velocity
}
