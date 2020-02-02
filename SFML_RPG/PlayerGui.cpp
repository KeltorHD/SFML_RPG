#include "stdafx.h"
#include "PlayerGui.h"

//constr/destr
PlayerGui::PlayerGui(Player* player)
{
	this->player = player;

	this->initFont();
	this->initHpBar();
}

PlayerGui::~PlayerGui()
{
}

//private func
void PlayerGui::initFont()
{
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");
}

void PlayerGui::initHpBar()
{
	float width = 200.f;
	float height = 40.f;
	float x = 20.f;
	float y = 20.f;

	this->hpBarBack.setSize(sf::Vector2f(width, height));
	this->hpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->hpBarBack.setPosition(x, y);


	this->hpBarInner.setSize(sf::Vector2f(width, height));
	this->hpBarInner.setFillColor(sf::Color(150, 20, 20, 200));
	this->hpBarInner.setPosition(x, y);
}

void PlayerGui::updateHpBar()
{
}

//public func
void PlayerGui::update(const float& dt)
{
}

void PlayerGui::renderHpBar(sf::RenderTarget& target)
{
	target.draw(this->hpBarBack);
	target.draw(this->hpBarInner);
}

void PlayerGui::render(sf::RenderTarget& target)
{
	this->renderHpBar(target);
}