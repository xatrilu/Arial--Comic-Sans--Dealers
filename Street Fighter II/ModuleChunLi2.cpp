#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleChunLi.h"
#include "ModuleParticles.h"
#include "ModuleChunLi2.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleUI.h"
#include "p2Qeue.h"
#include "Application.h"
#include "ModuleSceneDhalsim.h"
#include "ModuleCombos.h"
#include "ModuleSlowdown.h"
#include"ModuleFadeToBlack.h"
#include "ModuleCongratsScreen.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleChunLi2::ModuleChunLi2()
{
	// idle animation (arcade sprite sheet)

	


	const int idleCollider = 5;//Collider num for the idle animation
	SDL_Rect idleHitbox[idleCollider] = { { 14, 71, 31, 21 },{ 3, 37, 35, 41 },{ 16, 3, 37, 71 },{ 9,4,51,54 },{ 1,3,45,33 } };
	COLLIDER_TYPE idleCollType[idleCollider] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY } };
	Module* idleCallBack[idleCollider] = { { this },{ this },{ this },{ this },{ this } };

	idle.PushBack1({ 290, 438, 72, 85 }, { 32,2 }, idleCollider, idleHitbox, idleCollType, idleCallBack, {});
	idle.PushBack1({ 363, 437, 72, 86 }, { 32,2 }, idleCollider, idleHitbox, idleCollType, idleCallBack, {});
	idle.PushBack1({ 436, 436, 72, 87 }, { 32,2 }, idleCollider, idleHitbox, idleCollType, idleCallBack, {});
	idle.PushBack1({ 363, 437, 72, 86 }, { 32,2 }, idleCollider, idleHitbox, idleCollType, idleCallBack, {});
	idle.speed = 0.1f;

	//Forward

	const int fwdcollider = 5;//Collider num for the idle animation
	SDL_Rect fwdhitbox[idleCollider] = { { 0, 3, 45, 33 },{ 8, 4, 51, 54 },{ 15, 3, 37, 71 },{ 13, 71, 31, 21 },{ 2, 37, 35, 41 } };
	COLLIDER_TYPE fwdCollType[idleCollider] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY } };
	Module* fwdCallback[idleCollider] = { { this },{ this },{ this },{ this },{ this } };
	forward.PushBack1({ 652,437, 73, 86 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 726, 434, 63, 89 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 790, 433, 60, 90 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 851, 432, 63, 91 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 915, 433, 64, 90 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 0, 531, 64, 89 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 66, 532, 72, 88 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 0, 531, 64, 89 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 915, 433, 64, 90 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 851, 432, 63, 91 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 790, 433, 60, 90 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.PushBack1({ 726, 434, 63, 89 }, { 32,2 }, fwdcollider, fwdhitbox, fwdCollType, fwdCallback, {});
	forward.speed = 0.15f;


	//Backward

	const int bwdcollider = 5;//Collider num for the idle animation
	SDL_Rect bwdhitbox[idleCollider] = { { 0, 3, 45, 33 },{ 8, 4, 51, 54 },{ 15, 3, 37, 71 },{ 13, 71, 31, 21 },{ 2, 37, 35, 41 } };
	COLLIDER_TYPE bcwCollType[idleCollider] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY } };
	Module* bwdCallback[idleCollider] = { { this },{ this },{ this },{ this },{ this } };
	backward.PushBack1({ 652,437, 73, 86 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 726, 434, 63, 89 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 790, 433, 60, 90 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 851, 432, 63, 91 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 915, 433, 64, 90 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 0, 531, 64, 89 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 66, 532, 72, 88 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 0, 531, 64, 89 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 915, 433, 64, 90 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 851, 432, 63, 91 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 790, 433, 60, 90 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.PushBack1({ 726, 434, 63, 89 }, { 32,2 }, bwdcollider, bwdhitbox, bcwCollType, bwdCallback, {});
	backward.speed = 0.2f;

	//Crouch

	const int crhcollider = 5;//Collider num for the crouch animation
	SDL_Rect crhhitbox[crhcollider] = { { 30, 48, 23, 19 },{ 17, 29, 22, 27 },{ 38, 29, 29, 24 },{ 0, 0, 40, 29 },{ 40, 0, 34, 32 } };
	COLLIDER_TYPE crchCollType[crhcollider] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY} };
	Module* crhCallback[crhcollider] = { {this},{this},{this},{this},{this} };
	crouch.PushBack1({ 934, 742 , 74, 81 }, { 32, 2 }, crhcollider, crhhitbox, crchCollType, crhCallback, {});
	crouch.PushBack1({ 0, 833, 73, 72 }, { 32, 2 }, crhcollider, crhhitbox, crchCollType, crhCallback, {});
	crouch.PushBack1({ 74, 839, 72, 66 }, { 32, 2 }, crhcollider, crhhitbox, crchCollType, crhCallback, {});
	crouch.PushBack1({ 147, 839, 72, 65 }, { 32, 2 }, crhcollider, crhhitbox, crchCollType, crhCallback, {});
	crouch.speed = 0.3f;
	crouch.loop = false;

	//Jump 


	const int jumpcollider = 5;//Collider num for the idle animation
	SDL_Rect jumphitbox[jumpcollider] = { { 5, 53, 37, 19 },{ 2, 4, 51, 54 },{ 9, 55, 37, 39 },{ 20, 86, 31, 21 },{ 8, 68, 31, 27 } };
	COLLIDER_TYPE jumpCollType[jumpcollider] = { {COLLIDER_ENEMY},{COLLIDER_NONE},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY} };
	Module* jumpCallback[jumpcollider] = { {this},{this},{this},{this},{this} };

	jump_neutral.PushBack1({ 1756, 1, 47, 110 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral.PushBack1({ 1804, 27, 50, 84 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral.PushBack1({ 1855, 36, 52, 75 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral.PushBack1({ 1908, 46, 57, 65 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral.PushBack1({ 1908, 46, 57, 65 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral.PushBack1({ 1908, 46, 57, 65 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral.PushBack1({ 1855, 36, 52, 75 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral.PushBack1({ 1804, 27, 50, 84 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral.PushBack1({ 1756, 1, 47, 110 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});

	jump_neutral.speed = 0.21f;
	jump_neutral.loop = false;



	const int jumpfcollider1 = 1;//Collider num for the idle animation
	SDL_Rect jumpfhitbox1[jumpfcollider1] = { { 32, 55, 37, 39 } };
	COLLIDER_TYPE jumpfCollType1[jumpfcollider1] = { {COLLIDER_ENEMY}, };
	Module* jumpfCallback1[jumpfcollider1] = { {this} };

	//jump backwards

	jump_backwards.PushBack1({ 1756, 1, 47, 110 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backwards.PushBack1({ 925,940,50,84 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backwards.PushBack1({ 1024,30,88,81 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_backwards.PushBack1({ 1113,63,121,48 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_backwards.PushBack1({ 1235,23,109,88 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_backwards.PushBack1({ 1345,7,52,104 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_backwards.PushBack1({ 1398,30,110,81 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_backwards.PushBack1({ 1509,45,119,66 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_backwards.PushBack1({ 1629,35,95,76 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_backwards.PushBack1({ 1756, 1, 47, 110 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backwards.speed = 0.19f;
	jump_backwards.loop = true;

	//jump forward

	jump_forward.PushBack1({ 1756, 1, 47, 110 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward.PushBack1({ 925,940,50,84 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward.PushBack1({ 1629,35,95,76 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_forward.PushBack1({ 1509,45,119,66 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_forward.PushBack1({ 1398,30,110,81 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_forward.PushBack1({ 1345,7,52,104 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_forward.PushBack1({ 1235,23,109,88 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_forward.PushBack1({ 1113,63,121,48 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_forward.PushBack1({ 1024,30,88,81 }, { 32, 25 }, jumpfcollider1, jumpfhitbox1, jumpfCollType1, jumpfCallback1, {});
	jump_forward.PushBack1({ 1756, 1, 47, 110 }, { 32, 25 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward.speed = 0.19f;
	jump_forward.loop = true;

	//Punch animation

	const int punchcollider = 5;//Collider num for the punch animation
	SDL_Rect punchhitbox[punchcollider] = { { 0, 3, 44, 33 },{ 8, 4, 51, 54 },{ 15, 3, 37, 71 },{ 25, 71, 31, 21 },{ 2, 7, 35, 41 } };
	COLLIDER_TYPE punchCollType[punchcollider] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY } };
	Module* punchCallback[punchcollider] = { { this },{ this },{ this },{ this },{ this } };


	const int punchcollider2 = 6;
	SDL_Rect punchhitbox2[punchcollider2] = { { 0, 3, 44, 33 },{ 8, 4, 51, 54 },{ 15, 3, 37, 71 },{ 25, 71, 31, 21 },{ 2, 37, 35, 41 }, {63,72,25,27} };
	COLLIDER_TYPE punchCollType2[punchcollider2] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY }, {COLLIDER_ENEMY_SHOT} };
	Module* punchCallback2[punchcollider2] = { { this },{ this },{ this },{ this },{ this }, {this} };
	punch.PushBack1({ 139, 533, 78, 87 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, {});
	punch.PushBack1({ 218, 531, 101, 89 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, {});
	punch.PushBack1({ 320, 524, 87, 96 }, { 32,2 }, punchcollider2, punchhitbox2, punchCollType2, punchCallback2, 4);
	punch.PushBack1({ 218, 531, 101, 89 }, { 32, 2 }, punchcollider, punchhitbox, punchCollType, punchCallback, {});
	punch.PushBack1({ 139, 533, 78, 87 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, {});

	punch.speed = 0.3f;
	punch.loop = false;


	// Medium punch animation

	const int punchmcollider = 5;
	SDL_Rect punchmhitbox[punchmcollider] = { { 29, 3, 75, 37 },{ 47, 35, 39, 33 },{59, 64, 31, 21 }, {62,55,81,13} };
	COLLIDER_TYPE punchmCollType[punchmcollider] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY }, {COLLIDER_ENEMY_SHOT} };
	Module* punchmCallback[punchmcollider] = { { this },{ this },{ this }, {this} };

	punch_medium.PushBack1({ 408, 536, 101, 84 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, 12);
	punch_medium.PushBack1({ 510, 539, 119, 81 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, 12);
	punch_medium.PushBack1({ 630,539, 143,81 }, { 32,2 }, punchmcollider, punchmhitbox, punchmCollType, punchmCallback, 12);
	punch_medium.PushBack1({ 630,539, 143,81 }, { 32,2 }, punchmcollider, punchmhitbox, punchmCollType, punchmCallback, 12);
	punch_medium.PushBack1({ 630,539, 143,81 }, { 32,2 }, punchmcollider, punchmhitbox, punchmCollType, punchmCallback, 12);
	punch_medium.PushBack1({ 510, 539, 119, 81 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, 12);
	punch_medium.PushBack1({ 408, 536, 101, 84 }, { 32,2 }, punchmcollider, punchmhitbox, punchmCollType, punchmCallback, 12);

	punch_medium.speed = 0.3f;
	punch_medium.loop = false;


	//Hard punch animation 	

	const int punchhcollider2 = 5;
	SDL_Rect punchhhitbox2[punchhcollider2] = { { 16,3,37,71 },{	28,3,75,37 },{46,35,39,33}, {52,38,35,45},{	60,69,85,13 } };
	COLLIDER_TYPE punchhCollType2[punchhcollider2] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY }, {COLLIDER_ENEMY}, {COLLIDER_ENEMY_SHOT} };
	Module* punchhCallback2[punchhcollider2] = { { this },{ this },{ this }, {this}, {this} };

	punch_hard.PushBack1({ 774, 536, 101, 84 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, 16);
	punch_hard.PushBack1({ 876, 541, 119, 79 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, 16);
	punch_hard.PushBack1({ 0, 643, 130, 76 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, 16);
	punch_hard.PushBack1({ 0, 643, 130, 76 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, 16);
	punch_hard.PushBack1({ 876, 541, 119, 79 }, { 32,2 }, punchcollider, punchhitbox, punchCollType, punchCallback, 16);
	punch_hard.PushBack1({ 774, 536, 101, 84 }, { 32,2 }, punchhcollider2, punchhhitbox2, punchhCollType2, punchhCallback2, 16);
	punch_hard.speed = 0.2f;
	punch_hard.loop = false;


	//kick

	const int kickcollider = 5;//Collider num for the kick animation
	SDL_Rect kickhitbox[kickcollider] = { { 0, 3, 44, 33 },{ 8, 4, 51, 54 },{ 15, 3, 37, 71 },{ 13, 71, 31, 21 },{ 2, 37, 35, 41 } };
	COLLIDER_TYPE kickCollType[kickcollider] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY } };
	Module* kickCallback[kickcollider] = { { this },{ this },{ this },{ this },{ this } };


	const int kickcollider2 = 6;
	SDL_Rect kickhitbox2[kickcollider2] = { { 0, 3, 44, 33 },{ 8, 4, 51, 54 },{ 15, 3, 37, 71 },{ 13, 71, 31, 21 },{ 2, 37, 35, 41 }, {43,55,67,11} };
	COLLIDER_TYPE kickCollType2[kickcollider2] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY }, {COLLIDER_ENEMY_SHOT} };
	Module* kickCallback2[kickcollider2] = { { this },{ this },{ this },{ this },{ this }, {this} };

	kick.PushBack1({ 131,630 , 66, 89 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick.PushBack1({ 198, 626, 71, 93 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick.PushBack1({ 270, 622, 106,97 }, { 32,2 }, kickcollider2, kickhitbox2, kickCollType2, kickCallback2, 8);
	kick.PushBack1({ 198, 626, 71, 93 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick.PushBack1({ 131,630 , 66, 89 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick.speed = 0.2f;

	//kick medium

	const int kickcollider3 = 6;
	SDL_Rect kickhitbox3[kickcollider3] = { { 0, 3, 44, 33 },{ 8, 4, 51, 54 },{ 15, 3, 37, 71 },{ 13, 71, 31, 21 },{ 2, 37, 35, 41 }, {54,70,81,19} };
	COLLIDER_TYPE kickCollType3[kickcollider3] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY }, {COLLIDER_ENEMY_SHOT} };
	Module* kickCallback3[kickcollider3] = { { this },{ this },{ this },{ this },{ this }, {this} };

	kick_medium.PushBack1({ 131,630 , 66, 89 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick_medium.PushBack1({ 198, 626, 71, 93 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick_medium.PushBack1({ 377,624,109,95 }, { 32,2 }, kickcollider3, kickhitbox3, kickCollType3, kickCallback3, 12);
	kick_medium.PushBack1({ 377,624,109,95 }, { 32,2 }, kickcollider3, kickhitbox3, kickCollType3, kickCallback3, 12);
	kick_medium.PushBack1({ 377,624,109,95 }, { 32,2 }, kickcollider3, kickhitbox3, kickCollType3, kickCallback3, 12);
	kick_medium.PushBack1({ 198, 626, 71, 93 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick_medium.PushBack1({ 131,630 , 66, 89 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick_medium.speed = 0.3f;
	kick_medium.loop = false;


	//kick hard

	const int kickcollider4 = 6;
	SDL_Rect kickhitbox4[kickcollider4] = { { 0, 3, 44, 33 },{ 8, 4, 51, 54 },{ 15, 3, 37, 71 },{ 38, 66, 77, 33 },{ 2, 37, 35, 41 }, {65,80,79,27} };
	COLLIDER_TYPE kickCollType4[kickcollider4] = { { COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY },{ COLLIDER_ENEMY }, {COLLIDER_ENEMY_SHOT} };
	Module* kickCallback4[kickcollider4] = { { this },{ this },{ this },{ this },{ this }, {this} };

	kick_hard.PushBack1({ 487,641 , 64, 79 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick_hard.PushBack1({ 552, 627, 70, 92 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick_hard.PushBack1({ 623,629,82,90 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick_hard.PushBack1({ 706,622,123,97 }, { 32,2 }, kickcollider4, kickhitbox4, kickCollType4, kickCallback4, 16);

	kick_hard.PushBack1({ 830,636,102,83 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});
	kick_hard.PushBack1({ 933, 638, 70, 81 }, { 32,2 }, kickcollider, kickhitbox, kickCollType, kickCallback, {});

	kick_hard.speed = 0.15f;
	kick_hard.loop = false;


	//crouch punch
	const int crhpnchcollider = 5;//Collider num for the crouch punch animation
	SDL_Rect crhpnchhitbox[crhpnchcollider] = { { 30, 48, 23, 19 },{ 17, 29, 22, 27 },{ 38, 29, 29, 24 },{ 0, 0, 40, 29 },{ 40, 0, 34, 32 } };
	COLLIDER_TYPE crchpnchCollType[crhpnchcollider] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY} };
	Module* crhpnchCallback[crhpnchcollider] = { {this},{this},{this},{this},{this} };

	const int crhpnchcollider2 = 6;
	SDL_Rect crhpnchhitbox2[crhpnchcollider2] = { { 30, 48, 23, 19 },{ 17, 29, 22, 27 },{ 38, 29, 29, 24 },{ 0, 0, 40, 29 },{ 40, 0, 34, 32 },{52, 38, 56, 12} };
	COLLIDER_TYPE crchpnchCollType2[crhpnchcollider2] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY}, {COLLIDER_ENEMY_SHOT} };
	Module* crhpnchCallback2[crhpnchcollider2] = { {this},{this},{this},{this},{this} };


	Crouch_punch.PushBack1({ 368, 839, 71, 66 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_punch.PushBack1({ 518, 841, 107, 64 }, { 32, 2 }, crhpnchcollider2, crhpnchhitbox2, crchpnchCollType2, crhpnchCallback2, 6);
	Crouch_punch.PushBack1({ 440, 839, 77, 66 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_punch.speed = 0.13f;
	Crouch_punch.loop = true;

	//crouch  medium punch


	const int crhpnchcollider3 = 6;
	SDL_Rect crhpnchhitbox3[crhpnchcollider3] = { { 30, 48, 23, 19 },{ 17, 29, 22, 27 },{ 38, 29, 29, 24 },{ 0, 0, 40, 29 },{ 40, 0, 34, 32 },{55, 39, 80, 19} };
	COLLIDER_TYPE crchpnchCollType3[crhpnchcollider3] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY}, {COLLIDER_ENEMY_SHOT} };
	Module* crhpnchCallback3[crhpnchcollider3] = { {this},{this},{this},{this},{this} };


	Crouch_medium_punch.PushBack1({ 751, 838, 80, 67 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_medium_punch.PushBack1({ 832, 838, 100, 67 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_medium_punch.PushBack1({ 626, 838, 124, 67 }, { 32, 2 }, crhpnchcollider3, crhpnchhitbox3, crchpnchCollType3, crhpnchCallback3, 10);
	Crouch_medium_punch.PushBack1({ 626, 838, 124, 67 }, { 32, 2 }, crhpnchcollider3, crhpnchhitbox3, crchpnchCollType3, crhpnchCallback3, 10);
	Crouch_medium_punch.PushBack1({ 626, 838, 124, 67 }, { 32, 2 }, crhpnchcollider3, crhpnchhitbox3, crchpnchCollType3, crhpnchCallback3, 10);
	Crouch_medium_punch.PushBack1({ 832, 838, 100, 67 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_medium_punch.PushBack1({ 751, 838, 80, 67 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_medium_punch.speed = 0.3f;
	Crouch_medium_punch.loop = false;

	//crouch  hard punch


	Crouch_hard_punch.PushBack1({ 751, 838, 80, 67 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_hard_punch.PushBack1({ 832, 838, 100, 67 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_hard_punch.PushBack1({ 626, 838, 124, 67 }, { 32, 2 }, crhpnchcollider3, crhpnchhitbox3, crchpnchCollType3, crhpnchCallback3, 16);
	Crouch_hard_punch.PushBack1({ 626, 838, 124, 67 }, { 32, 2 }, crhpnchcollider3, crhpnchhitbox3, crchpnchCollType3, crhpnchCallback3, 16);
	Crouch_hard_punch.PushBack1({ 626, 838, 124, 67 }, { 32, 2 }, crhpnchcollider3, crhpnchhitbox3, crchpnchCollType3, crhpnchCallback3, 16);
	Crouch_hard_punch.PushBack1({ 832, 838, 100, 67 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_hard_punch.PushBack1({ 751, 838, 80, 67 }, { 32, 2 }, crhpnchcollider, crhpnchhitbox, crchpnchCollType, crhpnchCallback, {});
	Crouch_hard_punch.speed = 0.3f;
	Crouch_hard_punch.loop = false;


	// Crouch kick

	const int crhcollider3 = 4;//Collider num for the crouch animation
	SDL_Rect crhhitbox3[crhcollider3] = { { 10, 3, 37, 51 },{ 11, 6, 43, 25 },{ 11, 31, 35, 25 },{ 21, 43, 31, 21 } };
	COLLIDER_TYPE crchCollType3[crhcollider3] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY} };
	Module* crhCallback3[crhcollider3] = { {this},{this},{this},{this} };

	const int crhcollider4 = 5;//Collider num for the crouch animation
	SDL_Rect crhhitbox4[crhcollider4] = { { 10, 3, 37, 51 },{ 11, 6, 43, 25 },{ 11, 31, 35, 25 },{ 21, 43, 31, 21 },{ 31, 3, 75, 19 } };
	COLLIDER_TYPE crchCollType4[crhcollider4] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY_SHOT} };
	Module* crhCallback4[crhcollider4] = { {this},{this},{this},{this},{this} };

	Crouch_kick.PushBack1({ 139, 966, 63, 59 }, { 32, 2 }, crhcollider3, crhhitbox3, crchCollType3, crhCallback3, {});
	Crouch_kick.PushBack1({ 203, 966, 61, 58 }, { 32, 2 }, crhcollider3, crhhitbox3, crchCollType3, crhCallback3, {});
	Crouch_kick.PushBack1({ 265, 976, 107, 48 }, { 32, 2 }, crhcollider4, crhhitbox4, crchCollType4, crhCallback4, 8);
	Crouch_kick.PushBack1({ 265, 976, 107, 48 }, { 32, 2 }, crhcollider4, crhhitbox4, crchCollType4, crhCallback4, 8);
	Crouch_kick.PushBack1({ 265, 976, 107, 48 }, { 32, 2 }, crhcollider4, crhhitbox4, crchCollType4, crhCallback4, 8);


	Crouch_kick.speed = 0.25f;
	Crouch_kick.loop = false;

	// Crouch kick medium

	const int crhcollider5 = 4;//Collider num for the crouch animation
	SDL_Rect crhhitbox5[crhcollider5] = { { 10, 3, 37, 51 },{ 24, 3, 83, 23 },{ 11, 31, 35, 25 },{ 21, 43, 31, 21 } };
	COLLIDER_TYPE crchCollType5[crhcollider5] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY} };
	Module* crhCallback5[crhcollider5] = { {this},{this},{this},{this} };

	const int crhcollider6 = 5;//Collider num for the crouch animation
	SDL_Rect crhhitbox6[crhcollider6] = { { 10, 3, 37, 51 },{ 24, 3, 83, 23 },{ 11, 31, 35, 25 },{ 21, 43, 31, 21 },{ 36, 3, 85, 19 } };
	COLLIDER_TYPE crchCollType6[crhcollider6] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY_SHOT} };
	Module* crhCallback6[crhcollider6] = { {this},{this},{this},{this},{this} };

	Crouch_medium_kick.PushBack1({ 373, 961, 77, 63 }, { 32, 2 }, crhcollider5, crhhitbox5, crchCollType5, crhCallback5, {});
	Crouch_medium_kick.PushBack1({ 451, 969, 115, 55 }, { 32, 2 }, crhcollider6, crhhitbox6, crchCollType6, crhCallback6, 10);
	Crouch_medium_kick.PushBack1({ 567, 962, 76, 62 }, { 32, 2 }, crhcollider5, crhhitbox5, crchCollType5, crhCallback5, {});


	Crouch_medium_kick.speed = 0.20f;
	Crouch_medium_kick.loop = false;

	// Crouch kick hard

	const int crhcollider1 = 4;//Collider num for the crouch animation
	SDL_Rect crhhitbox1[crhcollider1] = { { 7, 3, 37, 51 },{ 8, 31, 35, 25 },{ 10, 43, 31, 21 },{ 49, 32, 55, 31 } };
	COLLIDER_TYPE crchCollType1[crhcollider1] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY} };
	Module* crhCallback1[crhcollider1] = { {this},{this},{this},{this} };

	const int crhcollider2 = 5;//Collider num for the crouch animation
	SDL_Rect crhhitbox2[crhcollider2] = { { 7, 3, 37, 51 },{ 8, 31, 35, 25 },{ 18, 43, 31, 21 },{ 57, 32, 55, 31 },{ 46, 32, 89, 33 } };
	COLLIDER_TYPE crchCollType2[crhcollider2] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY_SHOT} };
	Module* crhCallback2[crhcollider2] = { {this},{this},{this},{this},{this} };

	Crouch_hard_kick.PushBack1({ 644, 962, 72, 62 }, { 32, 2 }, crhcollider1, crhhitbox1, crchCollType1, crhCallback1, {});
	Crouch_hard_kick.PushBack1({ 717, 960, 60, 64 }, { 32, 2 }, crhcollider1, crhhitbox1, crchCollType1, crhCallback1, {});
	Crouch_hard_kick.PushBack1({ 796, 951, 128, 73 }, { 32, 2 }, crhcollider2, crhhitbox2, crchCollType2, crhCallback2, 14);
	Crouch_hard_kick.PushBack1({ 717, 960, 60, 64 }, { 32, 2 }, crhcollider1, crhhitbox1, crchCollType1, crhCallback1, {});
	Crouch_hard_kick.PushBack1({ 644, 962, 72, 62 }, { 32, 2 }, crhcollider1, crhhitbox1, crchCollType1, crhCallback1, {});
	Crouch_hard_kick.PushBack1({ 147, 839, 72, 65 }, { 32, 2 }, crhcollider1, crhhitbox1, crchCollType1, crhCallback1, {});


	Crouch_hard_kick.speed = 0.25f;
	Crouch_hard_kick.loop = false;

	//punch neutral jump



	const int jumppunchcollider = 6;
	SDL_Rect jumppunchhitbox[jumppunchcollider] = { { 5, 53, 37, 19 },{ 2, 4, 51, 54 },{ 9, 55, 37, 39 },{ 20, 86, 31, 21 },{ 8, 68, 31, 27 }, {29,30,53,35} };
	COLLIDER_TYPE jumppunchCollType[jumppunchcollider] = { {COLLIDER_ENEMY},{COLLIDER_NONE},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY}, {COLLIDER_ENEMY_SHOT} };
	Module* jumppunchCallback[jumppunchcollider] = { {this},{this},{this},{this},{this},{this} };

	jump_neutral_punch.PushBack1({ 1966, 22, 66,89 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_punch.PushBack1({ 1024, 131,53 ,90 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_punch.PushBack1({ 1078, 146, 85, 75 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_punch.PushBack1({ 1164, 144, 87, 77 }, { 32, 2 }, jumppunchcollider, jumppunchhitbox, jumppunchCollType, jumppunchCallback, 10);
	jump_neutral_punch.speed = 0.45f;
	jump_neutral_punch.loop = false;

	//punch neutral jump medium


	jump_neutral_punch_medium.PushBack1({ 1966, 22, 66,89 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_punch_medium.PushBack1({ 1024, 131,53 ,90 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_punch_medium.PushBack1({ 1078, 146, 85, 75 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_punch_medium.PushBack1({ 1164, 144, 87, 77 }, { 32, 2 }, jumppunchcollider, jumppunchhitbox, jumppunchCollType, jumppunchCallback, 14);
	jump_neutral_punch_medium.speed = 0.45f;
	jump_neutral_punch_medium.loop = false;

	//punch neutral jump hard


	jump_neutral_punch_hard.PushBack1({ 1966, 22, 66,89 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_punch_hard.PushBack1({ 1024, 131,53 ,90 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_punch_hard.PushBack1({ 1078, 146, 85, 75 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_punch_hard.PushBack1({ 1164, 144, 87, 77 }, { 32, 2 }, jumppunchcollider, jumppunchhitbox, jumppunchCollType, jumppunchCallback, 16);
	jump_neutral_punch_hard.speed = 0.45f;
	jump_neutral_punch_hard.loop = false;

	//punch forward jump

	jump_forward_punch.PushBack1({ 1252, 147, 53, 74 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_punch.PushBack1({ 1306, 146, 59,75 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_punch.PushBack1({ 1366, 144,83, 77 }, { 32, 2 }, jumppunchcollider, jumppunchhitbox, jumppunchCollType, jumppunchCallback, 10);
	jump_forward_punch.speed = 0.2f;
	jump_forward_punch.loop = false;

	//punch forward jump medium

	jump_forward_punch_medium.PushBack1({ 1252, 147, 53, 74 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_punch_medium.PushBack1({ 1306, 146, 59,75 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_punch_medium.PushBack1({ 1366, 144,83, 77 }, { 32, 2 }, jumppunchcollider, jumppunchhitbox, jumppunchCollType, jumppunchCallback, 14);
	jump_forward_punch_medium.speed = 0.2f;
	jump_forward_punch_medium.loop = false;

	//punch forward jump hard 

	jump_forward_punch_hard.PushBack1({ 1252, 147, 53, 74 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_punch_hard.PushBack1({ 1306, 146, 59,75 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_punch_hard.PushBack1({ 1366, 144,83, 77 }, { 32, 2 }, jumppunchcollider, jumppunchhitbox, jumppunchCollType, jumppunchCallback, 16);
	jump_forward_punch_hard.speed = 0.2f;
	jump_forward_punch_hard.loop = false;

	//punch backward jump

	jump_backward_punch.PushBack1({ 1252, 147, 53, 74 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_punch.PushBack1({ 1306, 146, 59,75 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_punch.PushBack1({ 1366, 144,83, 77 }, { 32, 2 }, jumppunchcollider, jumppunchhitbox, jumppunchCollType, jumppunchCallback, 10);
	jump_backward_punch.speed = 0.2f;
	jump_backward_punch.loop = false;

	//punch backward jump medium

	jump_backward_punch_medium.PushBack1({ 1252, 147, 53, 74 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_punch_medium.PushBack1({ 1306, 146, 59,75 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_punch_medium.PushBack1({ 1366, 144,83, 77 }, { 32, 2 }, jumppunchcollider, jumppunchhitbox, jumppunchCollType, jumppunchCallback, 14);
	jump_backward_punch_medium.speed = 0.2f;
	jump_backward_punch_medium.loop = false;

	//punch backward jump hard 

	jump_backward_punch_hard.PushBack1({ 1252, 147, 53, 74 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_punch_hard.PushBack1({ 1306, 146, 59,75 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_punch_hard.PushBack1({ 1366, 144,83, 77 }, { 32, 2 }, jumppunchcollider, jumppunchhitbox, jumppunchCollType, jumppunchCallback, 16);
	jump_backward_punch_hard.speed = 0.2f;
	jump_backward_punch_hard.loop = false;

	//KICK forward jump


	const int jumpkCollider2 = 6;//Collider num for the crouch animation
	SDL_Rect jumpkhitbox2[jumpkCollider2] = { { 7, 3, 37, 51 },{ 8, 31, 35, 25 },{ 18, 43, 31, 21 },{ 57, 32, 55, 31 },{ 46, 32, 89, 33 }, {43,10,63,27} };
	COLLIDER_TYPE jumpkCollType2[jumpkCollider2] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY_SHOT} };
	Module* jumpkCallback2[jumpkCollider2] = { {this},{this},{this},{this},{this},{this} };

	jump_forward_kick.PushBack1({ 1806,158,57,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick.PushBack1({ 1864,158,72,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick.PushBack1({ 1937,165,111,56 }, { 32, 2 }, jumpkCollider2, jumpkhitbox2, jumpkCollType2, jumpkCallback2, 10);
	jump_forward_kick.PushBack1({ 1937,165,111,56 }, { 32, 2 }, jumpkCollider2, jumpkhitbox2, jumpkCollType2, jumpkCallback2, 10);
	jump_forward_kick.PushBack1({ 1864,158,72,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick.PushBack1({ 1806,158,57,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick.speed = 0.2f;
	jump_forward_kick.loop = false;

	//KICK forward jump medium

	jump_forward_kick_medium.PushBack1({ 1806,158,57,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick_medium.PushBack1({ 1864,158,72,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick_medium.PushBack1({ 1937,165,111,56 }, { 32, 2 }, jumpkCollider2, jumpkhitbox2, jumpkCollType2, jumpkCallback2, 12);
	jump_forward_kick_medium.PushBack1({ 1937,165,111,56 }, { 32, 2 }, jumpkCollider2, jumpkhitbox2, jumpkCollType2, jumpkCallback2, 12);
	jump_forward_kick_medium.PushBack1({ 1864,158,72,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick_medium.PushBack1({ 1806,158,57,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick_medium.speed = 0.2f;
	jump_forward_kick_medium.loop = false;

	//KICK forward jump hard 


	const int jumpkCollider = 6;//Collider num for the crouch animation
	SDL_Rect jumpkhitbox[jumpkCollider] = { { 7, 3, 37, 51 },{ 8, 31, 35, 25 },{ 18, 43, 31, 21 },{ 57, 32, 55, 31 },{ 46, 32, 89, 33 }, {29,45,61,41} };
	COLLIDER_TYPE jumpkCollType[jumpkCollider] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY_SHOT} };
	Module* jumpkCallback[jumpkCollider] = { {this},{this},{this},{this},{this},{this} };

	jump_forward_kick_hard.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick_hard.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick_hard.PushBack1({ 1508, 127, 84, 94 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick_hard.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 16);
	jump_forward_kick_hard.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 16);
	jump_forward_kick_hard.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 16);
	jump_forward_kick_hard.PushBack1({ 1656,128,86,93 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick_hard.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_forward_kick_hard.speed = 0.25f;
	jump_forward_kick_hard.loop = false;

	//KICK forward jump

	jump_backward_kick.PushBack1({ 1806,158,57,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick.PushBack1({ 1864,158,72,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick.PushBack1({ 1937,165,111,56 }, { 32, 2 }, jumpkCollider2, jumpkhitbox2, jumpkCollType2, jumpkCallback2, 10);
	jump_backward_kick.PushBack1({ 1937,165,111,56 }, { 32, 2 }, jumpkCollider2, jumpkhitbox2, jumpkCollType2, jumpkCallback2, 10);
	jump_backward_kick.PushBack1({ 1864,158,72,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick.PushBack1({ 1806,158,57,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick.speed = 0.2f;
	jump_backward_kick.loop = false;

	//KICK forward jump medium

	jump_backward_kick_medium.PushBack1({ 1806,158,57,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick_medium.PushBack1({ 1864,158,72,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick_medium.PushBack1({ 1937,165,111,56 }, { 32, 2 }, jumpkCollider2, jumpkhitbox2, jumpkCollType2, jumpkCallback2, 12);
	jump_backward_kick_medium.PushBack1({ 1937,165,111,56 }, { 32, 2 }, jumpkCollider2, jumpkhitbox2, jumpkCollType2, jumpkCallback2, 12);
	jump_backward_kick_medium.PushBack1({ 1864,158,72,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick_medium.PushBack1({ 1806,158,57,63 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick_medium.speed = 0.2f;
	jump_backward_kick_medium.loop = false;

	//KICK forward jump hard 

	jump_backward_kick_hard.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick_hard.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick_hard.PushBack1({ 1508, 127, 84, 94 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick_hard.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 16);
	jump_backward_kick_hard.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 16);
	jump_backward_kick_hard.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 16);
	jump_backward_kick_hard.PushBack1({ 1656,128,86,93 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick_hard.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_backward_kick_hard.speed = 0.25f;
	jump_backward_kick_hard.loop = false;

	//Lightning Kick

	const int lkcollider = 9;//Collider num for the idle animation
	SDL_Rect lkhitbox[lkcollider] = { { 14, 71, 31, 21 },{ 3, 37, 35, 41 },{ 16, 3, 37, 71 }, {9,4,51,54 },{1,3,45,33} , {91,66,31,15}, {57,19,71,39}, {90,42,51,25} , {48,4,83,29} };
	COLLIDER_TYPE lkCollType[lkcollider] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY}, {COLLIDER_ENEMY_SHOT }, {COLLIDER_ENEMY_SHOT }, {COLLIDER_ENEMY_SHOT }, {COLLIDER_ENEMY_SHOT } };
	Module* lkCallback[lkcollider] = { {this},{this},{this},{this},{this},{this},{this},{this},{this} };

	SDL_Rect lkhitbox1[lkcollider] = { { 14, 71, 31, 21 },{ 3, 37, 35, 41 },{ 16, 3, 37, 71 }, {9,4,51,54 },{1,3,45,33}, {57,19,71,39} };
	SDL_Rect lkhitbox2[lkcollider] = { { 14, 71, 31, 21 },{ 3, 37, 35, 41 },{ 16, 3, 37, 71 }, {9,4,51,54 },{1,3,45,33}, {90,42,51,25} };
	SDL_Rect lkhitbox3[lkcollider] = { { 14, 71, 31, 21 },{ 3, 37, 35, 41 },{ 16, 3, 37, 71 }, {9,4,51,54 },{1,3,45,33}, {48,4,83,29} };

	LightningKick.PushBack1({ 1537, 226, 107, 99 }, { 32, 2 }, lkcollider, lkhitbox, lkCollType, lkCallback, 15);
	LightningKick.PushBack1({ 1645,222 , 123, 103 }, { 32, 2 }, idleCollider, idleHitbox, idleCollType, idleCallBack, {});
	LightningKick.PushBack1({ 1769, 230, 119, 95 }, { 32, 2 }, lkcollider, lkhitbox, lkCollType, lkCallback, 15);
	LightningKick.PushBack1({ 1889, 230, 136,95 }, { 32, 2 }, idleCollider, idleHitbox, idleCollType, idleCallBack, {});
	LightningKick.PushBack1({ 1025, 355, 120, 93 }, { 32, 2 }, lkcollider, lkhitbox, lkCollType, lkCallback, 15);
	LightningKick.PushBack1({ 1146, 353, 152, 95 }, { 32, 2 }, idleCollider, idleHitbox, idleCollType, idleCallBack, {});
	LightningKick.PushBack1({ 1300, 355, 101, 93 }, { 32, 2 }, lkcollider, lkhitbox, lkCollType, lkCallback, 15);
	LightningKick.speed = 0.2f;
	LightningKick.loop = true;


	//Wirlhwind Kick


	const int wkcollider = 2;//Collider num for the WhirlwindKick animation
	SDL_Rect wkhitbox[wkcollider] = { {25,41,31,49},{30,55,37,39} };
	COLLIDER_TYPE wkCollType[wkcollider] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY} };
	Module* wkCallback[wkcollider] = { {this},{this} };

	const int wkcollider1 = 3;//Collider num for the WhirlwindKick animation
	SDL_Rect wkhitbox1[wkcollider1] = { {25,41,31,49},{30,55,37,39}, {1,59,151,41} };
	COLLIDER_TYPE wkCollType1[wkcollider1] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY_SHOT} };
	Module* wkCallback1[wkcollider1] = { {this},{this},{this} };

	WhirlwindKick.PushBack1({ 1402,326,55,122 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1458,333,55,115 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1514,375,101,73 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1616,376,54,71 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1671,375,101,73 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1773,379,149,69 }, { 0, 30 }, wkcollider1, wkhitbox1, wkCollType1, wkCallback1, 15);
	WhirlwindKick.PushBack1({ 1920,379,96,69 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1024,477,48,68 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1073,476,86,69 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1160,475,146,70 }, { 0, 30 }, wkcollider1, wkhitbox1, wkCollType1, wkCallback1, 15);
	WhirlwindKick.PushBack1({ 1514,375,101,73 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1616,376,54,71 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1671,375,101,73 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1773,379,149,69 }, { 0, 30 }, wkcollider1, wkhitbox1, wkCollType1, wkCallback1, 15);
	WhirlwindKick.PushBack1({ 1920,379,96,69 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1024,477,48,68 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1073,476,86,69 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1160,475,146,70 }, { 0, 30 }, wkcollider1, wkhitbox1, wkCollType1, wkCallback1, 15);
	WhirlwindKick.PushBack1({ 1458,333,55,115 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1402,326,55,122 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1235,23,109,88 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1113,63,121,48 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1024,30,88,81 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 1756, 1, 47, 110 }, { 0, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.PushBack1({ 363, 437, 72, 86 }, { 20, 30 }, wkcollider, wkhitbox, wkCollType, wkCallback, 0);
	WhirlwindKick.speed = 0.286f;
	WhirlwindKick.loop = false;


	// JUMP NEUTRAL KICK

	jump_neutral_kick.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_kick.PushBack1({ 1508, 127, 84, 94 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_kick.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 10);
	jump_neutral_kick.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 10);
	jump_neutral_kick.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 10);
	jump_neutral_kick.PushBack1({ 1656,128,86,93 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_kick.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});

	jump_neutral_kick.speed = 0.25f;
	jump_neutral_kick.loop = false;

	// JUMP NEUTRAL KICK MEIDUM


	jump_neutral_kick_medium.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_kick_medium.PushBack1({ 1508, 127, 84, 94 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_kick_medium.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 12);
	jump_neutral_kick_medium.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 12);
	jump_neutral_kick_medium.PushBack1({ 1592,122,63,99 }, { 32, 2 }, jumpkCollider, jumpkhitbox, jumpkCollType, jumpkCallback, 12);
	jump_neutral_kick_medium.PushBack1({ 1656,128,86,93 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_kick_medium.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});

	jump_neutral_kick_medium.speed = 0.25f;
	jump_neutral_kick_medium.loop = false;

	// JUMP NEUTRAL KICK HARD

	const int jumpkCollider1 = 6;//Collider num for the crouch animation
	SDL_Rect jumpkhitbox1[jumpkCollider1] = { { 7, 3, 37, 51 },{ 8, 31, 35, 25 },{ 18, 43, 31, 21 },{ 57, 32, 55, 31 },{ 46, 32, 89, 33 }, {56,53,66,35} };
	COLLIDER_TYPE jumpkCollType1[jumpkCollider1] = { {COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY},{COLLIDER_ENEMY_SHOT} };
	Module* jumpkCallback1[jumpkCollider1] = { {this},{this},{this},{this},{this},{this} };

	jump_neutral_kick_hard.PushBack1({ 1024,228,57,97 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});
	jump_neutral_kick_hard.PushBack1({ 1112,260,99,65 }, { 32, 2 }, jumpkCollider1, jumpkhitbox1, jumpkCollType1, jumpkCallback1, 16);
	jump_neutral_kick_hard.PushBack1({ 1112,260,99,65 }, { 32, 2 }, jumpkCollider1, jumpkhitbox1, jumpkCollType1, jumpkCallback1, 16);
	jump_neutral_kick_hard.PushBack1({ 1212,255,110,70 }, { 32, 2 }, jumpkCollider1, jumpkhitbox1, jumpkCollType1, jumpkCallback1, 16);
	jump_neutral_kick_hard.PushBack1({ 1212,255,110,70 }, { 32, 2 }, jumpkCollider1, jumpkhitbox1, jumpkCollType1, jumpkCallback1, 16);
	jump_neutral_kick_hard.PushBack1({ 1323,232,86,93 }, { 32, 2 }, jumpkCollider1, jumpkhitbox1, jumpkCollType1, jumpkCallback1, 16);
	jump_neutral_kick_hard.PushBack1({ 1450, 126, 57, 95 }, { 32, 2 }, jumpcollider, jumphitbox, jumpCollType, jumpCallback, {});

	jump_neutral_kick_hard.speed = 0.3f;
	jump_neutral_kick_hard.loop = false;


	//damage animation 
	const int dmgCollider = 5;//Collider num for the idle animation
	SDL_Rect dmgHitbox[dmgCollider] = { { 14, 71, 31, 21 },{ 3, 37, 35, 41 },{ 16, 3, 37, 71 }, {9,4,51,54 },{1,3,45,33} };
	COLLIDER_TYPE dmgCollType[dmgCollider] = { {COLLIDER_NONE},{COLLIDER_NONE},{COLLIDER_NONE},{COLLIDER_NONE},{COLLIDER_NONE} };
	Module* dmgCallBack[dmgCollider] = { {this},{this},{this},{this},{this} };

	damage.PushBack1({ 1307,465,72,80 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage.PushBack1({ 1385, 458, 79, 87 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage.PushBack1({ 1465, 458, 76, 87 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage.PushBack1({ 1542, 462, 72, 83 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage.speed = 0.1f;
	damage.loop = true;

	//damage animation 

	damage2.PushBack1({ 1804,453,73,92 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage2.PushBack1({ 1878, 453, 76, 92 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage2.PushBack1({ 1024, 547, 102, 84 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage2.speed = 0.4f;
	damage2.loop = false;

	//damage animation
	damage3.PushBack1({ 1825,556,95,76 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage3.PushBack1({ 1921, 572, 83, 60 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage3.PushBack1({ 1024, 681, 117, 48 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage3.PushBack1({ 1142, 691, 139, 38 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage3.PushBack1({ 1284, 672, 104, 57 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage3.PushBack1({ 1389, 658, 94, 71 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage3.PushBack1({ 1284, 672, 104, 57 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage3.PushBack1({ 1142, 691, 139, 38 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage3.speed = 0.2f;
	damage3.loop = false;

	//Damage Crouch

	damage4.PushBack1({ 1350,562,72,69 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage4.PushBack1({ 1423, 560, 73, 71 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage4.PushBack1({ 1497, 564, 76, 67 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage4.PushBack1({ 1574, 570, 92, 61 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage4.speed = 0.2f;
	damage4.loop = false;

	//damage animation

	damage5.PushBack1({ 1825,556,95,76 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage5.PushBack1({ 1921, 572, 83, 60 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage5.PushBack1({ 1024, 681, 117, 48 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage5.PushBack1({ 1142, 691, 139, 38 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage5.PushBack1({ 1284, 672, 104, 57 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage5.PushBack1({ 1389, 658, 94, 71 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage5.PushBack1({ 1284, 672, 104, 57 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage5.PushBack1({ 1142, 691, 139, 38 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	damage5.speed = 0.1f;
	damage5.loop = false;
	//Block standing 

	block_standing.PushBack1({ 1667,546,84,85 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	block_standing.speed = 0.1f;
	block_standing.loop = false;

	//Block standing 

	block_crouch.PushBack1({ 1751,564,74,67 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	block_crouch.speed = 0.1f;
	block_crouch.loop = false;

	//Win1 
	win1.PushBack1({ 1867,632,68,97 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win1.PushBack1({ 1867,632,68,97 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win1.PushBack1({ 1936,632,68,97 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win1.PushBack1({ 1024,764,68,93 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win1.speed = 0.1f;
	win1.loop = false;

	//Win2
	win2.PushBack1({ 1093,755,48,102 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win2.PushBack1({ 1142,729,74,128 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win2.PushBack1({ 1217,745,74,112 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win2.PushBack1({ 1292,755,74,101 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win2.PushBack1({ 1367,753,48,103 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win2.PushBack1({ 1416,740,58,116 }, { 32, 2 }, dmgCollider, dmgHitbox, dmgCollType, dmgCallBack, {});
	win2.speed = 0.1f;
	win2.loop = false;
}

ModuleChunLi2::~ModuleChunLi2()
{}

// Load assets
bool ModuleChunLi2::Start()
{

	bool ret = true;

	graphics = App->textures->Load("Assets/Images/ChunLi2.png"); // arcade version
	shadow = App->textures->Load("Assets/Images/shadow.png");
	position.x = 395;
	position.y = 220;

	//Effects
	LightningKick_effect = App->audio->LoadChunk("Assets/Sound/Effects/chunli_yap.wav");
	WhirlwindKick_effect = App->audio->LoadChunk("Assets/Sound/Effects/chunli_kick.wav");
	light_damage = App->audio->LoadChunk("Asstes/Sound/Effects/light_attack.wav");
	medium_damage = App->audio->LoadChunk("Assets/Sound/Effects/medium_attack.wav");
	high_damage = App->audio->LoadChunk("Assets/Sound/Effects/high_attack.wav");
	wind = App->audio->LoadChunk("Assets/Sound/Effects/wind.wav");
	win_sound = App->audio->LoadChunk("Assets/Sound/Effects/chunli-laugh.wav");
	death_sound = App->audio->LoadChunk("Assets/Sound/Effects/chunli-death.wav");
	syou= App->audio->LoadChunk("Assets/Sound/Effects/you.wav");
	swin = App->audio->LoadChunk("Assets/Sound/Effects/win.wav");

	//Start functions to reset player
	ResetPlayer();
	Death.Reset();
	DeathCount = 0;
	victorycount = 0;
	force = 0;
	victoryRound1 = false;
	victoryRound2 = false;
	
	return ret;
}

bool ModuleChunLi2::CleanUp()
{
	LOG("Unloading Player textures");

	App->textures->Unload(graphics);

	for (int i = 0; i < MAX_COLLIDERS; i++)
	{
		if (colliders[i] != nullptr) {
			colliders[i]->to_delete = true;
			colliders[i] = nullptr;
		}
	}

	App->audio->UnloadChunk(LightningKick_effect);
	App->audio->UnloadChunk(WhirlwindKick_effect);
	App->audio->UnloadChunk(light_damage);
	App->audio->UnloadChunk(medium_damage);
	App->audio->UnloadChunk(high_damage);
	App->audio->UnloadChunk(wind);
	App->audio->UnloadChunk(win_sound);
	App->audio->UnloadChunk(death_sound);
	App->audio->UnloadChunk(syou);
	App->audio->UnloadChunk(swin);
	return true;
}

update_status ModuleChunLi2::Update()
{

	if (GodMode)//deletes all the collision boxes if in god mode
	{
		for (int i = 0; i < MAX_COLLIDERS; i++)
		{
			if (colliders[i] != nullptr)
				colliders[i]->to_delete = true;
		}
	}
	for (int i = 0; i < MAX_COLLIDERS; i++)//deletes all the hitboxes at the start of the frame
	{
		if (colliders[i] != nullptr) {
			colliders[i]->to_delete = true;
			colliders[i] = nullptr;
		}
	}
	Animation* current_animation = &idle;
	p2Qeue<chunli_inputs> inputs;
	chunli_states current_state = ST_UNKNOWN;

	positionlimits();
	debugcommands();


	if (death == false) {
		while (external_input(inputs))
		{

			internal_input(inputs);

			if (force < idleForce)
			{
				state = ST_UNKNOWN;
				force++;
			}
			else
			{
				state = process_fsm(inputs);
			}


			if (state != current_state)
			{
				lifecondition(current_animation);				

							
					switch (state)
					{
					case ST_IDLE:
						current_animation = &idle;
						resetanimations();
						crouch.Reset();
						wkcounter = 0;
						whirlwindMove = false;
						move = true;
						onAir = false;
					
						break;

					case ST_WALK_FORWARD:

						current_animation = &forward;
						resetanimations();
						onAir = false;
						if(move)
						position.x += speedX;

						move = true;
						break;

					case ST_WALK_BACKWARD:

						current_animation = &backward;
						resetanimations();
						onAir = false;
						if(move)
						position.x -= speedX;

						move = true;
						break;
					case ST_JUMP_NEUTRAL:
						onAir = true;
						current_animation = &jump_neutral;

						jump_neutral_logic();
						break;

					case ST_JUMP_FORWARD:

						onAir = true;
						current_animation = &jump_forward;
							
						jump_forward_logic();

						break;

					case ST_JUMP_BACKWARD:

						onAir = true;
						current_animation = &jump_backwards;
						jump_backward_logic();
						break;
					case ST_CROUCH:
						resetanimations();
						current_animation = &crouch;


						break;
					case ST_PUNCH_STANDING:

						current_animation = &punch;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
					}
											   						 					  
						break;
					case ST_KICK_STANDING:

						current_animation = &kick;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						break;

					case ST_PUNCH_MEDIUM:
						current_animation = &punch_medium;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						break;

					case ST_PUNCH_HARD:

						current_animation = &punch_hard;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						break;

					case ST_KICK_MEDIUM_STANDING:

						current_animation = &kick_medium;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						break;

					case ST_KICK_HARD_STANDING:

						current_animation = &kick_hard;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						break;


					case ST_PUNCH_CROUCH:

						current_animation = &Crouch_punch;
						crouchAttack = true;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						break;

					case ST_PUNCH_MEDIUM_CROUCH:

						current_animation = &Crouch_medium_punch;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						crouchAttack = true;

						break;

					case ST_PUNCH_HARD_CROUCH:

						current_animation = &Crouch_hard_punch;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						crouchAttack = true;


						break;

					case ST_KICK_CROUCH:

						current_animation = &Crouch_kick;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						crouchAttack = true;

						break;
					case ST_KICK_MEDIUM_CROUCH:

						current_animation = &Crouch_medium_kick;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						crouchAttack = true;


						break;
					case ST_KICK_HARD_CROUCH:

						current_animation = &Crouch_hard_kick;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						break;
					case ST_PUNCH_NEUTRAL_JUMP:

						current_animation = &jump_neutral_punch;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						onAir = true;
						jump_neutral_logic();



						break;

					case ST_PUNCH_MEDIUM_NEUTRAL_JUMP:

						current_animation = &jump_neutral_punch_medium;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						onAir = true;
						jump_neutral_logic();


						break;

					case ST_PUNCH_HARD_NEUTRAL_JUMP:

						current_animation = &jump_neutral_punch_hard;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						onAir = true;
						jump_neutral_logic();


						break;
					case ST_PUNCH_FORWARD_JUMP:

						onAir = true;
						current_animation = &jump_forward_punch;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						jump_forward_logic();

						break;

					case ST_PUNCH_MEDIUM_FORWARD_JUMP:

						onAir = true;
						current_animation = &jump_forward_punch_medium;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						jump_forward_logic();

						break;

					case ST_PUNCH_HARD_FORWARD_JUMP:

						onAir = true;
						current_animation = &jump_forward_punch_hard;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						jump_forward_logic();

						break;

					case ST_KICK_FORWARD_JUMP:

						onAir = true;
						current_animation = &jump_forward_kick;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						jump_forward_logic();

						break;

					case ST_KICK_MEDIUM_FORWARD_JUMP:

						onAir = true;
						current_animation = &jump_forward_kick_medium;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						jump_forward_logic();

						break;

					case ST_KICK_HARD_FORWARD_JUMP:

						onAir = true;
						current_animation = &jump_forward_kick_hard;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						jump_forward_logic();

						break;
					case ST_PUNCH_BACKWARD_JUMP:
						current_animation = &jump_backward_punch;

						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						onAir = true;

					


						jump_backward_logic();
						break;

					case ST_PUNCH_MEDIUM_BACKWARD_JUMP:
						current_animation = &jump_backward_punch_medium;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						onAir = true;

					


						jump_backward_logic();

						break;

					case ST_PUNCH_HARD_BACKWARD_JUMP:
						current_animation = &jump_backward_punch_hard;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						onAir = true;

					


						jump_backward_logic();

						break;
					case ST_KICK_BACKWARD_JUMP:
						current_animation = &jump_backward_kick;

						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						onAir = true;

					


						jump_backward_logic();
						break;

					case ST_KICK_MEDIUM_BACKWARD_JUMP:
						current_animation = &jump_backward_kick_medium;

						if(hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						onAir = true;

					


						jump_backward_logic();

						break;

					case ST_KICK_HARD_BACKWARD_JUMP:
						current_animation = &jump_backward_kick_hard;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						onAir = true;

					


						jump_backward_logic();

						break;

					case ST_LIGHTNINGKICK:
						current_animation = &LightningKick;
						App->audio->PlayChunk(LightningKick_effect, 3);
						break;
					case ST_WHIRLWIND:
						current_animation = &WhirlwindKick;
						App->audio->PlayChunk(WhirlwindKick_effect, 1);
						if (wkcounter < 15) {
							wkcounter++;
						}
						if (wkcounter >= 15 && wkcounter < 80) {
							wkcounter++;
							whirlwindMove = true;
						}
						if (whirlwindMove) {
							if (abs(App->chunli->position.x - position.x) >= 120) {
								if (position.x < App->chunli->position.x) { position.x += 3; }
								if (position.x > App->chunli->position.x) { position.x -= 3; }
							}

							position.y = 190;
						}
						if (wkcounter >= 60) {
							whirlwindMove = false;
							position.y = 220;
						}
						
						break;

					case ST_KICK_NEUTRAL_JUMP:

						current_animation = &jump_neutral_kick;

						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}
						onAir = true;

						jump_neutral_logic();
						break;

					case ST_KICK_MEDIUM_NEUTRAL_JUMP:

						current_animation = &jump_neutral_kick_medium;
						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						}

						jump_neutral_logic();
						onAir = true;

						break;

					case ST_KICK_HARD_NEUTRAL_JUMP:

						current_animation = &jump_neutral_kick_hard;

						if (hit_started == 0) {
							App->audio->PlayChunk(wind, 1);
							hit_started++;
						};
						onAir = true;

				


						jump_neutral_logic();


						break;

					case ST_DAMAGE:
						current_animation = &damage;

						if (current_animation->current_frame != 0)
						{
							if (position.x > App->chunli->position.x)
								position.x += 1;
							else
								position.x -= 1;
						}
						move = false;

						break;

					case ST_DAMAGE_HARD:
						current_animation = &damage2;

						if (current_animation->current_frame != 0)
						{
							if (position.x > App->chunli->position.x)
								position.x += 3;
							else
								position.x -= 3;
						}
						move = false;

						break;

					case ST_DAMAGE_FALL:
						current_animation = &damage3;
						damage_received = 0;

						if(position.x>App->chunli->position.x)
							position.x += 3;
						
						else
							position.x -= 3;

						if (SDL_GetTicks() - dmg_fall_timer <= JUMP_TIME / 4) {
							position.y -= 10;

						}

						if (SDL_GetTicks() - dmg_fall_timer >= JUMP_TIME / 4 && SDL_GetTicks() - dmg_fall_timer <= JUMP_TIME / 2) {
							position.y += 12;
						}
						if (position.y >= 220) {
							position.y = 220;
						}

						move = false;

						break;

					case ST_DAMAGE_CROUCH:
						current_animation = &damage4;
						damage_received = 0;
						break;

					case ST_DAMAGE_AIR:

						current_animation = &damage5;

						if (position.x < App->chunli->position.x)
							position.x -= 2;
						else
							position.x += 2;

						if (SDL_GetTicks() - jump_timer > JUMP_TIME / 2) {
							position.y += 4;
						}
						if (SDL_GetTicks() - jump_timer >= JUMP_TIME / 1.28) {
							position.y += 5;
						}
						if (position.y >= 220) {
							position.y = 220;
						}
						move = false;
						break;
					case ST_BLOCK:
						block_damage = 0;
						current_animation = &block_standing;
						break;
					case ST_BLOCK_CROUCH:
						block_damage = 0;
						current_animation = &block_crouch;
						break;				
					case ST_VICTORY:
						if(App->chunli->state==ST_LOSE2)
						App->UI->Resultinfo = 2;
						if(victorycount==0)
							victorycount++;		

						if (sound < 30) {
							if (sound == 1)
								App->audio->PlayChunk(syou, 1);
							sound++;
						}
						else if (sound == 30) {
							App->audio->PlayChunk(swin, 1);
							sound++;
						}
							current_animation = &win1;
						break;
					case ST_VICTORY2_:
						if (App->chunli->state == ST_LOSE2) {

							App->UI->Resultinfo = 2;
							current_animation = &win2;
						}

						if (WinSoundPlayed == false) {
							App->audio->PlayChunk(win_sound, 1);								

							WinSoundPlayed = true;
						}

						if (sound < 30) {
							if (sound == 1)
								App->audio->PlayChunk(syou, 1);
							sound++;
						}
						else if (sound == 30) {
							App->audio->PlayChunk(swin, 1);
							sound++;
						}

						if (win2.current_frame < 2) {
							position.y -= 2;
						}
						else if (win2.current_frame > 2 && position.y <= 220) {
							position.y += 2;
						}
						break;	
					case ST_LOSE:

						ignore = 1;

						if (SDL_GetTicks() - lose_timer > 2000 && App->chunli->victorycount == 0)
							App->chunli->win = 1;
						else if (SDL_GetTicks() - lose_timer > 2000 && App->chunli->victorycount == 1)
							App->chunli->win = 2;

						current_animation = &damage3;

						if (DeathSoundPlayed == false)
						{
							App->audio->PlayChunk(death_sound, 1);
							DeathSoundPlayed = true;
						}


						if (SDL_GetTicks() - lose_timer > 9000 && App->chunli->state == ST_VICTORY2) {
							App->fade->FadeToBlack(App->combo, App->combo, 2.0f);
							
						}
							

						else if (SDL_GetTicks() - lose_timer > 9000 && App->chunli->state == ST_VICTORY2_2) {
							App->audio->StopMusic(250);

							App->fade->FadeToBlack(App->scene_dhalsim, App->congrats_screen, 2.0f);
						}

						if (position.x < App->chunli->position.x)
							position.x -= 3;
						else
							position.x += 3;

						if (onAir && position.y <= 225) {
							position.y += 5;
						}

						else if (SDL_GetTicks() - lose_timer < 450) {
							position.y -= 6;
						}
						else if ( position.y<=225) {
							position.y += 7;
						}
						

						break;
					}				
										
				
				current_state = state;

				colliders_and_blit(current_animation);

				return UPDATE_CONTINUE;
			}
		}
	}
}

void ModuleChunLi2::positionlimits() {

	if (position.y == 220) {
		speedX = 1;
		speedY = 1;
	}

	if (position.x -20<= App->scene_dhalsim->background.x - 12) {
		position.x = App->scene_dhalsim->background.x - 12+20;
		leftLimit = true;
	}
	else{
		leftLimit = false;
	}

	if (position.x -40>= (App->scene_dhalsim->background.x + App->scene_dhalsim->background.w) -90 ) {
		position.x = (App->scene_dhalsim->background.x + App->scene_dhalsim->background.w)-90 +40;
		RightLimit = true;
		
	}

	else {
		RightLimit = false;
		
	}
	
	if (abs(App->chunli->position.x - position.x) >= SCREEN_WIDTH - 10 && position.x>App->chunli->position.x) {
		App->chunli->position.x = position.x - SCREEN_WIDTH + 10;
		position.x = App->chunli->position.x + SCREEN_WIDTH - 10;		
	}

	if (abs(App->chunli->position.x - position.x) >= SCREEN_WIDTH - 130 && position.x < App->chunli->position.x) {
		
		App->chunli->position.x = position.x + SCREEN_WIDTH - 130;
		position.x = App->chunli->position.x - SCREEN_WIDTH + 130;
	}
}

void ModuleChunLi2::colliders_and_blit(Animation* current_animation) {

	PivotX = current_animation->pivot[(int)current_animation->current_frame].x;
	PivotY = current_animation->pivot[(int)current_animation->current_frame].y;
	dmg = current_animation->damage[(int)current_animation->current_frame];


	for (int i = 0; i < MAX_COLLIDERS; i++)//deletes all the hitboxes at the start of the frame
	{
		if (colliders[i] != nullptr)
			colliders[i]->to_delete = true;
	}


	SDL_Rect r;
	int max_hitboxes = current_animation->maxcolliders[(int)current_animation->current_frame];

	for (int i = 0; i < max_hitboxes; i++)
	{
		r = current_animation->hitbox[i];

		if (!GodMode) {
			if (position.x > App->chunli->position.x)
				colliders[i] = App->collision->AddCollider({ position.x - (r.w - PivotX) - r.x , position.y - r.h + PivotY - r.y,r.w,r.h }, current_animation->type[i], current_animation->callback[i]);

			if (position.x < App->chunli->position.x)
				colliders[i] = App->collision->AddCollider({ position.x - PivotX + r.x , position.y + PivotY - r.h - r.y,r.w,r.h }, current_animation->type[i], current_animation->callback[i]);
		}
		

	}
	r = current_animation->GetCurrentFrame();

	

	SDL_Rect shadowrect = { 6,8,71,15 };
	if (position.x < App->chunli->position.x + App->chunli->PivotX && !RightLimit || (leftLimit && position.y==220)) {
		
		App->render->Blit(graphics, position.x -PivotX, position.y - r.h, &r);
	}
	if (position.x > App->chunli->position.x + App->chunli->PivotX && (!leftLimit || position.y !=220) || RightLimit) {
	
		App->render->BlitSym(graphics, position.x-(r.w-PivotX), position.y  - r.h, &r);
	}
}

void ModuleChunLi2::OnCollision(Collider* c1, Collider* c2) {

	if (c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_PLAYER || c2->type == COLLIDER_NONE))
	{

		if (state == ST_IDLE) {
			if (position.x > App->chunli->position.x)
				position.x += 1;
			if (position.x < App->chunli->position.x)
				position.x -= 1;
		}

		
		else if (App->chunli->leftLimit && leftLimit) {
			position.x += 2;
		}
		
		else if (App->chunli->leftLimit == true && state == ST_WALK_BACKWARD ) {
			position.x += 2;
		}
		else {
			move = false;
		}
	
	}



	if (c1->type == COLLIDER_ENEMY && c2->type == COLLIDER_PLAYER_ATTACK)
	{

		if (state == ST_WALK_FORWARD && position.x>App->chunli->position.x && !App->chunli->crouchAttack) {
			block_damage = 1;
			App->particle->AddParticle(App->particle->hit, position.x - PivotX, position.y - 70, COLLIDER_NONE, 0);
		}
		else if (state == ST_WALK_BACKWARD && position.x < App->chunli->position.x && !App->chunli->crouchAttack) {
			block_damage = 1;
			App->particle->AddParticle(App->particle->hit, position.x - PivotX + 30, position.y - 70, COLLIDER_NONE, 0);
		}
		
		else if (state == ST_CROUCH && (right || right1 || right2) && position.x > App->chunli->position.x + App->chunli->PivotX) {
			block_damage = 2;
			App->particle->AddParticle(App->particle->hit, position.x - PivotX , position.y - 70, COLLIDER_NONE, 0);
		}

		else if (state == ST_CROUCH && (left || left1 || left2) && position.x < App->chunli->position.x + App->chunli->PivotX) {
			block_damage = 2;
			App->particle->AddParticle(App->particle->hit, position.x - PivotX+30, position.y - 70, COLLIDER_NONE, 0);
		}

		else {			
			int aux = life;
			if (!damage_received) {
				life = aux - App->chunli->dmg;
			}

				
				if (state == ST_WALK_BACKWARD || state == ST_WALK_FORWARD || state == ST_IDLE) {
					if (App->chunli->state == ST_KICK_HARD_CROUCH2 || App->chunli->state == ST_KICK_HARD_NEUTRAL_JUMP2) {
						damage_received = 3;
						App->slow->StartSlowdown(JUMP_TIME, 50);
						
					}
					else if (App->chunli->state == ST_WHIRLWIND2) {
						damage_received = 2;
						App->slow->StartSlowdown(200, 50);
						
						//App->chunli->move = false;
					}
					else if (App->chunli->state == ST_KICK_HARD_STANDING2) {
						damage_received = 2;
						App->slow->StartSlowdown(400, 50);
						
					}
					else {
						damage_received = 1;
						
					}
				}
				else if (state == ST_CROUCH) {
					damage_received = 4;
					
				}
				else {
					damage_received = 5;
				
				
			}
			
			
		}

		if(block_damage ==0)
			App->particle->AddParticle(App->particle->hit, position.x + PivotX-50, position.y - 70, COLLIDER_NONE, 0);
		App->audio->PlayChunk(medium_damage, 1);
	}
}

bool ModuleChunLi2::external_input(p2Qeue<chunli_inputs>& inputs)
{
	if (App->chunli->life > 0 && App->UI->round==false) {

		//Key up
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_UP) {
			inputs.Push(IN_CROUCH_UP);
		}
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_UP) {
			return false;
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_UP) {
			left = false;
			inputs.Push(IN_LEFT_UP);
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_UP) {
			right = false;
			inputs.Push(IN_RIGHT_UP);
		}
		if (App->input->keyboard[SDL_SCANCODE_J] == KEY_UP) {
			return false;
		}
		if (App->input->keyboard[SDL_SCANCODE_K] == KEY_UP) {
			return false;
		}
		if (App->input->keyboard[SDL_SCANCODE_L] == KEY_UP) {
			return false;
		}
		if (App->input->keyboard[SDL_SCANCODE_7] == KEY_UP) {
			return false;
		}
		if (App->input->keyboard[SDL_SCANCODE_8] == KEY_UP) {
			return false;
		}
		if (App->input->keyboard[SDL_SCANCODE_9] == KEY_UP) {
			return false;
		}
		if (App->input->keyboard[SDL_SCANCODE_0] == KEY_UP) {
			return false;
		}
		if (App->input->keyboard[SDL_SCANCODE_5] == KEY_UP) {
			return false;
		}


		//Key down

		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_UP] == KEY_REPEAT) {
			inputs.Push(IN_JUMP);
		}
		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_REPEAT) {
			inputs.Push(IN_CROUCH_DOWN);
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_REPEAT) {
			left = true;
			inputs.Push(IN_LEFT_DOWN);
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_REPEAT) {
			right = true;
			inputs.Push(IN_RIGHT_DOWN);
		}
		if (App->input->keyboard[SDL_SCANCODE_J] == KEY_DOWN) {
			inputs.Push(IN_X);
		}
		if (App->input->keyboard[SDL_SCANCODE_K] == KEY_DOWN) {
			inputs.Push(IN_C);
		}
		if (App->input->keyboard[SDL_SCANCODE_L] == KEY_DOWN) {
			inputs.Push(IN_LIGHTINGKICK);
		}
		if (App->input->keyboard[SDL_SCANCODE_7] == KEY_DOWN) {
			inputs.Push(IN_1);
		}
		if (App->input->keyboard[SDL_SCANCODE_8] == KEY_DOWN) {
			inputs.Push(IN_2);
		}
		if (App->input->keyboard[SDL_SCANCODE_9] == KEY_DOWN) {
			inputs.Push(IN_3);
		}
		if (App->input->keyboard[SDL_SCANCODE_0] == KEY_DOWN) {
			inputs.Push(IN_4);
		}
		if (App->input->keyboard[SDL_SCANCODE_6] == KEY_DOWN) {
			inputs.Push(IN_WHIRLWINDKICK);
		}

		//Controller

		if (App->input->Gamepad2 == true) {

			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_A] == KEY_UP) {
				return false;
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_B] == KEY_UP) {
				return false;
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_RIGHTSHOULDER] == KEY_UP) {
				return false;
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_UP) {
				return false;
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_UP) {
				inputs.Push(IN_CROUCH_UP);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_UP) {
				left1 = false;
				inputs.Push(IN_LEFT_UP);;
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_UP) {
				right1 = false;
				inputs.Push(IN_RIGHT_UP);
			}


			if (App->combo->CheckPunchP2() == true) {
				inputs.Push(IN_X);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_B] == KEY_DOWN) {
				inputs.Push(IN_C);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_X] == KEY_DOWN) {
				inputs.Push(IN_1);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_LEFTSHOULDER] == KEY_DOWN) {
				inputs.Push(IN_2);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_Y] == KEY_DOWN) {
				inputs.Push(IN_3);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_RIGHTSHOULDER] == KEY_DOWN) {
				inputs.Push(IN_4);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_DOWN || App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_REPEAT) {
				inputs.Push(IN_JUMP);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_DOWN || App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_REPEAT) {
				inputs.Push(IN_CROUCH_DOWN);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_DOWN || App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_REPEAT) {
				left1 = true;
				inputs.Push(IN_LEFT_DOWN);
			}
			if (App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_DOWN || App->input->Pad2.button_state[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_REPEAT) {
				right1 = true;
				inputs.Push(IN_RIGHT_DOWN);
			}

			if (App->combo->CheckLightingKickP2() == true) {
				inputs.Push(IN_LIGHTINGKICK);
			}
			if (App->combo->CheckWhirlwindKickP2() == true) {
				inputs.Push(IN_WHIRLWINDKICK);
			}

			//Axis
			if (App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTY] < JOYSTICK_DEAD_ZONE_NEGATIVE) {
				inputs.Push(IN_JUMP);
			}
			if (App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTY] > JOYSTICK_DEAD_ZONE) {
				inputs.Push(IN_CROUCH_DOWN);
			}
			if (App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTX] < JOYSTICK_DEAD_ZONE_NEGATIVE) {
				left2 = true;
				inputs.Push(IN_LEFT_DOWN);
			}
			if (App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTX] > JOYSTICK_DEAD_ZONE) {
				right2 = true;
				inputs.Push(IN_RIGHT_DOWN);
			}


			if (App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTY] > JOYSTICK_DEAD_ZONE_NEGATIVE && App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTY] < JOYSTICK_DEAD_ZONE) {

			}
			if (App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTY] < JOYSTICK_DEAD_ZONE && App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTY] > JOYSTICK_DEAD_ZONE_NEGATIVE) {
				inputs.Push(IN_CROUCH_UP);
			}
			if (App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTX] > JOYSTICK_DEAD_ZONE_NEGATIVE && App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTX] < JOYSTICK_DEAD_ZONE) {
				left2 = false;
				inputs.Push(IN_LEFT_UP);
			}
			if (App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTX] < JOYSTICK_DEAD_ZONE && App->input->Pad2.axis_state[SDL_CONTROLLER_AXIS_LEFTX] > JOYSTICK_DEAD_ZONE_NEGATIVE) {
				right2 = false;
				inputs.Push(IN_RIGHT_UP);
			}


		}
	}

	if (damage_received == 1) {
		inputs.Push(IN_DAMAGE);
	}
	if (damage_received == 2) {
		inputs.Push(IN_DAMAGE_HARD);
	}
	if (damage_received == 3) {
		inputs.Push(IN_DAMAGE_FALL);
	}
	if (damage_received == 4) {
		inputs.Push(IN_DAMAGE_CROUCH);
	}
	if (damage_received == 5) {
		inputs.Push(IN_DAMAGE_AIR);
	}

	if (block_damage == 1) {
		inputs.Push(IN_BLOCK);
	}
	if (block_damage == 2) {
		inputs.Push(IN_BLOCK_CROUCH);
	}

	if (win==1 && App->chunli->state==ST_LOSE2) {
		inputs.Push(IN_VICTORY);
		win = 0;
	}

	if (win == 2 && App->chunli->state == ST_LOSE2) {
		inputs.Push(IN_VICTORY2_);
		win = 0;
	}

	if (lose && state != ST_LOSE ) {
		inputs.Push(IN_LOSE);
		App->slow->StartSlowdown(2000, 50);
		lose = false;
	}


	//OMAY GOT, THERE IS NO LOGC HOW CAN THIS BE THIS POSSIBLE, WHAT A MASTER SKILL OF PROGRAMATION
	return true;
}

void ModuleChunLi2::internal_input(p2Qeue<chunli_inputs>& inputs)
{
	if (jump_timer > 0)
	{
		if (SDL_GetTicks() - jump_timer > JUMP_TIME)
		{
			inputs.Push(IN_JUMP_FINISH);
			jump_timer = 0;
			position.y = 220;
		}
	}

	if (punch_timer > 0)
	{
		if (SDL_GetTicks() - punch_timer > PUNCH_TIME)
		{
			inputs.Push(IN_PUNCH_FINISH);
			punch_timer = 0;
		}
	}

	if (kick_timer > 0)
	{
		if (SDL_GetTicks() - kick_timer > KICK_TIME)
		{
			inputs.Push(IN_KICK_FINISH);
			kick_timer = 0;
		}
	}

	if (hadouken_timer > 0)
	{
		if (SDL_GetTicks() - hadouken_timer > HADOUKEN_TIME)
		{
			inputs.Push(IN_LIGHTNINGKICK_FINISH);
			hadouken_timer = 0;
		}
	}
	if (punch_neutral_jump_timer > 0)
	{
		if (SDL_GetTicks() - punch_neutral_jump_timer > PUNCH_NEUTRAL_JUMP_TIME)
		{
			inputs.Push(IN_PUNCH_FINISH);
			punch_neutral_jump_timer = 0;
		}
	}
	if (punch_medium_timer > 0)
	{
		if (SDL_GetTicks() - punch_medium_timer > PUNCH_MEDIUM_TIME)
		{
			inputs.Push(IN_PUNCH_MEDIUM_FINISH);
			punch_medium_timer = 0;
		}
	}

	if (punch_hard_timer > 0)
	{
		if (SDL_GetTicks() - punch_hard_timer > PUNCH_HARD_TIME)
		{
			inputs.Push(IN_PUNCH_HARD_FINISH);
			punch_hard_timer = 0;
		}
	}

	if (kick_medium_timer > 0)
	{
		if (SDL_GetTicks() - kick_medium_timer > KICK_MEDIUM_TIME)
		{
			inputs.Push(IN_KICK_MEDIUM_FINISH);
			kick_medium_timer = 0;
		}
	}

	if (kick_hard_timer > 0)
	{
		if (SDL_GetTicks() - kick_hard_timer > JUMP_TIME)
		{
			inputs.Push(IN_KICK_HARD_FINISH);
			kick_hard_timer = 0;
		}
	}
	if (dmg_timer > 0)
	{
		if (SDL_GetTicks() - dmg_timer > DMG_TIME)
		{
			inputs.Push(IN_DAMAGE_FINISH);
			dmg_timer = 0;
		}
	}

	if (dmg_hard_timer > 0)
	{
		if (SDL_GetTicks() - dmg_hard_timer > DMG_TIME)
		{
			inputs.Push(IN_DAMAGE_FINISH);
			dmg_hard_timer = 0;
		}
	}

	if (dmg_fall_timer > 0)
	{
		if (SDL_GetTicks() - dmg_fall_timer > JUMP_TIME)
		{
			inputs.Push(IN_DAMAGE_FINISH);
			dmg_fall_timer = 0;
		}
	}

	if (block_timer > 0)
	{
		if (SDL_GetTicks() - block_timer > PUNCH_TIME)
		{
			inputs.Push(IN_BLOCK_FINISH);
			block_timer = 0;
		}
	}

	if (whirlwind_timer > 0)
	{
		if (SDL_GetTicks() - whirlwind_timer > WHIRLWINDKICK_TIME2)
		{
			inputs.Push(IN_WHIRLWINDKICK_FINISH);
			whirlwind_timer = 0;
		}
	}

	if (victory_timer > 0)
	{
		victoryRound1 = true;
		if (SDL_GetTicks() - victory_timer > 8000)
		{
			inputs.Push(IN_VICTORY_FINISH);
			victory_timer = 0;
			victoryRound1 = false;
		}
	}
	if (victory2_timer > 0)
	{
		victoryRound2 = true;
		if (SDL_GetTicks() - victory2_timer > 8000)
		{
			inputs.Push(IN_VICTORY2_FINISH);
			victory2_timer = 0;
			victoryRound2 = false;
		}
	}
	if (lose_timer > 0)
	{
		if (SDL_GetTicks() - lose_timer > 10000)
		{
			inputs.Push(IN_LOSE_FINISH);
			lose_timer = 0;
		}
	}

}

void ModuleChunLi2::ResetPlayer() {

	life = 1000;
	position.x = 410; 
	position.y = 220;
	state = ST_IDLE;
	App->UI->Resultinfo == 0;
	if (App->chunli->position.x != 180 || App->chunli->life != 1000) {
		ActiveDeath = 0;
		App->chunli->ResetPlayer();
		App->UI->time = 99;
		App->UI->Counter1 = 9;
		App->UI->Counter2 = 9;
		App->UI->Resultinfo = 0;
	}
	
}

chunli_states ModuleChunLi2::process_fsm(p2Qeue<chunli_inputs>& inputs)
{
	static chunli_states state = ST_IDLE;
	chunli_inputs last_input;

	while (inputs.Pop(last_input))
	{
		
			switch (state)
			{

			case ST_IDLE2:
			{
				if (hit_conected > 0) {
					hit_conected = 0;
				}
				if (hit_started > 0) {
					hit_started = 0;
				}
				switch (last_input)
				{

				case IN_RIGHT_DOWN: state = ST_WALK_FORWARD; break;
				case IN_LEFT_DOWN: state = ST_WALK_BACKWARD; break;
				case IN_JUMP: state = ST_JUMP_NEUTRAL; jump_timer = SDL_GetTicks();  break;
				case IN_CROUCH_DOWN: state = ST_CROUCH; break;
				case IN_X: state = ST_PUNCH_STANDING; punch_timer = SDL_GetTicks();  break;
				case IN_C: state = ST_KICK_STANDING; kick_timer = SDL_GetTicks(); break;
				case IN_LIGHTINGKICK: state = ST_LIGHTNINGKICK; hadouken_timer = SDL_GetTicks(); break;
				case IN_1: state = ST_PUNCH_MEDIUM; punch_medium_timer = SDL_GetTicks(); break;
				case IN_2: state = ST_PUNCH_HARD; punch_hard_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_KICK_MEDIUM_STANDING; kick_medium_timer = SDL_GetTicks(); break;
				case IN_4: state = ST_KICK_HARD_STANDING; kick_hard_timer = SDL_GetTicks(); break;
				case IN_DAMAGE: state = ST_DAMAGE; dmg_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_HARD: state = ST_DAMAGE_HARD; dmg_hard_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_FALL: state = ST_DAMAGE_FALL; dmg_fall_timer = SDL_GetTicks(); break;
				case IN_WHIRLWINDKICK: state = ST_WHIRLWIND; whirlwind_timer = SDL_GetTicks(); break;
				case IN_VICTORY: state = ST_VICTORY; victory_timer = SDL_GetTicks(); break;
				case IN_VICTORY2_: state = ST_VICTORY2_; victory2_timer = SDL_GetTicks(); break;
				case IN_LOSE: state = ST_LOSE; lose_timer = SDL_GetTicks();  break;
				}
			}
			break;

			case ST_WALK_FORWARD:
			{
				if (hit_conected > 0) {
					hit_conected = 0;
				}
				if (hit_started > 0) {
					hit_started = 0;
				}
				switch (last_input)
				{
				case IN_RIGHT_UP: state = ST_IDLE; break;
				case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
				case IN_JUMP: state = ST_JUMP_FORWARD; jump_timer = SDL_GetTicks();  break;
				case IN_CROUCH_DOWN: state = ST_CROUCH; break;
				case IN_X: state = ST_PUNCH_STANDING; punch_timer = SDL_GetTicks();  break;
				case IN_C: state = ST_KICK_STANDING; kick_timer = SDL_GetTicks(); break;
				case IN_LIGHTINGKICK: state = ST_LIGHTNINGKICK; hadouken_timer = SDL_GetTicks(); break;
				case IN_1: state = ST_PUNCH_MEDIUM; punch_medium_timer = SDL_GetTicks(); break;
				case IN_2: state = ST_PUNCH_HARD; punch_hard_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_KICK_MEDIUM_STANDING; kick_medium_timer = SDL_GetTicks(); break;
				case IN_4: state = ST_KICK_HARD_STANDING; kick_hard_timer = SDL_GetTicks(); break;
				case IN_DAMAGE: state = ST_DAMAGE; dmg_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_HARD: state = ST_DAMAGE_HARD; dmg_hard_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_FALL: state = ST_DAMAGE_FALL; dmg_fall_timer = SDL_GetTicks(); break;
				case IN_BLOCK: state = ST_BLOCK; block_timer = SDL_GetTicks(); break;
				case IN_WHIRLWINDKICK: state = ST_WHIRLWIND; whirlwind_timer = SDL_GetTicks(); break;
				case IN_VICTORY: state = ST_VICTORY; victory_timer = SDL_GetTicks(); break;
				case IN_VICTORY2_: state = ST_VICTORY2_; victory2_timer = SDL_GetTicks(); break;
				case IN_LOSE: state = ST_LOSE; lose_timer = SDL_GetTicks();  break;
				}
			}
			break;

			case ST_WALK_BACKWARD:
			{
				if (hit_started > 0) {
					hit_started = 0;
				}
				if (hit_conected > 0) {
					hit_conected = 0;
				}
				switch (last_input)
				{
				case IN_LEFT_UP: state = ST_IDLE; break;
				case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
				case IN_JUMP: state = ST_JUMP_BACKWARD; jump_timer = SDL_GetTicks();  break;
				case IN_CROUCH_DOWN: state = ST_CROUCH; break;
				case IN_X: state = ST_PUNCH_STANDING; punch_timer = SDL_GetTicks();  break;
				case IN_C: state = ST_KICK_STANDING; kick_timer = SDL_GetTicks(); break;
				case IN_LIGHTINGKICK: state = ST_LIGHTNINGKICK; hadouken_timer = SDL_GetTicks(); break;
				case IN_1: state = ST_PUNCH_MEDIUM; punch_medium_timer = SDL_GetTicks(); break;
				case IN_2: state = ST_PUNCH_HARD; punch_hard_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_KICK_MEDIUM_STANDING; kick_medium_timer = SDL_GetTicks(); break;
				case IN_4: state = ST_KICK_HARD_STANDING; kick_hard_timer = SDL_GetTicks(); break;
				case IN_DAMAGE: state = ST_DAMAGE; dmg_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_HARD: state = ST_DAMAGE_HARD; dmg_hard_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_FALL: state = ST_DAMAGE_FALL; dmg_fall_timer = SDL_GetTicks(); break;
				case IN_BLOCK: state = ST_BLOCK; block_timer = SDL_GetTicks(); break;
				case IN_WHIRLWINDKICK: state = ST_WHIRLWIND; whirlwind_timer = SDL_GetTicks(); break;
				case IN_VICTORY: state = ST_VICTORY; victory_timer = SDL_GetTicks(); break;
				case IN_VICTORY2_: state = ST_VICTORY2_; victory2_timer = SDL_GetTicks(); break;
				case IN_LOSE: state = ST_LOSE; lose_timer = SDL_GetTicks();  break;
				}
			}
			break;

			case ST_JUMP_NEUTRAL:
			{
				if (hit_started > 0) {
					hit_started = 0;
				}
				if (hit_conected > 0) {
					hit_conected = 0;
				}
				switch (last_input)
				{
				case IN_JUMP_FINISH: state = ST_IDLE; break;
				case IN_X: state = ST_PUNCH_NEUTRAL_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_1: state = ST_PUNCH_MEDIUM_NEUTRAL_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_2: state = ST_PUNCH_HARD_NEUTRAL_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_C: state = ST_KICK_NEUTRAL_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_3:state = ST_KICK_MEDIUM_NEUTRAL_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_4:state = ST_KICK_HARD_NEUTRAL_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_AIR:state = ST_DAMAGE_AIR; dmg_fall_timer = SDL_GetTicks(); break;
				case IN_LOSE: state = ST_LOSE; lose_timer = SDL_GetTicks();  break;
				}
			}
			break;

			case ST_JUMP_FORWARD:
			{
				if (hit_started > 0) {
					hit_started = 0;
				}
				if (hit_conected > 0) {
					hit_conected = 0;
				}
				switch (last_input)
				{
				case IN_JUMP_FINISH: state = ST_IDLE; break;
				case IN_X: state = ST_PUNCH_FORWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_C: state = ST_KICK_FORWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_1: state = ST_PUNCH_MEDIUM_FORWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_2: state = ST_PUNCH_HARD_FORWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_KICK_MEDIUM_FORWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_4: state = ST_KICK_HARD_FORWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_AIR:state = ST_DAMAGE_AIR; dmg_fall_timer = SDL_GetTicks(); break;
				case IN_LOSE: state = ST_LOSE; lose_timer = SDL_GetTicks();  break;
				
				}
			}
			break;

			case ST_JUMP_BACKWARD:
			{
				if (hit_conected > 0) {
					hit_conected = 0;
				}
				if (hit_started > 0) {
					hit_started = 0;
				}
				switch (last_input)
				{
				case IN_JUMP_FINISH: state = ST_IDLE; break;
				case IN_X: state = ST_PUNCH_BACKWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_C: state = ST_KICK_BACKWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_1: state = ST_PUNCH_MEDIUM_BACKWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_2: state = ST_PUNCH_HARD_BACKWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_KICK_MEDIUM_BACKWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_4: state = ST_KICK_HARD_BACKWARD_JUMP; punch_neutral_jump_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_AIR:state = ST_DAMAGE_AIR; dmg_fall_timer = SDL_GetTicks(); break;
				case IN_LOSE: state = ST_LOSE; lose_timer = SDL_GetTicks();  break;
				}
			}
			break;

			case ST_PUNCH_NEUTRAL_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
				{
					App->audio->PlayChunk(light_damage, 1);
					App->UI->scoreP2 += 200;
					hit_conected++;
				}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_NEUTRAL;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH: 
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_PUNCH_MEDIUM_NEUTRAL_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 200;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_NEUTRAL;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH: 
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_PUNCH_HARD_NEUTRAL_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2+= 200;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_NEUTRAL;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH: 
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_KICK_NEUTRAL_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 200;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_NEUTRAL;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH: 
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_KICK_MEDIUM_NEUTRAL_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 200;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_NEUTRAL;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_KICK_HARD_NEUTRAL_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 200;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_NEUTRAL;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH:
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_PUNCH_FORWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_FORWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH:
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_PUNCH_MEDIUM_FORWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_FORWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH:
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_PUNCH_HARD_FORWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_FORWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH: 
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_KICK_FORWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_FORWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH: 
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_KICK_MEDIUM_FORWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_FORWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH: 
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_KICK_HARD_FORWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_FORWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH: 
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_PUNCH_BACKWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_BACKWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;
			case ST_PUNCH_MEDIUM_BACKWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_BACKWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH:
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;
			case ST_PUNCH_HARD_BACKWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_BACKWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_KICK_BACKWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_BACKWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;
			case ST_KICK_MEDIUM_BACKWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_BACKWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;
			case ST_KICK_HARD_BACKWARD_JUMP:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_JUMP_BACKWARD;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				case IN_JUMP_FINISH: 
					state = ST_IDLE; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;
			case ST_PUNCH_STANDING:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_CROUCH:
			{
				if (hit_conected > 0) {
					hit_conected = 0;
				}
				if (hit_started > 0) {
					hit_started = 0;
				}
				switch (last_input)
				{
				case IN_CROUCH_UP: state = ST_IDLE; break;
				case IN_JUMP_AND_CROUCH: state = ST_IDLE; break;
				case IN_X: state = ST_PUNCH_CROUCH; punch_hard_timer = SDL_GetTicks(); break;
				case IN_C: state = ST_KICK_CROUCH; punch_medium_timer = SDL_GetTicks(); break;
				case IN_1: state = ST_PUNCH_MEDIUM_CROUCH; punch_hard_timer = SDL_GetTicks(); break;
				case IN_2: state = ST_PUNCH_HARD_CROUCH; punch_hard_timer = SDL_GetTicks(); break;
				case IN_3: state = ST_KICK_MEDIUM_CROUCH; punch_medium_timer = SDL_GetTicks(); break;
				case IN_4: state = ST_KICK_HARD_CROUCH; kick_hard_timer = SDL_GetTicks(); break;
				case IN_DAMAGE_CROUCH: state = ST_DAMAGE_CROUCH; dmg_hard_timer = SDL_GetTicks(); break;
				case IN_BLOCK_CROUCH: state = ST_BLOCK_CROUCH; block_timer = SDL_GetTicks(); break;
				case IN_VICTORY: state = ST_VICTORY; victory_timer = SDL_GetTicks(); break;
				case IN_VICTORY2_: state = ST_VICTORY2_; victory2_timer = SDL_GetTicks(); break;
				case IN_LOSE: state = ST_LOSE; lose_timer = SDL_GetTicks();  break;
				}
			}
			break;
			case ST_PUNCH_CROUCH:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_HARD_FINISH:
					if (IN_CROUCH_DOWN == true)
						state = ST_CROUCH;
					else
						state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					crouchAttack = false;
					break;
				}
			}
			break;
			case ST_PUNCH_MEDIUM_CROUCH:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 200;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_HARD_FINISH:
					if (IN_CROUCH_DOWN == true)
						state = ST_CROUCH;
					else
						state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					crouchAttack = false;
					break;
				}
			}
			break;
			case ST_PUNCH_HARD_CROUCH:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 300;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_HARD_FINISH:
					if (IN_CROUCH_DOWN == true)
						state = ST_CROUCH;
					else
						state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					crouchAttack = false;
					break;
				}
			}
			break;
			case ST_KICK_CROUCH:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_MEDIUM_FINISH:
					if (IN_CROUCH_DOWN == true)
						state = ST_CROUCH;
					else
						state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					crouchAttack = false;
					break;
				}
			}
			break;
			case ST_KICK_MEDIUM_CROUCH:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 200;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_MEDIUM_FINISH:
					if (IN_CROUCH_DOWN == true)
						state = ST_CROUCH;
					else
						state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					
					crouchAttack = false;
					break;
				}
			}
			break;
			case ST_KICK_HARD_CROUCH:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 300;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_KICK_HARD_FINISH:
					if (IN_CROUCH_DOWN == true)
						state = ST_CROUCH;
					else
						state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;
			case ST_KICK_STANDING:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 100;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_KICK_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;
			case ST_KICK_MEDIUM_STANDING:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 200;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_KICK_MEDIUM_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_KICK_HARD_STANDING:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 300;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_KICK_HARD_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_PUNCH_MEDIUM:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(medium_damage, 1);
						App->UI->scoreP2 += 200;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_MEDIUM_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}

			}
			break;


			case ST_PUNCH_HARD:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(light_damage, 1);
						App->UI->scoreP2 += 300;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_PUNCH_HARD_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}

			}
			break;
			case ST_LIGHTNINGKICK:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
						App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 500;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_LIGHTNINGKICK_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}

			}
			break;
			case ST_WHIRLWIND:
			{
				if (App->chunli->damage_received > 0 && hit_conected == 0)
					{
					    App->audio->PlayChunk(high_damage, 1);
						App->UI->scoreP2 += 500;
						hit_conected++;
					}
				switch (last_input)
				{
				case IN_WHIRLWINDKICK_FINISH:
					state = ST_IDLE;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					position.y = 220;
				}
			}
			break;

			case ST_DAMAGE:
			{
				switch (last_input)
				{
				case IN_DAMAGE_FINISH:
					state = ST_IDLE;
					damage_received = 0;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_DAMAGE_HARD:
			{
				switch (last_input)
				{
				case IN_DAMAGE_FINISH:
					state = ST_IDLE; 
					damage_received = 0;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;
			case ST_DAMAGE_FALL:
			{
				switch (last_input)
				{
				case IN_DAMAGE_FINISH:
					state = ST_IDLE; 
					damage_received = 0; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_DAMAGE_AIR:
			{
				switch (last_input)
				{
				case IN_DAMAGE_FINISH:
					state = ST_IDLE; 
					damage_received = 0; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			case ST_BLOCK:
			{
				switch (last_input)
				{
				case IN_BLOCK_FINISH:
					state = ST_IDLE;
					block_damage = 0;
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_BLOCK_CROUCH:
			{
				switch (last_input)
				{
				case IN_BLOCK_FINISH:
					state = ST_IDLE; 
					block_damage = 0; 
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_DAMAGE_CROUCH:
			{
				switch (last_input)
				{
				case IN_DAMAGE_FINISH:
					state = ST_IDLE; 
					damage_received = 0;
					if (hit_started > 0) {
						hit_started = 0;
					}
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					break;
				}
			}
			break;

			case ST_VICTORY:
			{
				switch (last_input)
				{
				case IN_VICTORY_FINISH:					
					state = ST_IDLE;
					win = 3;
					
					ResetPlayer();
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
					break;
				}
			}
			break;

			case ST_VICTORY2_:
			{
				switch (last_input)
				{
				case IN_VICTORY2_FINISH:

					state = ST_IDLE;
					win = 3;
					//victorycount++;
					ResetPlayer();
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}

					//ResetPlayer();
					break;
				}
			}
			break;

			case ST_LOSE:
			{
				switch (last_input)
				{
				case IN_LOSE_FINISH:
					state = ST_IDLE;
					
			
					if (victorycount < 2)
						ResetPlayer();
					
					if (hit_conected > 0) {
						hit_conected = 0;
					}
					if (hit_started > 0) {
						hit_started = 0;
					}
				//	ResetPlayer();
					break;
				}
			}
			break;
			}
		
	}
	return state;
}

void ModuleChunLi2::lifecondition(Animation* current_animation) {


	healthbar = life * 0.153;

	if (life < 0) {
		life = 0;
	}

	if (life == 0 && App->chunli->state != ST_VICTORY2 && App->chunli->state != ST_VICTORY2_2 && App->chunli->victorycount != 2)
	{
		lose = true;	
	}
	else {
		lose = false;
	}
	
}

void ModuleChunLi2::resetanimations() {

	damage_received = 0;

	sound = 0;
	WinSoundPlayed = false;
	DeathSoundPlayed = false;
	win2.Reset();
	win = 0;
	ignore = 0;

	jump_neutral.Reset();
	jump_forward.Reset();
	jump_backwards.Reset();
	punch.Reset();
	jump_neutral_punch.Reset();
	jump_neutral_punch_medium.Reset();
	jump_neutral_punch_hard.Reset();
	jump_backward_punch.Reset();
	jump_forward_punch.Reset();
	Crouch_punch.Reset();
	kick.Reset();
	LightningKick.Reset();
	punch_medium.Reset();
	punch_hard.Reset();
	kick_medium.Reset();
	kick_hard.Reset();
	Crouch_punch.Reset();
	Crouch_medium_punch.Reset();
	Crouch_hard_punch.Reset();
	Crouch_kick.Reset();
	Crouch_medium_kick.Reset();
	Crouch_hard_kick.Reset();
	damage.Reset();
	damage2.Reset();
	damage3.Reset();
	damage4.Reset();
	damage5.Reset();
	jump_neutral_kick.Reset();
	jump_neutral_kick_medium.Reset();
	jump_neutral_kick_hard.Reset();

	jump_forward_punch_medium.Reset();
	jump_forward_punch_hard.Reset();

	jump_backward_punch_medium.Reset();
	jump_backward_punch_hard.Reset();

	jump_forward_kick.Reset();
	jump_forward_kick_medium.Reset();
	jump_forward_kick_hard.Reset();

	jump_backward_kick.Reset();
	jump_backward_kick_medium.Reset();
	jump_backward_kick_hard.Reset();

	WhirlwindKick.Reset();
	win1.Reset();
	win2.Reset();
}

void ModuleChunLi2::debugcommands() {


	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_DOWN) {
		life = 0;
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN)
	{
		if (!GodMode) {
			for (int i = 0; i < MAX_COLLIDERS; i++)
			{
				if (colliders[i] != nullptr)
					colliders[i]->to_delete = true;
			}
			GodMode = true;
		}
		else {
			GodMode = false;
		}

	}

}

void ModuleChunLi2::jump_neutral_logic() {

	if (SDL_GetTicks() - jump_timer <= JUMP_TIME2 / 4.5) {
		position.y -= 8;
	}

	if (SDL_GetTicks() - jump_timer > JUMP_TIME2 / 4.5 && SDL_GetTicks() - jump_timer < JUMP_TIME2 / 1.28) {
		if (SDL_GetTicks() - jump_timer < JUMP_TIME2 / 2) {
			position.y -= 4;
		}

		if (SDL_GetTicks() - jump_timer > JUMP_TIME2 / 2) {
			position.y += 4;
		}
	}

	if (SDL_GetTicks() - jump_timer >= JUMP_TIME2 / 1.28) {
		position.y += 10;
	}
}

void ModuleChunLi2::jump_forward_logic() {

	position.x += (3 * speedX);


	if (SDL_GetTicks() - jump_timer <= JUMP_TIME2 / 5) {
		position.y -= 9;

	}
	if (SDL_GetTicks() - jump_timer > JUMP_TIME2 / 5 && SDL_GetTicks() - jump_timer < JUMP_TIME2 / 1.25) {
		if (SDL_GetTicks() - jump_timer < JUMP_TIME2 / 2) {
			position.y -= 5;

		}

		if (SDL_GetTicks() - jump_timer > JUMP_TIME2 / 2) {
			position.y += 7;

		}
	}

	if (SDL_GetTicks() - jump_timer >= JUMP_TIME2 / 1.25) {
		position.y += 8;
	}

}

void ModuleChunLi2::jump_backward_logic() {

	position.x -= (3 * speedX);


	if (SDL_GetTicks() - jump_timer <= JUMP_TIME2 / 5) {
		position.y -= 9;

	}
	if (SDL_GetTicks() - jump_timer > JUMP_TIME2 / 5 && SDL_GetTicks() - jump_timer < JUMP_TIME2 / 1.25) {
		if (SDL_GetTicks() - jump_timer < JUMP_TIME2 / 2) {
			position.y -= 5;

		}

		if (SDL_GetTicks() - jump_timer > JUMP_TIME2 / 2) {
			position.y += 7;

		}
	}

	if (SDL_GetTicks() - jump_timer >= JUMP_TIME2 / 1.25) {
		position.y += 8;
	}

}
