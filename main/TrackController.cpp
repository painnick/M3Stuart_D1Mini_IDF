//
// Created by painnick on 2022-12-13.
//

#include <Arduino.h>
#include "TrackController.h"

// 0~255
#define TRACK_MOTOR_RESOLUTION 8

TrackController::TrackController(int pin1, int pin2, int ledc1, int ledc2) : pin1(pin1), pin2(pin2), ledc1(ledc1), ledc2(ledc2), speed(256 - 1) {
    // ledcSetup(ledc1, 1000, TRACK_MOTOR_RESOLUTION);
    // ledcSetup(ledc2, 1000, TRACK_MOTOR_RESOLUTION);

    // ledcAttachPin(pin1, ledc1);
    // ledcAttachPin(pin2, ledc2);
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void TrackController::forward() {
    // ledcWrite(ledc1, speed);
    // ledcWrite(ledc2, 0);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
}

void TrackController::backward() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
}

void TrackController::stop() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}

void TrackController::setSpeed(int speed1) {
    speed = speed1;
}

int TrackController::speedUp(int step) {
    speed = min(speed + step, 256 - 1);
    return speed;
}

int TrackController::speedDown(int step) {
    speed = max(speed - step, 196 - 1);
    return speed;
}