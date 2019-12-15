#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };
namespace gui
{
	class Button
	{
	private:
		short unsigned buttonState;


		sf::RectangleShape shape;
		sf::Font* font;
		sf::Text text;

		sf::Color textIdleColor;
		sf::Color textHoverColor;
		sf::Color textActiveColor;

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;



	public:
		Button(float x, float y, float width, float height,
			sf::Font* font, std::string text,
			unsigned character_size,
			sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
			sf::Color idle_color, sf::Color hover_color,
			sf::Color active_color);
		~Button();

		//Accessors
		const bool isPressed() const;
		const std::string& getText() const;

		//Modifiers
		void setText(const std::string text);

		//Func
		void update(const sf::Vector2f& mousePos);
		void render(sf::RenderTarget& target);

	};

	class DropDownList
	{
	private:
		sf::Font& font;
		gui::Button* activeElement;
		std::vector<gui::Button*> list;
		

	public:
		DropDownList(sf::Font& font, std::string list[], unsigned nrOfElemetn, unsigned default_index = 0);
		~DropDownList();

		void update(const sf::Vector2f& mousePos);
		void render(sf::RenderTarget& target);
	};
}

#endif // !GUI_H