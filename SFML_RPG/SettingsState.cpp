#include "SettingsState.h"

//init
void SettingsState::initVariables()
{
	this->modes = sf::VideoMode::getFullscreenModes();
}

void SettingsState::initBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));
	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
	{
		throw "ERROR::SETTINGSSTATE::FAILED_LOAD_BACKGROUND";
	}
	this->background.setTexture(&this->backgroundTexture);
}

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::SETTINGSSTATE::COULD NOT LOAD FONT");
	}

}

void SettingsState::initKeybinds()
{
	std::ifstream ifs("Config/SettingsState_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void SettingsState::initGui()
{
	this->buttons["BACK"] = new gui::Button(
		1500.f, 880.f, 250.f, 50.f,
		&this->font, "Back", 50,

		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 250),
		sf::Color(20, 20, 20, 50),

		sf::Color(100, 100, 100, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));
	
	this->buttons["APPLY"] = new gui::Button(
		1300.f, 880.f, 250.f, 50.f,
		&this->font, "Apply", 50,

		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 250),
		sf::Color(20, 20, 20, 50),

		sf::Color(100, 100, 100, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));

	std::vector<std::string> modes_str;
	for (auto& i : this->modes)
	{
		modes_str.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));
	}
	this->dropDownLists["RESOLUTION"] = new gui::DropDownList(800, 450, 200, 50, font, modes_str.data(), modes_str.size());
}

void SettingsState::initText()
{
	this->optionsText.setFont(this->font);
	this->optionsText.setPosition(sf::Vector2f(100.f, 450.f));
	this->optionsText.setCharacterSize(30.f);
	this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));

	this->optionsText.setString(
		"Resolution Fullscreen \n\n Vsunc \n\n Antialiasing \n\n"
	);
}

//const /destr
SettingsState::SettingsState(sf::RenderWindow* window, std::map <std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initBackground();
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
	this->initText();
}

SettingsState::~SettingsState()
{
	for (auto it = this->buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
	for (auto it = this->dropDownLists.begin(); it != dropDownLists.end(); ++it)
	{
		delete it->second;
	}
}

//func
void SettingsState::updateInput(const float& dt)
{

}

void SettingsState::updateGui(const float& dt)
{
	/*Updates all the gui in this state*/

	//Buttons
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//Quit the game
	if (this->buttons["BACK"]->isPressed())
	{
		this->endState();
	}

	//Apply selected settings
	if (this->buttons["APPLY"]->isPressed())
	{
		//testing - REMOVE LATER
		this->window->create(this->modes[this->dropDownLists["RESOLUTION"]->getActiveElementId()], "TEST", sf::Style::Default);
	}

	//Dropdow list
	for (auto& it : this->dropDownLists)
	{
		it.second->update(this->mousePosView, dt);
	}
}

void SettingsState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateGui(dt);
}

void SettingsState::renderGui(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
	for (auto& it : this->dropDownLists)
	{
		it.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->background);

	this->renderGui(*target);

	target->draw(this->optionsText);

	//Remove later
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);
}