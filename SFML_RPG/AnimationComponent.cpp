#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	: sprite(sprite), textureSheet(texture_sheet)
{
}

AnimationComponent::~AnimationComponent()
{
}

//func


void AnimationComponent::update(const float& dt)
{

}
