#include "framework.h"
#include "GameObject.h"

GameObject::GameObject(wstring file)
{

    CreateMeterial(file);
    CreateVertices();
    _transform = make_shared<Transform>();
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
    _transform->Update();
}

void GameObject::Render()
{
    _inputLayout->IASetInputLayout();           // ���� ������ �ؼ� ��� ����
    _vertexBuffer->IASet(0);                    // ���� ���� ������ ����

    _vertexShader->SetVS();                     // ���̴� ����
    _pixelShader->SetPs();                      // �ȼ� ���̴� ����
    
    _transform->SetVS(0);
    _texture->PSSet(0);                          // �̹���(�ؽ�ó)�� �ȼ� ���̴��� �������ִ� ��, �� �ؽ�ó�� GPU�� ���̴� ���ҽ��� ���ε��ϴ� ����  

    DC->Draw(6, 0);
}

void GameObject::CreateVertices()
{
    _vertices = {
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

    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size(), 0);
    _inputLayout = make_shared<InputLayout>(_vertexShader);
}

void GameObject::CreateMeterial(wstring file)
{
    _vertexShader = make_shared<VertexShader>(L"Shader/VertexShader.hlsl");
    _pixelShader = make_shared<PixelShader>(L"Shader/PixelShader.hlsl");
    _texture = make_shared<Texture>(file);
}
