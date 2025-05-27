#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
    _monster = make_shared<GameObject>(L"Resource/monster.png");
    _monster->GetTransform()->SetPos(Vector(900, 600));
    _monster->GetTransform()->SetScale(Vector(150, 150));

    _monsterCol = make_shared<CircleCollider>(Vector(0.1f, 0.1f), 0.48f);
    _monsterCol->GetTransform()->SetParent(_monster->GetTransform());

    _transform = make_shared<Transform>();
}


Monster::~Monster()
{
}

void Monster::Update()
{
    _monster->Update();
    _monsterCol->Update();
    _transform->Update();
}

void Monster::Render()
{
    _monster->Render();
    _monsterCol->Render();
}

void Monster::HitbyPlayer(const shared_ptr<Player>& player)
{
    if (_hp > 0)
        _hp -= player->GetAtk();
}

void Monster::SetPos(Vector pos)
{
    _monster->GetTransform()->SetPos(pos);
}


