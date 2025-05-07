#pragma once

#define KEY_MAX 255

class InputManager
{
private:
    enum State
    {
        NONE,
        DOWN,
        UP,
        PRESS
    };
public:
    static void Create()
    {
        if (_instance == nullptr)
            _instance = new InputManager();
    }

    static void Delete()
    {
        if (_instance != nullptr)
            delete _instance;
    }

    static InputManager* GetInstance() { return _instance; }

    void Update();

    bool Down(UINT key) { return _stateMap[key] == DOWN; }
    bool Up(UINT key) { return _stateMap[key] == UP; }
    bool Press(UINT key) { return _stateMap[key] == PRESS; }

private:
    InputManager();
    ~InputManager();

    static InputManager* _instance;

    byte _curState[KEY_MAX];			// byte 는 8비트 크기의 데이터 타입 , 0 ~ 255까지의 값을 표현할 수 있다.
    byte _oldState[KEY_MAX];
    byte _stateMap[KEY_MAX];
};
