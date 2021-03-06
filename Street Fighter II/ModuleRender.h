#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "Module.h"
#include "SDL\include\SDL_rect.h"

struct SDL_Renderer;
struct SDL_Texture;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status Update();
	update_status PreUpdate();
	bool CleanUp();

	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f, bool use_camera = true);
	bool RectBlit2(SDL_Texture* texture, SDL_Rect* section, SDL_Rect* dsrect);
	bool RectBlit2Sym(SDL_Texture* texture, SDL_Rect* section, SDL_Rect* dsrect);
	bool BlitSym(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f, bool use_camera = true);
	bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);
	bool RectBlit(const SDL_Rect& rect, SDL_Texture* texture);

	void StartCameraShake(int duration, float magnitude);
	void UpdateCameraShake();

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;	
	
private:
	bool shaking = false;

	int shake_duration = 0.0f;
	int shake_timer = 0.0f;
	float shake_magnitude = 0.0f;

	SDL_Point camera_offset;
};

#endif //__ModuleRenderer_H__