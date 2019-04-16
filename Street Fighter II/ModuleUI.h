#ifndef _MODULEUI_H
#define _MODULEUI_H

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleUI : public Module
{
public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics1 = nullptr;
	SDL_Texture* graphics2 = nullptr;

	SDL_Rect HealthBar1;
	SDL_Rect HealthBar2;
	SDL_Rect KObar;

};

#endif // !_MODULEUI_H
