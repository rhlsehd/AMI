#include "framework.h"
#include "GameManager.h"
GameManager* GameManager::_instance = nullptr;

void GameManager::Init()
{
    
}

void GameManager::Update()
{
    /*  ?? 입력 처리	키보드, 마우스 입력 받기 <- 싱글톤패턴
        ?? 게임 로직 처리	플레이어 위치 이동, 적 AI 업데이트 등
        ? 시간 기반 업데이트	deltaTime 사용해서 움직임 부드럽게 <- 싱글톤패턴
        ?? 애니메이션	프레임 전환, 타이머 체크
        ?? 충돌 처리	AABB, 원 충돌 등
        ?? 리소스 관리	텍스처 변경, 상태 전환 등*/
    Isaac->GetTransform()->AddPos(Vector(1, 0));
    Isaac->Update();
}

void GameManager::Render()
{
     float clearColor[] = { 1.0f ,1.0f ,1.0f ,1.0f };

     DC->ClearRenderTargetView(Device::GetInstance()->GetRTV().Get(), clearColor); //렌더 타겟을 지워주는 역할. 
     // 즉, 화면을 새로 그리기 전에 이전 프레임의 그림을 전부 지운다.
     
     DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST); // GPU가 정점(Vertex)을 어떻게 조합해서 도형을 만들지를 지정해주는 명령
     // D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST는 3개의 정점을 하나의 삼각형으로 인식해서 그리겠다는 뜻;
     _view->SetVS(1);
     _projection->SetVS(2);


     Isaac->GetTransform()->SetVS(0);
     Isaac->Render();
    
     Device::GetInstance()->GetSwapChain()->Present(0, 0);
}

GameManager::GameManager()
{
    Isaac = make_shared<GameObject>(L"Resource/Isaac.png");
    Isaac->GetTransform()->SetPos(Vector(WIN_WIDTH / 2.0f, WIN_HEIGHT / 2.0f));
    Isaac->GetTransform()->SetScale(Vector(150, 150));

    _view = make_shared<MatrixBuffer>();
    _projection = make_shared<MatrixBuffer>();

    //뷰 행렬: 그냥 단위 행렬로
    XMMATRIX viewMatrix = XMMatrixIdentity();
    _view->SetData(viewMatrix);
    _view->Update();

    XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0, 1.0f);
    _projection->SetData(projectionM);
    _projection->Update();
}

GameManager::~GameManager()
{
}
