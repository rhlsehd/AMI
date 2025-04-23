#include "framework.h"
#include "GameManager.h"
GameManager* GameManager::_instance = nullptr;

void GameManager::Init()
{

    Vertex vertices[6] = { {-0.5f,0.5f}, {0.5f, -0.5f}, {-0.5f, -0.5f}, {-0.5f,0.5f}, {0.5f,0.5f }, { 0.5f,-0.5f } };

    vertices[0].color = { 1,0,0,1 };
    vertices[1].color = { 0,1,0,1 };
    vertices[2].color = { 0,0,1,1 };
    vertices[3].color = { 0,0,1,1 };
    vertices[4].color = { 0,1,0,1 };
    vertices[5].color = { 1,0,0,1 };

    UINT stride = sizeof(Vertex);
    UINT count = 6;

    vertexShader = make_shared<class VertexShader>(L"Shader/VertexShader.hlsl");
    vertexBuffer = make_shared<class VertexBuffer>(vertices,stride,count);
    inputLayout = make_shared<class InputLayout>(vertexShader);
    pixelShader = make_shared<class PixelShader>(L"Shader/PixelShader.hlsl");
}

void GameManager::Update()
{
}

void GameManager::Render()
{
     float clearColor[] = { 1.0f ,1.0f ,1.0f ,1.0f };

     DC->ClearRenderTargetView(Device::GetInstance()->GetRTV().Get(), clearColor);

     DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

     DC->Draw(6, 0);

     Device::GetInstance()->GetSwapChain()->Present(0, 0);

     vertexShader->SetVS();
     vertexBuffer->IASet(0);
     inputLayout->IASetInputLayout();
     pixelShader->SetPs();
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}
