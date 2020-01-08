#include "Jimple.hpp"

using namespace jp;

class App : public GameWindow
{
private:
	GameWindow window;
public: App() { std::cout << "Successfully created!! My congrats!" << std::endl; }

public:
	void OnCreate() override
	{
	}
	void OnUpdate() override
	{
		while (window.Opened())
		{
		}
	}
};

int main()
{
	App app;
	app.Run(Vec2i(800, 600), "JimpleWindow");
	return 0;
}