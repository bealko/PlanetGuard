
#include "game.h"
#include "game_player.h"
#include "constants.h"
typedef enum GameState {
    PAUSED = 0,
    PLAYING = 1
} GameState;

static GameState _state;

float _gravity = -10.0;

static Vector2 cameraTarget;

Camera2D _camera = {0};
void InitGame(void)
{
    _camera.offset = (Vector2){ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f };
    _camera.rotation = 0.0f;
    _camera.zoom = 1.0f;
	InitPlayer();
    InitEnvironment();
}
void UpdateGameCamera(void){
    _camera.target = GetPlayer()->position;
}
void UpdateGame(void)
{   
    BeginMode2D(_camera);

    UpdateEnvironment();
    DrawEnvironment();
    EnvironmentSetPlayerInfo(GetPlayer());
    UpdateGameCamera();

	UpdatePlayer();
    DrawPlayer();

    EndMode2D();
}


void DrawGame(void)
{
	switch (_state)
	{
        case PAUSED:
        _state = PLAYING;
        break;
		
	case PLAYING:
        UpdateGame();
		break;
		
	default:
		//TraceLog(LOG_ERROR, "Unhandled GameState!");
		break;
	}

}