#ifndef GAME_ENVIRONMENT_H
#define GAME_ENVIRONMENT_H
#include "environment.h"
#include "actor.h"

void InitEnvironment(void);
void UpdateEnvironment(void);
void DrawEnvironment(void);
void EnvironmentSetPlayerInfo(Actor* player);
Environment* GetEnvironment();

#endif