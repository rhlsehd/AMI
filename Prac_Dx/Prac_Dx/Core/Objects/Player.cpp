#include "framework.h"
#include "Player.h"

Player::Player()
    :_hp(3), _atk(10)
{
    _player = make_shared<GameObject>(L"Resource/Isaac.png");
    _transform = make_shared<Transform>();

    _playerAni[UP] = make_shared<GameObject>(L"Resource/up_head.png");
    _playerAni[DOWN] = make_shared<GameObject>(L"Resource/down_head.png");
    _playerAni[RIGHT] = make_shared<GameObject>(L"Resource/right_head.png");
    _playerAni[LEFT] = make_shared<GameObject>(L"Resource/left_head.png");

    _walkFrame[DOWN] = {
        make_shared<GameObject>(L"Resource/walk1.png"),
        make_shared<GameObject>(L"Resource/walk2.png"),
        make_shared<GameObject>(L"Resource/walk3.png")
    };

    _walkFrame[RIGHT] = {
        make_shared<GameObject>(L"Resource/side_walk1.png"),
        make_shared<GameObject>(L"Resource/side_walk2.png"),
        make_shared<GameObject>(L"Resource/side_walk3.png")
    };

    _walkFrame[LEFT] = _walkFrame[RIGHT]; // 반전 시키기
    _walkFrame[UP] = _walkFrame[DOWN];

    // LEFT 방향 프레임

    _player->GetTransform()->SetPos(Vector(WIN_WIDTH / 2.0f, WIN_HEIGHT / 2.0f));
    _player->GetTransform()->SetScale(Vector(150, 150));

    _playerHeadCol = make_shared<CircleCollider>(Vector(0.1f, 0.1f), 0.25f);
    _playerHeadCol->GetTransform()->SetParent(_player->GetTransform());
    _playerHeadCol->GetTransform()->SetPos(Vector(0, 13));  

    _playerBodyCol = make_shared<CircleCollider>(Vector(0.1f, 0.1f), 0.13f);
    _playerBodyCol->GetTransform()->SetParent(_player->GetTransform());
    _playerBodyCol->GetTransform()->SetPos(Vector(0, -35));
}

Player::~Player()
{
}

void Player::Update()
{
    _player->Update();
    _playerHeadCol->Update();
    _playerBodyCol->Update();
    _transform->Update();


    if (_isMoving)
    {
        _aniTimer += DELTA_TIME;
        if (_aniTimer >= _aniSpeed)
        {
            _aniTimer = 0.0f;
            _frameIndex = (_frameIndex + 1) % _walkFrame[_dir].size();
        }
    }
    
    else
    {
        _frameIndex = 0;
        _aniTimer = 0.0f;
    }

    
    
    Vector playerPos = _player->GetTransform()->GetWorldPos();

    if (_dir < 2)
    {
        _walkFrame[_dir][_frameIndex]->GetTransform()->SetPos(playerPos + Vector(0, -33));
        _walkFrame[_dir][_frameIndex]->GetTransform()->SetScale(Vector(68, 68));
        _walkFrame[_dir][_frameIndex]->Update();
    }

    else
    {
        _walkFrame[_dir][_frameIndex]->GetTransform()->SetPos(playerPos + Vector(0, -38));
        _walkFrame[_dir][_frameIndex]->GetTransform()->SetScale(Vector(70, 70));
        _walkFrame[_dir][_frameIndex]->Update();
    }
    
    

    for (int i = 0; i < 4; i++)
    {
        _playerAni[i]->GetTransform()->SetScale(Vector(110,125));
        _playerAni[i]->GetTransform()->SetPos(_player->GetTransform()->GetWorldPos() + Vector(0,12));
        _playerAni[i]->Update();
    }

    

    Input();

    Vector pos = _player->GetTransform()->GetLocalPos();

    float playerWidth = _player->GetTransform()->GetWorldScale().x;
    float playerHeight = _player->GetTransform()->GetWorldScale().y;

    pos.x = max(100.0f, min(pos.x, WIN_WIDTH - playerWidth + 50));
    pos.y = max(120.0f, min(pos.y, WIN_HEIGHT - playerHeight + 25));

    _player->GetTransform()->SetPos(pos);
}

void Player::Render()
{
    //_player->Render();
    _playerHeadCol->Render();
    _playerBodyCol->Render();

    _walkFrame[_currentDir][_frameIndex]->Render();

    _playerAni[_currentDir]->Render();
    

}

void Player::Input()
{ 
    _isMoving = false;
    
    if (KEY_PRESS('A'))
    {
        _player->GetTransform()->AddPos(Vector(-1, 0) * DELTA_TIME * _speed);
        _currentDir = LEFT;
        _dir = LEFT;
        _isMoving = true;
        _isPress = true;
    }
    if (KEY_PRESS('D'))
    {
        _player->GetTransform()->AddPos(Vector(1, 0) * DELTA_TIME * _speed);
        _currentDir = RIGHT;
        _dir = RIGHT;
        _isMoving = true;
        _isPress = true;
    }
    if (KEY_PRESS('W'))
    {
        _player->GetTransform()->AddPos(Vector(0, 1) * DELTA_TIME * _speed);
        _currentDir = UP;
        _dir = UP;
        _isMoving = true;
        _isPress = true;
    }
    if (KEY_PRESS('S'))
    {
        _player->GetTransform()->AddPos(Vector(0, -1) * DELTA_TIME * _speed);
        _currentDir = DOWN;
        _dir = DOWN;
        _isMoving = true;
        _isPress = true;
    }
    _isPress = false;
}

void Player::HitByMonster()
{
    if (_hp > 0)
        _hp--;
}
