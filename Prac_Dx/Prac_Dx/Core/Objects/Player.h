#pragma once
class Player
{
public:
    Player();
    ~Player();

    void Update();
    void Render();

    void Input();

private:
    shared_ptr<GameObject> _player;

    float _speed = 300.0f;
};

