#include "framework.h"
#include "Heart.h"

Heart::Heart()
{
    _player = make_shared<Player>();

    for (int i = 0; i < 3; i++)
    {
        auto heart = make_shared<GameObject>(L"Resource/heart.png");

        heart->GetTransform()->SetPos(Vector(50, 680) + Vector(i * 50, 0));
        heart->GetTransform()->SetScale(Vector(50, 50));
        _heart.push_back(heart);
    }
}

Heart::~Heart()
{
}

void Heart::Update()
{
    int hp = _player->GetHp();

    for (int i = 0; i < hp; i++)
    {
        _heart[i]->Update();
    }
}

void Heart::Render()
{
    int hp = _player->GetHp();

    for (int i = 0; i < hp; i++)
    {
        _heart[i]->Render();
    }
}
