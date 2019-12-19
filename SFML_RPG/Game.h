#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game
{
private:
	class GraphicsSettings
	{
	public:
		GraphicsSettings()
		{
			this->title = "DEFAULT";
			this->resolution = sf::VideoMode::getDesktopMode();
			this->fullscreen = false;
			this->verticalSync = false;
			this->framerateLimit = 120;
			this->contextSettings.antialiasingLevel = 0;
			this->videoModes = sf::VideoMode::getFullscreenModes();
		}

		//variables
		std::string title;
		sf::VideoMode resolution;
		bool fullscreen;
		bool verticalSync;
		unsigned framerateLimit;
		sf::ContextSettings contextSettings;
		std::vector<sf::VideoMode> videoModes;

		//func
		void saveToFile(const std::string path)
		{
			std::ofstream ofs(path);

			if (ofs.is_open())
			{
				ofs << this->title;
				ofs << this->resolution.width << " " << this->resolution.height;
				ofs << this->fullscreen;
				ofs << this->framerateLimit;
				ofs << this->verticalSync;
				ofs << this->contextSettings.antialiasingLevel;
			}
			ofs.close();
		}
		void loadFromFile(const std::string path)
		{
			std::ifstream ifs(path);

			if (ifs.is_open())
			{
				std::getline(ifs, this->title);
				ifs >> this->resolution.width >> this->resolution.height;
				ifs >> this->fullscreen;
				ifs >> this->framerateLimit;
				ifs >> this->verticalSync;
				ifs >> this->contextSettings.antialiasingLevel;
			}
			ifs.close();
		}
	};

	//Variables
	GraphicsSettings gfxSettings;
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Initialization
	void initVariables();
	void initGraphicsSettings();
	void initWindow();
	void initKeys();
	void initStates();
public:
	//Constructor/Destructor
	Game();
	virtual ~Game();

	//func

	//regular
	void endApplication();

	//update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//render
	void render();

	//core
	void run();
};

#endif