#pragma once

class Time {
private:
    LARGE_INTEGER frequency;
    LARGE_INTEGER lastTime;
    float deltaTime = 0.0f;
public:
    Time();

    void timeUpdate();
    float getDeltaTime() const;
};

extern Time G_TIME;