#include "framework.h"
#include "GameManager.h"
GameManager* GameManager::_instance = nullptr;

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
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}
