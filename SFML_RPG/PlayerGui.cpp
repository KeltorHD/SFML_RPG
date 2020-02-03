#include "stdafx.h"
#include "PlayerGui.h"

//constr/destr
PlayerGui::PlayerGui(Player* player)
{
	this->player = player;

	this->initFont();
	this->initHpBar();
	this->initExpBar();
}

PlayerGui::~PlayerGui()
{
}

//private func
void PlayerGui::initFont()
{
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");
}

void PlayerGui::initExpBar()
{
	float width = 200.f;
	float height = 40.f;
	float x = 20.f;
	float y = 80.f;

	this->expBarMaxWidth = width;

	this->expBarBack.setSize(sf::Vector2f(width, height));
	this->expBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->expBarBack.setPosition(x, y);

	this->expBarInner.setSize(sf::Vector2f(width, height));
	this->expBarInner.setFillColor(sf::Color(20, 20, 250, 200));
	this->expBarInner.setPosition(this->expBarBack.getPosition());

	this->expBarText.setFont(this->font);
	this->expBarText.setCharacterSize(20);
	this->expBarText.setPosition
	(
		this->expBarInner.getPosition().x + 10.f,
		this->expBarInner.getPosition().y + 5.f
	);
}

void PlayerGui::initHpBar()
{
	float width = 200.f;
	float height = 40.f;
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
	this->HpBarText.setCharacterSize(20);
	this->HpBarText.setPosition
	(
		this->hpBarInner.getPosition().x + 10.f,
		this->hpBarInner.getPosition().y + 5.f
	);
}

void PlayerGui::updateHpBar()
{
	float percent = static_cast<float>(this->player->getAttributeComponent()->hp) / static_cast<float>(this->player->getAttributeComponent()->hpMax);

	this->hpBarInner.setSize(
		sf::Vector2f(
			static_cast<float>(std::floor(this->hpBarMaxWidth * percent)),
			this->hpBarInner.getSize().y
		)
	);

	this->hpBarString = std::to_string(this->player->getAttributeComponent()->hp) + " | " + std::to_string(this->player->getAttributeComponent()->hpMax);
	this->HpBarText.setString(this->hpBarString);
}

void PlayerGui::updateExpBar()
{
	float percent = static_cast<float>(this->player->getAttributeComponent()->exp) / static_cast<float>(this->player->getAttributeComponent()->expNext);

	this->expBarInner.setSize(
		sf::Vector2f(
			static_cast<float>(std::floor(this->expBarMaxWidth * percent)),
			this->expBarInner.getSize().y
		)
	);

	this->expBarString = std::to_string(this->player->getAttributeComponent()->exp) + " | " + std::to_string(this->player->getAttributeComponent()->expNext);
	this->expBarText.setString(this->expBarString);
}

//public func
void PlayerGui::update(const float& dt)
{
	this->updateHpBar();
	this->updateExpBar();
}

void PlayerGui::renderHpBar(sf::RenderTarget& target)
{
	target.draw(this->hpBarBack);
	target.draw(this->hpBarInner);
	target.draw(this->HpBarText);
}

void PlayerGui::renderExpBar(sf::RenderTarget& target)
{
	target.draw(this->expBarBack);
	target.draw(this->expBarInner);
	target.draw(this->expBarText);
}

void PlayerGui::render(sf::RenderTarget& target)
{
	this->renderHpBar(target);
	this->renderExpBar(target);
}