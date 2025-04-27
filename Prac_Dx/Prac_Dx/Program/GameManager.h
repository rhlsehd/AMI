#pragma once
class GameManager // °ÔÀÓ Èå¸§À» ÃÑ°ıÇÏ´Â Å¬·¡½º
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

    void Init();
    void Update();
    void Render();

    static GameManager* GetInstance() { return _instance; }
private:
    GameManager();
    ~GameManager();

    static GameManager* _instance;
      
    shared_ptr<MatrixBuffer> _world;
    shared_ptr<MatrixBuffer> _view;
    shared_ptr<MatrixBuffer> _projection;

    shared_ptr<GameObject> Isaac;
};

