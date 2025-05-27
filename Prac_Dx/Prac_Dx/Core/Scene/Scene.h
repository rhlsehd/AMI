#pragma once
class Scene
{
public:
    Scene();
    ~Scene();

    void Update();
    void Render();

    void Input();

private:
    shared_ptr<GameObject> _backGround;
    shared_ptr<Player> _player;
    vector<shared_ptr<Monster>> _monster;
    shared_ptr<Heart> _heart;

    vector<shared_ptr<Bullet>> _bullets;

    float _time = 0.0f;
    float _fireTime = 0.2f;

    float _hitTime = 0.0f;
    float _dontHitTime = 1.0f;
};

