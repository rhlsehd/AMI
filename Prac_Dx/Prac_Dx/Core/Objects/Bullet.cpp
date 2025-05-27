#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
    _bullet = make_shared<GameObject>(L"Resource/bullet_tear.png");

    _bullet->GetTransform()->SetScale(Vector(30, 30));

    _bulletCol = make_shared<CircleCollider>(Vector(0, 0), 0.5f);
    _bulletCol->GetTransform()->SetParent(_bullet->GetTransform());
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
    if (!_isActive) return;

    _bullet->Update();
    _bulletCol->Update();
    _bullet->GetTransform()->AddPos(_bulletDir * 500.0f * DELTA_TIME);

    
    _time += DELTA_TIME;
    if (_time > 5.0f)
    {
        _time = 0.0f;
        _isActive = false;
    }
}

void Bullet::Render()
{
    _bullet->Render();
    _bulletCol->Render();
}

void Bullet::SetPos(Vector pos)
{
    _bullet->GetTransform()->SetPos(pos);
}

void Bullet::SetDir(Vector dir)
{
    _bulletDir = dir.UnitVector();
}
