#pragma once
#include"Core.h"

namespace Kilo {
class KILO_API Application {
public:
	Application();
	virtual ~Application();
	void Run();
};
//To Be Defined In Client
Application* CreateApplication();
}