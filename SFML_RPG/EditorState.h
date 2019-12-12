#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"
#include "Button.h"

class EditorState :
	public State
{
private:
	//Var
	sf::Font font;

	std::map<std::string, Button*>buttons;

	//Func
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initButtons();
public:
	EditorState(sf::RenderWindow* window, std::map <std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~EditorState();

	//func

	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = NULL);
	void render(sf::RenderTarget* target = NULL);

};



#endif // !EDITORSTATE_H