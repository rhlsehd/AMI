#pragma once
class Player
{   
public:
    Player();
    ~Player();

    void Update();
    void Render();

    void Input();

    int GetHp() { return _hp; }
    int GetAtk() { return _atk; }

    void HitByMonster();

    shared_ptr<CircleCollider> GetHeadCollider() { return _playerHeadCol; }
    shared_ptr<CircleCollider> GetBodyCollider() { return _playerBodyCol; }

    shared_ptr<Transform> GetTransform() { return _transform; }
private:
    enum Direction
    {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    shared_ptr<GameObject> _player;

    // 애니메이션
    unordered_map<int, shared_ptr<GameObject>> _playerAni;
    unordered_map<int ,vector<shared_ptr<GameObject>>> _walkFrame;

    shared_ptr<Transform> _transform;

    shared_ptr<CircleCollider> _playerHeadCol; // player 콜라이더
    shared_ptr<CircleCollider> _playerBodyCol;

    int _currentDir = 1;
    Direction _dir = DOWN;

    
    float _speed = 300.0f;


    int _frameIndex = 0;
    float _aniTimer = 0.0f;
    const float _aniSpeed = 0.15f;


    bool _isMoving = false;
    bool _isPress = false;

    int _hp;
    int _atk;
};

