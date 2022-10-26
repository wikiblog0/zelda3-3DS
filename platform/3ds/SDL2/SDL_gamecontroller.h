#ifndef SDL_gamecontroller_h_
#define SDL_gamecontroller_h_

#include "SDL_stdinc.h"
#include "SDL_error.h"
//#include "SDL_rwops.h"
//#include "SDL_sensor.h"
#include "SDL_joystick.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

struct _SDL_GameController;
typedef struct _SDL_GameController SDL_GameController; //59







extern DECLSPEC SDL_bool SDLCALL SDL_IsGameController(int joystick_index); //181

extern DECLSPEC SDL_GameController *SDLCALL SDL_GameControllerOpen(int joystick_index); //213


typedef enum
{
    SDL_CONTROLLER_AXIS_INVALID = -1,
    SDL_CONTROLLER_AXIS_LEFTX,
    SDL_CONTROLLER_AXIS_LEFTY,
    SDL_CONTROLLER_AXIS_RIGHTX,
    SDL_CONTROLLER_AXIS_RIGHTY,
    SDL_CONTROLLER_AXIS_TRIGGERLEFT,
    SDL_CONTROLLER_AXIS_TRIGGERRIGHT,
    SDL_CONTROLLER_AXIS_MAX
} SDL_GameControllerAxis; //322


typedef enum
{
    SDL_CONTROLLER_BUTTON_INVALID = -1,
    SDL_CONTROLLER_BUTTON_A,
    SDL_CONTROLLER_BUTTON_B,
    SDL_CONTROLLER_BUTTON_X,
    SDL_CONTROLLER_BUTTON_Y,
    SDL_CONTROLLER_BUTTON_BACK,
    SDL_CONTROLLER_BUTTON_GUIDE,
    SDL_CONTROLLER_BUTTON_START,
    SDL_CONTROLLER_BUTTON_LEFTSTICK,
    SDL_CONTROLLER_BUTTON_RIGHTSTICK,
    SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
    SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
    SDL_CONTROLLER_BUTTON_DPAD_UP,
    SDL_CONTROLLER_BUTTON_DPAD_DOWN,
    SDL_CONTROLLER_BUTTON_DPAD_LEFT,
    SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
    SDL_CONTROLLER_BUTTON_MISC1,    /* Xbox Series X share button, PS5 microphone button, Nintendo Switch Pro capture button */
    SDL_CONTROLLER_BUTTON_PADDLE1,  /* Xbox Elite paddle P1 */
    SDL_CONTROLLER_BUTTON_PADDLE2,  /* Xbox Elite paddle P3 */
    SDL_CONTROLLER_BUTTON_PADDLE3,  /* Xbox Elite paddle P2 */
    SDL_CONTROLLER_BUTTON_PADDLE4,  /* Xbox Elite paddle P4 */
    SDL_CONTROLLER_BUTTON_TOUCHPAD, /* PS4/PS5 touchpad button */
    SDL_CONTROLLER_BUTTON_MAX
} SDL_GameControllerButton; //386









/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_gamecontroller_h_ */