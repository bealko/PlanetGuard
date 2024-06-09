#ifndef ACTOR_H
#define ACTOR_H
#include <raylib.h>

#define PLAYER_RADIUS 20

typedef enum ActorState
{
	PLAYER_DEFAULT = 0,
} ActorState;

typedef struct Actor
{
    char* name;
    Vector2 position;
    Vector2 velocity;
    ActorState state;
    float rotation;

} Actor;




Vector2 ActorFacingDirection(Actor player);
void ActorDraw(Actor actor, Texture2D texture );
void ActorUpdate(Actor* actor);
void ActorMove(Actor* actor);
void ActorAddVelocity(Vector2 velocity);


#endif



