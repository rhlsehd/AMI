#include "framework.h"
#include "Player.h"

Player::Player()
{
    _player = make_shared<GameObject>(L"Resource/Isaac.png");
    _player->GetTransform()->SetPos(Vector(WIN_WIDTH / 2.0f, WIN_HEIGHT / 2.0f));
    _player->GetTransform()->SetScale(Vector(150, 150));
}

Player::~Player()
{
}

void Player::Update()
{
     Input();
    _player->Update();
}

void Player::Render()
{
    _player->Render();
}

void Player::Input()
{
    if (KEY_PRESS('A'))
    {
        _player->GetTransform()->AddPos(Vector(-1, 0) * DELTA_TIME * _speed);
    }
    if (KEY_PRESS('D'))
    {
        _player->GetTransform()->AddPos(Vector(1, 0) * DELTA_TIME * _speed);
    }
    if (KEY_PRESS('W'))
    {
        _player->GetTransform()->AddPos(Vector(0, 1) * DELTA_TIME * _speed);
    }
    if (KEY_PRESS('S'))
    {
        _player->GetTransform()->AddPos(Vector(0, -1) * DELTA_TIME * _speed);
    }
}
