#pragma once
class GameManager
{
public:
    static void Create()
    {
        if (_instance == nullptr)
            _instance = new GameManager();
    }

    static void Delete()
    {
        if (_instance != nullptr)
            delete _instance;
    }

    static void Update();
    static void Render();

    static GameManager* GetInstance() { return _instance; }
private:
    GameManager();
    ~GameManager();

    static GameManager* _instance;
};

