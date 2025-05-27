#pragma once
class Monster
{
public:
    Monster();
    ~Monster();

    void Update();
    void Render();

    int GetHp() { return _hp; }
    void HitbyPlayer(const  shared_ptr<Player>& player);
    void SetPos(Vector pos);

    shared_ptr<CircleCollider> GetCollider() { return _monsterCol; }
    shared_ptr<Transform> GetTransform() { return _transform; }

private:
    shared_ptr<GameObject> _monster;
    shared_ptr<CircleCollider> _monsterCol;

    shared_ptr<Transform> _transform;

    int _hp = 100;
};

