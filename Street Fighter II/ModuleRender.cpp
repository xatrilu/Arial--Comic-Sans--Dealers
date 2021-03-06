#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleWelcomePage.h"
#include "ModuleCongratsScreen.h"
#include <cstdlib>
#include <time.h>
#include "SDL/include/SDL.h"

ModuleRender::ModuleRender() : Module()
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;	

	camera_offset.x = camera_offset.y = 0;

	srand(time(NULL));
}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if(REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}
	
	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	SDL_RenderSetLogicalSize(renderer, 384, 224);

	if(renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	SDL_RenderClear(renderer); 

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::Update()	
{
	int speed = 3;

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	SDL_RenderPresent(renderer);
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if(renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed, bool use_camera)
{
	bool ret = true;

	SDL_Rect rect;

	if (use_camera) {
		rect.x = (int)((camera.x + camera_offset.x) * speed) + x * SCREEN_SIZE;
		rect.y = (int)((camera.y + camera_offset.x) * speed) + y * SCREEN_SIZE;

		if (section != NULL)
		{
			rect.w = section->w;
			rect.h = section->h;
		}
		else
		{
			SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
		}

	}

	if (use_camera == false) {
		rect.x = (int)((camera.x + camera_offset.x) * speed) + x * SCREEN_SIZE;
		rect.y = (int)((camera.y + camera_offset.x) * speed) + y * SCREEN_SIZE;

		if (section != NULL)
		{
			rect.w = section->w;
			rect.h = section->h;
		}
		else
		{
			SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
		}

	}
	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;
	
	SDL_RenderCopy(renderer, texture, section, &rect);

	return ret;
}

bool ModuleRender::RectBlit2(SDL_Texture* texture, SDL_Rect* section, SDL_Rect* dsrect)
{
	bool ret = true;

	SDL_RenderCopy(renderer, texture, section, dsrect);

	return ret;
}

bool ModuleRender::RectBlit2Sym(SDL_Texture* texture, SDL_Rect* section, SDL_Rect* dsrect)
{
	bool ret = true;

	SDL_RenderCopyEx(renderer, texture, section, dsrect, 0, NULL, SDL_FLIP_HORIZONTAL);

	return ret;
}

// Blit to screen on an rotation angle of 90 degrees
bool ModuleRender::BlitSym(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed, bool use_camera)
{
	bool ret = true;

	SDL_Rect rect;
	SDL_Point p;
	p.x = section->w / 2;
	p.y = section->y + section->h;

	if (use_camera) {
		rect.x = (int)((camera.x + camera_offset.x) * speed) + x * SCREEN_SIZE;
		rect.y = (int)((camera.y + camera_offset.x) * speed) + y * SCREEN_SIZE;

		if (section != NULL)
		{
			rect.w = section->w;
			rect.h = section->h;
		}
		else
		{
			SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
		}

	}

	if (use_camera == false) {
		rect.x = (int)((camera.x + camera_offset.x) * speed) + x * SCREEN_SIZE;
		rect.y = (int)((camera.y + camera_offset.x) * speed) + y * SCREEN_SIZE;

		if (section != NULL)
		{
			rect.w = section->w;
			rect.h = section->h;
		}
		else
		{
			SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
		}

	}
	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

			SDL_RenderCopyEx(renderer, texture, section, &rect, 0, NULL, SDL_FLIP_HORIZONTAL);


	return ret;
}

bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);
		rec.y = (int)(camera.y + rect.y * SCREEN_SIZE);
		rec.w *= SCREEN_SIZE;
		rec.h *= SCREEN_SIZE;
	}

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleRender::RectBlit(const SDL_Rect& rect, SDL_Texture* texture) {

	bool ret = true;

	if (SDL_RenderCopy(App->render->renderer, texture, &rect, NULL) == -1) { ret = false; }

	return ret;
}

void ModuleRender::StartCameraShake(int duration, float magnitude) {
	shaking = true;

	shake_duration = duration;
	shake_timer = SDL_GetTicks();
	shake_magnitude = magnitude;
}

void ModuleRender::UpdateCameraShake() {
	if (shake_duration + shake_timer > SDL_GetTicks()) {
		camera_offset.x = (rand() % (int)shake_magnitude * 2 - (int)shake_magnitude);
		camera_offset.y = (rand() % (int)shake_magnitude * 2 - (int)shake_magnitude);
	}
	else {
		shake_duration = 0;
		camera_offset.x = 0;
		camera_offset.y = 0;
		shaking = false;
	}
}

