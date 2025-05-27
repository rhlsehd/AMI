#pragma once
class Heart
{
public:
    Heart();
    ~Heart();

    void Update();
    void Render();

    void SetPlayer(shared_ptr<Player> player) { _player = player; }

private:
    vector<shared_ptr<GameObject>> _heart;
    shared_ptr<Player> _player;
};

