#include "actor.h"
#include <raymath.h>
#include <string.h>
#include "environment.h"

#define TRAIL 0


static void UpdateAngle(Actor* actor, float frametime)
{
	int xIn = (int)IsKeyDown(KEY_RIGHT) - (int)IsKeyDown(KEY_LEFT);
	actor->rotation += (xIn * 100 * frametime);
}

void UpdateVelocity(Actor* actor, float frametime){

    int yIn = (int)IsKeyDown(KEY_UP);
    float magSqr = Vector2LengthSqr(actor->velocity);
	float mag = sqrt(magSqr);
    Vector2 facingDirection = ActorFacingDirection(*actor);

    if (yIn > 0) {  
        actor->velocity = Vector2Add(actor->velocity,
			Vector2Scale(facingDirection, 1.5 * frametime));
    }else{
        //DrawText(TextFormat("Gravity takes hold...", actor->velocity), 40, 40, 16, WHITE);
        //Vector2 gravityVector = Vector2Scale(defaultEnvironment.gravity_direction,defaultEnvironment.gravity_scale);
        //actor->velocity = Vector2Add(actor->velocity, Vector2Scale(gravityVector, 0.5 * frametime));
    }


}
Vector2 ActorFacingDirection(Actor actor)
{
	return Vector2Rotate((Vector2){0, -1}, actor.rotation * DEG2RAD);
}
void ActorDraw(Actor actor, Texture2D texture)
{
	const Rectangle source = {0, 0, 16, 16};
	Rectangle dest = {actor.position.x, actor.position.y, PLAYER_RADIUS * 2, PLAYER_RADIUS * 2};
	Vector2 origin = {dest.width / 2, dest.height / 2};

	Color color = WHITE;

	DrawTexturePro(texture, source, dest, origin, actor.rotation, color);
}

static Vector2 origin = {0,0};

void ActorMove(Actor* actor)
{
	float frametime = GetFrameTime();
    char* description = "actor: %d";
    DrawText(TextFormat("actor: %s",actor->name), actor->position.x - 60, actor->position.y - 80, 16, WHITE);
    DrawText(TextFormat("pos: %.0f,%.0f",actor->position.x, actor->position.y), actor->position.x - 60, actor->position.y - 60, 16, WHITE);
    DrawPixel(actor->position.x - origin.x,actor->position.y - origin.y,WHITE);
    DrawText(TextFormat("vel: %.0f,%.0f",actor->velocity.x, actor->velocity.y), actor->position.x - 60, actor->position.y - 40, 16, WHITE);
    UpdateAngle(actor, frametime);
    UpdateVelocity(actor,frametime);
	actor->position = Vector2Add(actor->position, Vector2Scale(actor->velocity, frametime));

}