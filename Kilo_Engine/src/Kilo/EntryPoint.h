#pragma once
#ifdef KL_PLATFORM_WINDOWS

extern Kilo::Application* Kilo::CreateApplication();

int main(int argc, char** argv) {

	Kilo::Log::Init();
	KL_CORE_WARN("Initialized Kilo Core");
	int a = 5;
	KL_INFO("Building App");

	auto app = Kilo::CreateApplication();
	app->Run();
	delete app;

}
#endif