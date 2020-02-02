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
	float width = 300.f;
	float height = 50.f;
	float x = 20.f;
	float y = 20.f;

	this->hpBarMaxWidth = width;

	this->hpBarBack.setSize(sf::Vector2f(width, height));
	this->hpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->hpBarBack.setPosition(x, y);

	this->hpBarInner.setSize(sf::Vector2f(width, height));
	this->hpBarInner.setFillColor(sf::Color(150, 20, 20, 200));
	this->hpBarInner.setPosition(this->hpBarBack.getPosition());

	this->HpBarText.setFont(this->font);
	this->HpBarText.setPosition
	(
		this->hpBarInner.getPosition().x + 10.f,
		this->hpBarInner.getPosition().y + 5.f
	);
}

void PlayerGui::updateHpBar()
{
	float percent = static_cast<float>(this->player->getAttributeComponent()->hp) / static_cast<float>(this->player->getAttributeComponent()->hpMax);
	/*
	std::cout << this->player->getAttributeComponent()->hp<<std::endl;
	std::cout << this->player->getAttributeComponent()->hpMax<<std::endl;
	*/
	this->hpBarInner.setSize(
		sf::Vector2f(
			static_cast<float>(std::floor(this->hpBarMaxWidth * percent)),
			this->hpBarInner.getSize().y
		)
	);

	this->hpBarString = std::to_string(this->player->getAttributeComponent()->hp) + "|" + std::to_string(this->player->getAttributeComponent()->hpMax);
	this->HpBarText.setString(this->hpBarString);
}

//public func
void PlayerGui::update(const float& dt)
{
	this->updateHpBar();
}

void PlayerGui::renderHpBar(sf::RenderTarget& target)
{
	target.draw(this->hpBarBack);
	target.draw(this->hpBarInner);
	target.draw(this->HpBarText);
}

void PlayerGui::render(sf::RenderTarget& target)
{
	this->renderHpBar(target);
}