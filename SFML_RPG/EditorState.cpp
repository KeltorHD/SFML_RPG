#include "stdafx.h"
#include "EditorState.h"

//Init func
void EditorState::initVariables()
{
	this->textureRect = sf::IntRect(0, 0, static_cast<int>(this->stateData->gridSize), static_cast<int>(this->stateData->gridSize));

}

void EditorState::initBackground()
{
	
}

void EditorState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT");
	}

}

void EditorState::initText()
{
	this->cursorText.setFont(this->font);
	this->cursorText.setCharacterSize(12);
	this->cursorText.setFillColor(sf::Color::White); 
	this->cursorText.setPosition(this->mousePosView.x + 100.f, this->mousePosView.y -50.f);
}

void EditorState::initKeybinds()
{
	std::ifstream ifs("Config/editorstate_keybinds.ini");

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

void EditorState::initPauseMenu()
{
	this->pmenu = new PauseMenu(*this->window, this->font);

	this->pmenu->addButton("QUIT", 800.f, "Quit");
}

void EditorState::initButtons()
{
	
}

void EditorState::initGui()
{
	this->selectorRect.setSize(sf::Vector2f(this->stateData->gridSize, this->stateData->gridSize));

	this->selectorRect.setFillColor(sf::Color(255, 255, 255, 150));
	this->selectorRect.setOutlineThickness(1.f);
	this->selectorRect.setOutlineColor(sf::Color::Green);

	this->selectorRect.setTexture(this->tileMap->getTileSheet());
	this->selectorRect.setTextureRect(this->textureRect);
	
	this->textureSelector = new gui::TextureSelector(20.f, 20.f, 500.f, 500.f, this->stateData->gridSize, this->tileMap->getTileSheet());
}

void EditorState::initTileMap()
{
	this->tileMap = new TileMap(this->stateData->gridSize, 10, 10);
}

EditorState::EditorState(StateData* state_data)
	: State(state_data)
{
	this->initBackground();
	this->initVariables();
	this->initFonts();
	this->initText();
	this->initKeybinds();
	this->initPauseMenu();
	this->initButtons();
	this->initTileMap();
	this->initGui();
}

EditorState::~EditorState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

	delete this->pmenu;

	delete this->tileMap;

	delete this->textureSelector;
}


//func 
void EditorState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeyTime())
	{
		if (!this->paused)
		{
			this->pauseState();
		}
		else
			this->unpauseState();
	}
}

void EditorState::updateEditorInput(const float& dt)
{
	//add a Tile
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeyTime())
	{
		this->tileMap->addTile(this->mousePosGrid.x, this->mousePosGrid.y, 0, this->textureRect);
	}
	//remove a Tile
	else
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->getKeyTime())
	{
		this->tileMap->removeTile(this->mousePosGrid.x, this->mousePosGrid.y, 0);
	}
	//change texture
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getKeyTime())
	{
		if (this->textureRect.left < 100)
		{
			this->textureRect.left += 100;
		}
	}
}

void EditorState::updateButtons()
{
	/*Updates all the buttons in this state*/

	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

void EditorState::updateGui()
{
	this->selectorRect.setTextureRect(this->textureRect);
	this->selectorRect.setPosition(this->mousePosGrid.x * this->stateData->gridSize, this->mousePosGrid.y * this->stateData->gridSize);

	this->cursorText.setPosition(this->mousePosView.x + 100.f, this->mousePosView.y - 50.f);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y
		<< "\n" << this->mousePosGrid.x << " " << this->mousePosGrid.y
		<< "\n" << this->textureRect.left << " " << this->textureRect.top;
	this->cursorText.setString(ss.str());

	this->textureSelector->update(this->mousePosWindow);
}

void EditorState::updatePauseMenuButtons()
{
	if (this->pmenu->isButtonPressed("QUIT"))
		this->endState();
}

void EditorState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeyTime(dt);
	this->updateInput(dt);

	if (!this->paused) //unpaused
	{
		this->updateGui();
		this->updateButtons();
		this->updateEditorInput(dt);
	}
	else //paused
	{
		this->pmenu->update(this->mousePosView);
		this->updatePauseMenuButtons();
	}

	this->updateButtons();
}

void EditorState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void EditorState::renderGui(sf::RenderTarget& target)
{
	target.draw(this->selectorRect);
	this->textureSelector->render(target);
	target.draw(this->cursorText);
}

void EditorState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	this->tileMap->render(*target);

	this->renderButtons(*target);
	this->renderGui(*target);

	if (this->paused) //pause menu render
	{
		this->pmenu->render(*target);
	}
}

