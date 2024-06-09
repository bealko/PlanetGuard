#include "game_player.h"
#include "raymath.h"
#include "constants.h"



static Actor _player;
static Texture2D _texturePlayerTexture;
static Texture2D _thrusterFireTexture;





void InitPlayer(void)
{
	ResetPlayer();
	_texturePlayerTexture = LoadTexture("../res/ship.png");
	_thrusterFireTexture = LoadTexture("../res/thruster_fire.png");
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

Actor* GetPlayer(){
    return &_player;
}


void DrawPlayer(void)
{
	if (GetPlayer()->thrust > 0)
	DrawThrusterFire();
	ActorDraw(_player, _texturePlayerTexture);
	
}

void UpdatePlayer(void){
	ActorReadInput();
    ActorMove(&_player);

}
void DrawThrusterFire() {
    int frames_count = 4; // Assuming 4 frames for the thruster fire animation
    static int currentFrame = 0;
    static int frameCounter = 0;
    static int frameSpeed = 8;

    // Source rectangle definition (sprite sheet)
    Rectangle source = { currentFrame * (_thrusterFireTexture.width / frames_count), 0, _thrusterFireTexture.width / frames_count, _thrusterFireTexture.height };

    // Increment frame counter and update current frame
    frameCounter++;
    if (frameCounter >= (60 / frameSpeed)) {
        frameCounter = 0;
        currentFrame++;
        if (currentFrame >= frames_count) currentFrame = 0;

        source.x = (float)currentFrame * (_thrusterFireTexture.width / frames_count);
    }

    // Player's position and rotation
    Vector2 playerPos = GetPlayer()->position;
    float playerRot = GetPlayer()->rotation;

    // Position offset to place the thruster fire correctly behind the player
    Vector2 offset = { 0, 30 }; // Adjust this to set the thruster position relative to the player
    Vector2 rotatedOffset = Vector2Rotate(offset, playerRot * DEG2RAD); // Convert rotation to radians

    // Calculate the final position for the thruster fire
    Vector2 finalPosition = Vector2Add(playerPos, rotatedOffset);

    // Destination rectangle definition (scaling the texture)
    Rectangle dest = { finalPosition.x, finalPosition.y, (float)_thrusterFireTexture.width / frames_count, (float)_thrusterFireTexture.height };


    // Draw the thruster fire texture
    DrawTexturePro(
        _thrusterFireTexture,
        source,
        dest,
        (Vector2){ dest.width / 2, dest.height / 2 }, // Offset for the center of the destination rectangle
        playerRot,
        WHITE
    );
}
