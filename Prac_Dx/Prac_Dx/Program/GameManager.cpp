#include "framework.h"
#include "GameManager.h"
GameManager* GameManager::_instance = nullptr;

void GameManager::Init()
{
    
    vertices = {
        // ù��° �ﰢ��_halfSize.y
    { XMFLOAT3(-0.5f, 0.5f, 0.0f), XMFLOAT2(0, 0) },   // ���� ��
    { XMFLOAT3(0.5f, -0.5f, 0.0f), XMFLOAT2(1, 1) },  // ������ �Ʒ�
    { XMFLOAT3(-0.5f, -0.5f, 0.0f), XMFLOAT2(0, 1) },  // ���� �Ʒ�

    // �� ��° �ﰢ��
    { XMFLOAT3(-0.5f, 0.5f, 0.0f), XMFLOAT2(0, 0) },   // ���� ��
    { XMFLOAT3(0.5f, 0.5f, 0.0f), XMFLOAT2(1, 0) },   // ������ ��
    { XMFLOAT3(0.5f, -0.5f, 0.0f), XMFLOAT2(1, 1) }   // ������ �Ʒ�
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
    /*  ?? �Է� ó��	Ű����, ���콺 �Է� �ޱ� <- �̱�������
        ?? ���� ���� ó��	�÷��̾� ��ġ �̵�, �� AI ������Ʈ ��
        ? �ð� ��� ������Ʈ	deltaTime ����ؼ� ������ �ε巴�� <- �̱�������
        ?? �ִϸ��̼�	������ ��ȯ, Ÿ�̸� üũ
        ?? �浹 ó��	AABB, �� �浹 ��
        ?? ���ҽ� ����	�ؽ�ó ����, ���� ��ȯ ��*/
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
