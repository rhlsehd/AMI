#pragma once

#include "Render/Shader/InputLayout.h"
#include "Render/Shader/VertexBuffer.h"
#include "Render/Shader/VertexShader.h"
#include "Render/Shader/PixelShader.h"

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

    static void Init();
    static void Update();
    static void Render();

    static GameManager* GetInstance() { return _instance; }
private:
    GameManager();
    ~GameManager();

    static GameManager* _instance;
        
    static shared_ptr<class VertexShader> vertexShader;
    static shared_ptr<class VertexBuffer> vertexBuffer;
    static shared_ptr<class InputLayout> inputLayout;
    static shared_ptr<class PixelShader> pixelShader;
};

