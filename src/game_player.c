#include "game_player.h"
#include "raymath.h"
#include "constants.h"



static Actor _player;
static Texture2D _texturePlayer;






void InitPlayer(void)
{
	ResetPlayer();
	_texturePlayer = LoadTexture("../res/ship.png");
}
void ResetPlayer(void)
{
	_player = (Actor){
        .name = "Player",
		.position = SCREEN_CENTER,
		.velocity = (Vector2){0,0},
		.rotation = 0,
	};

}

void DrawPlayer(void)
{
	ActorDraw(_player, _texturePlayer);
}
Actor* GetPlayer(){
    return &_player;
}
void UpdatePlayer(void){

    ActorMove(&_player);
}