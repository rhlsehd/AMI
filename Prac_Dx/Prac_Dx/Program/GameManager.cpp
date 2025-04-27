#include "framework.h"
#include "GameManager.h"
GameManager* GameManager::_instance = nullptr;

void GameManager::Init()
{
    
}

void GameManager::Update()
{
    /*  ?? �Է� ó��	Ű����, ���콺 �Է� �ޱ� <- �̱�������
        ?? ���� ���� ó��	�÷��̾� ��ġ �̵�, �� AI ������Ʈ ��
        ? �ð� ��� ������Ʈ	deltaTime ����ؼ� ������ �ε巴�� <- �̱�������
        ?? �ִϸ��̼�	������ ��ȯ, Ÿ�̸� üũ
        ?? �浹 ó��	AABB, �� �浹 ��
        ?? ���ҽ� ����	�ؽ�ó ����, ���� ��ȯ ��*/
    Isaac->GetTransform()->AddPos(Vector(1, 0));
    Isaac->Update();
}

void GameManager::Render()
{
     float clearColor[] = { 1.0f ,1.0f ,1.0f ,1.0f };

     DC->ClearRenderTargetView(Device::GetInstance()->GetRTV().Get(), clearColor); //���� Ÿ���� �����ִ� ����. 
     // ��, ȭ���� ���� �׸��� ���� ���� �������� �׸��� ���� �����.
     
     DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST); // GPU�� ����(Vertex)�� ��� �����ؼ� ������ �������� �������ִ� ���
     // D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST�� 3���� ������ �ϳ��� �ﰢ������ �ν��ؼ� �׸��ڴٴ� ��;
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

    //�� ���: �׳� ���� ��ķ�
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
