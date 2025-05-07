#pragma once
class Monster
{
public:
    Monster();
    ~Monster();

    void Update();
    void Render();

private:
    shared_ptr<GameObject> _monster;
};

