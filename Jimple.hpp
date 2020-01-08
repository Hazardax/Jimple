#ifndef JIMPLE_GAME_ENGINE
#define JIMPLE_GAME_ENGINE

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

namespace jp
{

	// MATHS
	struct Vec2f
	{
		float x{ 0.0f };
		float y{ 0.0f };

		Vec2f() {}
		Vec2f(float x, float y) : x(x), y(y) {}
	};

	struct Vec2i
	{
		int x{ 0 };
		int y{ 0 };

		Vec2i() {}
		Vec2i(int x, int y) : x(x), y(y) {}
	};



	/* FOR THE FUTURE
	struct Event
	{
		bool MousePressed();
		bool MouseReleased();

		bool KeyPressed();
		bool KeyReleased();
	};*/

	// WINDOW 
	struct Window
	{
		Vec2i dimensions{ 800, 600 };
		std::string title{ "JimpleWindow" };

		bool isOpen{ false };

		// STATES
		bool isResizable{ false };
		bool isFullscreen{ false };
		bool isBorderless{ false };
	};

	class GameWindow
	{
	private:
		Window window;
		sf::RenderWindow rendWindow;

	public:

		virtual void OnCreate() {}
		virtual void OnUpdate() {}

		GameWindow() { window.isOpen = true; }
		virtual ~GameWindow() {  }
		
		bool Opened()
		{ 
			if (window.isOpen) return true;
			else return false;
		}

		void SetSize(Vec2i dimensions) { rendWindow.setSize(sf::Vector2u(dimensions.x, dimensions.y)); }
		Vec2i GetSize() { return Vec2i(rendWindow.getSize().x, rendWindow.getSize().y); }

		void Run(Vec2i dimensions, std::string title)
		{
			rendWindow.create(sf::VideoMode(dimensions.x, dimensions.y), title);
			OnCreate();
			OnUpdate();
			
		}
		void Run()
		{
			rendWindow.create(sf::VideoMode(window.dimensions.x, window.dimensions.y), window.title);
			OnCreate();
			OnUpdate();

		}
	};

}

#endif