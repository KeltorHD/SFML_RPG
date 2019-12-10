#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <map>
#include <iostream>
#include <string>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"


class AnimationComponent
{
private:
	class Animation
	{
	public:
		Animation();
		
		//func
		void play();
		void pause();
		void reset();
	};

	std::map<std::string, Animation> animations;
public:

	AnimationComponent();
	virtual ~AnimationComponent();

	//func
};



#endif // !ANIMATIONCOMPONENT_H