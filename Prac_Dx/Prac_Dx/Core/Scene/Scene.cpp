#include "framework.h"
#include "Scene.h"

Scene::Scene()
{
    _backGround = make_shared<GameObject>(L"Resource/map.png");

    _player = make_shared<Player>();

    for (int i = 0; i < 6; i++)
    {
        auto monster = make_shared<Monster>();   
        _monster.push_back(monster);
    }

    _monster[0]->SetPos(Vector(100, 100));
    _monster[1]->SetPos(Vector(100, 650));
    _monster[2]->SetPos(Vector(550, 100));
    _monster[3]->SetPos(Vector(1000, 100));
    _monster[4]->SetPos(Vector(550, 650));
    _monster[5]->SetPos(Vector(1000, 650));
   

    _heart = make_shared<Heart>();
    _heart->SetPlayer(_player);

    _backGround->GetTransform()->SetPos(CENTER);
    _backGround->GetTransform()->SetScale(Vector(WIN_WIDTH, WIN_HEIGHT));
    _backGround->Update();

    for (int i = 0; i < 30; i++)
    {
        shared_ptr<Bullet> bullet = make_shared<Bullet>();
        _bullets.push_back(bullet);
    }
}

Scene::~Scene()
{

}

void Scene::Update()
{
    _time += DELTA_TIME;
    _hitTime += DELTA_TIME;

    _player->Update();
    _heart->Update();
    
    // 몬스터, 총알 업데이트
    for (const auto& m : _monster)
        m->Update();

    for (const auto& b : _bullets)
        b->Update();

    // 플레이어 <-> 몬스터 충돌 처리

    bool headHitTotal = false;
    bool bodyHitTotal = false;

        for (const auto& m : _monster)
        {
            Vector v = _player->GetTransform()->GetWorldPos() - m->GetTransform()->GetWorldPos();
            Vector dir = v.UnitVector();
            m->GetTransform()->AddPos(dir * DELTA_TIME * 100.0f);

            bool headHit = _player->GetHeadCollider()->IsCollision(m->GetCollider());
            bool bodyHit = _player->GetBodyCollider()->IsCollision(m->GetCollider());

            // 플레이어 콜라이더 색상 처리

            if (headHit)
                headHitTotal = true;

            if (bodyHit)
                bodyHitTotal = true;
            

            if (headHit || bodyHit)
            {
                m->GetCollider()->SetRed();

                if (_hitTime > _dontHitTime)
                {
                    _player->HitByMonster(); // 데미지 처리
                    _hitTime = 0.0f;
                }
            }
            else
            {
                m->GetCollider()->SetGreen();
            }


            if (headHitTotal)
                _player->GetHeadCollider()->SetRed();
            else
                _player->GetHeadCollider()->SetGreen();

            if (bodyHitTotal)
                _player->GetBodyCollider()->SetRed();
            else
                _player->GetBodyCollider()->SetGreen();
        }

    // 총알 <-> 몬스터 충돌 처리
    for (const auto& b : _bullets)
    {
        bool hit = false;

        for (const auto& m : _monster)
        {
            if (b->GetCollider()->IsCollision(m->GetCollider()))
            {
                b->GetCollider()->SetRed();
                m->GetCollider()->SetRed(); // 맞은 몬스터 표시              
                hit = true;
            }
        }

        if (!hit)
            b->GetCollider()->SetGreen();
    }

    Input();
}

void Scene::Render()
{

    _backGround->Render();
    for (auto m : _monster)
        m->Render();
    _player->Render();

    _heart->Render();

    for (auto b : _bullets)
        b->Render();
}

void Scene::Input()
{
    if (KEY_DOWN(VK_UP) && _time >= _fireTime)
    {
        Vector dir = Vector(0, 1);

        auto noneActicveArrow = std::find_if(_bullets.begin(), _bullets.end(), [](shared_ptr<Bullet> bullet)-> bool
            {
                if (bullet->GetActive() == false)
                    return true;
                return false;
            });

        if (noneActicveArrow == _bullets.end())
            return;

        shared_ptr<Bullet> bullet = *noneActicveArrow;
        bullet->SetActive(true);
        bullet->SetPos(_player->GetHeadCollider()->GetWorldCenter() + Vector(0, -20));
        bullet->SetDir(dir);
        _time = 0.0f;
    }

    if (KEY_DOWN(VK_DOWN) && _time >= _fireTime)
    {
        Vector dir = Vector(0, -1);

        auto noneActicveArrow = std::find_if(_bullets.begin(), _bullets.end(), [](shared_ptr<Bullet> bullet)-> bool
            {
                if (bullet->GetActive() == false)
                    return true;
                return false;
            });

        if (noneActicveArrow == _bullets.end())
            return;

        shared_ptr<Bullet> bullet = *noneActicveArrow;
        bullet->SetActive(true);
        bullet->SetPos(_player->GetHeadCollider()->GetWorldCenter() + Vector(0, -20));
        bullet->SetDir(dir);

        _time = 0.0f;
    }

    if (KEY_DOWN(VK_LEFT) && _time >= _fireTime)
    {
        Vector dir = Vector(-1, 0);

        auto noneActicveArrow = std::find_if(_bullets.begin(), _bullets.end(), [](shared_ptr<Bullet> bullet)-> bool
            {
                if (bullet->GetActive() == false)
                    return true;
                return false;
            });

        if (noneActicveArrow == _bullets.end())
            return;

        shared_ptr<Bullet> bullet = *noneActicveArrow;
        bullet->SetActive(true);
        bullet->SetPos(_player->GetHeadCollider()->GetWorldCenter() + Vector(0, -20));
        bullet->SetDir(dir);

        _time = 0.0f;
    }

    if (KEY_DOWN(VK_RIGHT) && _time >= _fireTime)
    {
        Vector dir = Vector(1, 0);

        auto noneActicveArrow = std::find_if(_bullets.begin(), _bullets.end(), [](shared_ptr<Bullet> bullet)-> bool
            {
                if (bullet->GetActive() == false)
                    return true;
                return false;
            });

        if (noneActicveArrow == _bullets.end())
            return;

        shared_ptr<Bullet> bullet = *noneActicveArrow;
        bullet->SetActive(true);
        bullet->SetPos(_player->GetHeadCollider()->GetWorldCenter() + Vector(0, -20));
        bullet->SetDir(dir);

        _time = 0.0f;
    }
}
