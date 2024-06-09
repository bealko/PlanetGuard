#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "actor.h"

void InitPlayer(void);
void DrawPlayer(void);
void UpdatePlayer(void);
Actor* GetPlayer();
void ResetPlayer(void);
#endif

