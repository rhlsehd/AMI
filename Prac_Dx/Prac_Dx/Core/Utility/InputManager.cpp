#include "framework.h"
#include "InputManager.h"

InputManager* InputManager::_instance = nullptr;

InputManager::InputManager()
    : _curState{}, _oldState{}, _stateMap{}
{
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
    memcpy(_oldState, _curState, sizeof(_oldState));
    // memcpy(목적지, 원본, 복사할 바이트 수)
    // 이 코드의 목적 : 현재 키보드 상태(_curState)를 이전상태(_oldState) 로 복사하는것
    // 이전상태와 현재상태를 비교하여 키가 눌렀는지 떼졌는지 알 수 있다.

    GetKeyboardState(_curState);

    for (int i = 0; i < KEY_MAX; i++)
    {
        byte key = _curState[i] & 0x80;
        _curState[i] = key ? 1 : 0; //  삼항 연산자, key가 true면 1, 아니면 0

        int old = _oldState[i];
        int cur = _curState[i];

        if (old == 0 && cur == 1) // 전에는 안눌렀고 현재 누름 -> 키가 눌렸을 때
        {
            _stateMap[i] = State::DOWN;
        }
        else if (old == 1 && cur == 0) // 전에는 눌렀고 현재는 누르지 않음 -> 키를 뗐을 때
        {
            _stateMap[i] = State::UP;
        }
        else if (old == 1 && cur == 1) // 전에도 눌렀꼬 현재도 누르고 있을때 -> 키를 계속 누르고 있음
        {
            _stateMap[i] = State::PRESS;
        }
        else // 아예 안누름
        {
            _stateMap[i] = State::NONE;
        }

    }
}

