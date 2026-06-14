#include <sstream>
#include "Application.h"
#include"Event/ApplicationEvent.h"
#include"Log.h"

namespace Kilo {
	Application::Application() 
	{
		
	}

	Application::~Application() 
	{

	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCatagory(EventCatagoryApp))
		{
			KL_CORE_TRACE("{0}",e.ToString());
			
		}
		while (true);
	}
}