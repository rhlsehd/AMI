#include "framework.h"
#include "GameManager.h"
GameManager* GameManager::_instance = nullptr;

void GameManager::Init()
{
    
    vertices = {
        // 첫번째 삼각형_halfSize.y
    { XMFLOAT3(-0.5f, 0.5f, 0.0f), XMFLOAT2(0, 0) },   // 왼쪽 위
    { XMFLOAT3(0.5f, -0.5f, 0.0f), XMFLOAT2(1, 1) },  // 오른쪽 아래
    { XMFLOAT3(-0.5f, -0.5f, 0.0f), XMFLOAT2(0, 1) },  // 왼쪽 아래

    // 두 번째 삼각형
    { XMFLOAT3(-0.5f, 0.5f, 0.0f), XMFLOAT2(0, 0) },   // 왼쪽 위
    { XMFLOAT3(0.5f, 0.5f, 0.0f), XMFLOAT2(1, 0) },   // 오른쪽 위
    { XMFLOAT3(0.5f, -0.5f, 0.0f), XMFLOAT2(1, 1) }   // 오른쪽 아래
    };



    

    UINT stride = sizeof(Vertex);
    UINT count = 6;
    
    vertexBuffer = make_shared<VertexBuffer>(vertices.data(), sizeof(Vertex), vertices.size(), 0);
    vertexShader = make_shared<class VertexShader>(L"Shader/VertexShader.hlsl");
    inputLayout = make_shared<class InputLayout>(vertexShader);
    pixelShader = make_shared<class PixelShader>(L"Shader/PixelShader.hlsl");
    texture = make_shared<class Texture>(L"Resource/Isaac_character.jpeg");
   
}

void GameManager::Update()
{
    /*  ?? 입력 처리	키보드, 마우스 입력 받기 <- 싱글톤패턴
        ?? 게임 로직 처리	플레이어 위치 이동, 적 AI 업데이트 등
        ? 시간 기반 업데이트	deltaTime 사용해서 움직임 부드럽게 <- 싱글톤패턴
        ?? 애니메이션	프레임 전환, 타이머 체크
        ?? 충돌 처리	AABB, 원 충돌 등
        ?? 리소스 관리	텍스처 변경, 상태 전환 등*/
}

void GameManager::Render()
{
     float clearColor[] = { 0.0f ,0.0f ,0.0f ,1.0f };

     DC->ClearRenderTargetView(Device::GetInstance()->GetRTV().Get(), clearColor);
     DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

     vertexShader->SetVS();
     pixelShader->SetPs();
     texture->PSSet();

     inputLayout->IASetInputLayout();
     vertexBuffer->IASet(0);
     

     DC->Draw(6, 0);

     Device::GetInstance()->GetSwapChain()->Present(0, 0);
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}
