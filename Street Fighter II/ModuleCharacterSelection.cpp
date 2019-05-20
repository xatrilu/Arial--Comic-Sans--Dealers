#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Module.h"
#include "ModuleCharacterSelection.h"
#include "ModuleAudio.h"
#include "ModuleLoseScene.h"
#include "ModuleSceneDhalsim.h"

ModuleCharacterSelection::ModuleCharacterSelection()
{
	//Background
	background.x = 0;
	background.y = 0;
	background.h = SCREEN_HEIGHT;
	background.w = SCREEN_WIDTH;

	//Map
	Map.x = 53;
	Map.y = 777;
	Map.w = 1302;
	Map.h = 73;


	//P2Pointer


	//P1Pointer

}

ModuleCharacterSelection::~ModuleCharacterSelection()
{}


bool ModuleCharacterSelection::Start()
{
	LOG("Loading characters selection");

	graphicsBack = App->textures->Load("Assets/Images/Player_Select.png");
	graphicsUI = App->textures->Load("Assets/Images/Character_Selection_UI.png");
	//music = App->audio->LoadMusic("Assets/Sound/Musics/start_music.ogg");
	//App->audio->PlayMusic(music, 300);
	//start_sound = App->audio->LoadChunk("Assets/Sound/start_sound.wav");
	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

bool ModuleCharacterSelection::CleanUp()
{
	LOG("Unloading Selection page");

	App->textures->Unload(graphicsBack);
	App->textures->Unload(graphicsUI);
	//App->audio->UnloadMusic(music);

	return true;
}

update_status ModuleCharacterSelection::Update()
{

	App->render->Blit(graphicsBack, 0, 0, &background);
	App->render->Blit(graphicsUI, -340, 160, &Map);

	/*if (App->input->keyboard[SDL_SCANCODE_RETURN] == KEY_DOWN || App->input->Pad1.button_state[SDL_CONTROLLER_BUTTON_START] == KEY_DOWN || App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_START] == KEY_DOWN) {
		App->fade->FadeToBlack(App->selectionScene, App->scene_dhalsim, 2.0f);
		App->audio->PlayChunk(start_sound, 0);
		App->audio->StopMusic(250);
	}*/

	return UPDATE_CONTINUE;
}