#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
    _monster = make_shared<GameObject>(L"Resource/monster.png");
    _monster->GetTransform()->SetPos(Vector(900, 600));
    _monster->GetTransform()->SetScale(Vector(150, 150));
}


Monster::~Monster()
{
}

void Monster::Update()
{
    _monster->Update();
}

void Monster::Render()
{
    _monster->Render();
}
