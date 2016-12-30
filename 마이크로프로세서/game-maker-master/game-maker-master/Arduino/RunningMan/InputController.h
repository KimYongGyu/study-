#include <Arduino.h>

#define JOYSTICK_X_PIN A1
#define JOYSTICK_Y_PIN A2
#define BUTTON_A_PIN 30
#define BUTTON_B_PIN 32

#define LEFT_THRESHOLD 300
#define RIGHT_THRESHOLD 700
#define UP_THRESHOLD 300
#define DOWN_THRESHOLD 700

class InputController {
	public:
		InputController();
		uint8_t getInput();

	private:
		
};

