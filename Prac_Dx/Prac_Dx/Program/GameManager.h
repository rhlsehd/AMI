#pragma once

#include "Core/Render/Shader/InputLayout.h"
#include "Core/Render/Shader/VertexBuffer.h"
#include "Core/Render/Shader/VertexShader.h"
#include "Core/Render/Shader/PixelShader.h"
#include "Core/Texture/Texture.h"

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

    void Init();
    void Update();
    void Render();

    static GameManager* GetInstance() { return _instance; }
private:
    GameManager();
    ~GameManager();

    static GameManager* _instance;
        
    shared_ptr<class VertexShader> vertexShader;
    shared_ptr<class VertexBuffer> vertexBuffer;
    shared_ptr<class InputLayout> inputLayout;
    shared_ptr<class PixelShader> pixelShader;

    vector<Vertex> vertices;
};

