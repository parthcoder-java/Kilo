#include<Kilo.h>
#include"Terreria.h"

Terreria::Terreria(){}
Terreria::~Terreria(){}
Kilo::Application* Kilo::CreateApplication() 
{
	return new Terreria();
}