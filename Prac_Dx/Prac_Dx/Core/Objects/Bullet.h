#pragma once
class Bullet
{
public:
    Bullet();
    ~Bullet();

    void Update();
    void Render();

    void SetDir(Vector dir);    
    void SetPos(Vector pos);
    void SetAngle(float angle) { _bullet->GetTransform()->SetAngle(angle); }
    void SetActive(bool active) { _isActive = active; }
    bool GetActive() { return _isActive; }

    shared_ptr<CircleCollider> GetCollider() { return _bulletCol; }
private:
    float _lifeTime = 3.0f;
    float _time = 0.0f;

    bool _isActive = false;

    Vector _bulletDir = Vector(0, 0);

    shared_ptr<GameObject> _bullet;
    shared_ptr<CircleCollider> _bulletCol;
};

