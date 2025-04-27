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
    _inputLayout->IASetInputLayout();           // 정점 데이터 해석 방법 지정
    _vertexBuffer->IASet(0);                    // 실제 정점 데이터 연결

    _vertexShader->SetVS();                     // 셰이더 연결
    _pixelShader->SetPs();                      // 픽셀 셰이더 연결
    
    _transform->SetVS(0);
    _texture->PSSet(0);                          // 이미지(텍스처)를 픽셀 셰이더에 연결해주는 것, 즉 텍스처를 GPU의 셰이더 리소스로 바인딩하는 역할  

    DC->Draw(6, 0);
}

void GameObject::CreateVertices()
{
    _vertices = {
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

    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size(), 0);
    _inputLayout = make_shared<InputLayout>(_vertexShader);
}

void GameObject::CreateMeterial(wstring file)
{
    _vertexShader = make_shared<VertexShader>(L"Shader/VertexShader.hlsl");
    _pixelShader = make_shared<PixelShader>(L"Shader/PixelShader.hlsl");
    _texture = make_shared<Texture>(file);
}
