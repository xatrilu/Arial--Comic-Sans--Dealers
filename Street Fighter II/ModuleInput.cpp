#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	camMoving = false;
	border = false;
	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	eventList.clear();
	SDL_PumpEvents();
	SDL_Event event;
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	if (keyboard[SDL_SCANCODE_ESCAPE])
		return update_status::UPDATE_STOP;

	/*if (keyboard[SDL_SCANCODE_F11] && App->win_scene->isEnabled()==true)
	{
		App->fade->FadeToBlack(App->scene_ryu, App->win_scene, 1.0f);
		App->audio->StopMusic(2500);
	}*/

	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT) { return update_status::UPDATE_STOP; }
		eventList.push_back(event);
	}
	

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}