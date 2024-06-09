#include "game_environment.h"

#include "environment.h"
#include <raylib.h>
#include <math.h>

static Environment _environment;

static Texture2D _texture_stars_1;
static Texture2D _texture_stars_2;
static Vector2 playerPosition; 
void InitEnvironment(void)
{

    _environment.env_name = "Eregon";
    _environment.gravity_direction = (Vector2){0,-1};
    _texture_stars_1 = LoadTexture("../res/stars_1.png");
    _texture_stars_2 = LoadTexture("../res/stars_2.png");

}
void EnvironmentSetPlayerInfo(Actor* player)
{
    playerPosition = player->position;
}
void UpdateEnvironment(void)
{
    
}

void DrawEnvironment(void)
{
    float parallaxFactor1 = 0.1f; // Move very little
    float parallaxFactor2 = 0.2f; // Move even less

    // Get the dimensions of the textures and scale them
    Vector2 textureSize1 = { _texture_stars_1.width * 3.0f, _texture_stars_1.height * 3.0f };
    Vector2 textureSize2 = { _texture_stars_2.width * 3.0f, _texture_stars_2.height * 3.0f };

    // Calculate the offset positions for the textures
    Vector2 offset1 = { fmod(playerPosition.x * parallaxFactor1, textureSize1.x), fmod(playerPosition.y * parallaxFactor1, textureSize1.y) };
    Vector2 offset2 = { fmod(playerPosition.x * parallaxFactor2, textureSize2.x), fmod(playerPosition.y * parallaxFactor2, textureSize2.y) };

    // Adjust offsets to ensure they are positive
    if (offset1.x < 0) offset1.x += textureSize1.x;
    if (offset1.y < 0) offset1.y += textureSize1.y;
    if (offset2.x < 0) offset2.x += textureSize2.x;
    if (offset2.y < 0) offset2.y += textureSize2.y;

    // Draw the first layer of stars with minimal movement
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            Vector2 position = { (x * textureSize1.x) - offset1.x, (y * textureSize1.y) - offset1.y };
            DrawTextureEx(_texture_stars_1, position, 0.0f, 3.0f, WHITE);
        }
    }

    // Draw the second layer of stars with even less movement
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            Vector2 position = { (x * textureSize2.x) - offset2.x, (y * textureSize2.y) - offset2.y };
            DrawTextureEx(_texture_stars_2, position, 0.0f, 3.0f, WHITE);
        }
    }
}


Environment* GetEnvironment()
{
    return &_environment;
}



