#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <raylib.h>
typedef struct Environment {
    char* env_name;
    Vector2 gravity_direction;
    float gravity_scale;
} Environment;


#endif



