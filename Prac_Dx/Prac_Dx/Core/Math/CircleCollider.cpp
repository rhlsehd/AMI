#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
    :_radius(radius)
{
    CreateMesh();
    CreateMaterial();

    _transform = make_shared<Transform>();
    _transform->SetPos(center);
    _colorBuffer = make_shared<ColorBuffer>();
    SetGreen();
}

void CircleCollider::Update()
{
    _transform->Update();
    _colorBuffer->Update();

}

void CircleCollider::Render()
{
    _inputLayout->IASetInputLayout(); // IA(Input Assembler) 단계에서 사용할 입력 레이아웃을 설정. 
    //입력 레이아웃은 VertexShader에서 받을 데이터(위치, 색상등) 의 구조를 설명, ex) POSITION, TEXCOORD 같은 요소들이 어디에 있는지 GPU에게 설명

    _transform->SetVS(0); // _transform에 있는 내용을 0번 슬롯에 바인딩
    _colorBuffer->SetPS(0);

    _vertexBuffer->IASet(0); // 정점버퍼 슬롯 0번에 바인딩

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP); // 정점들을 어떤 방식으로 연결해서 그릴지를 지정. LINESTRIP은 각 정점을 선으로 이어그리되, 연속된 선분으로 처리

    _vs->SetVS(); // 버텍스셰이더 바인딩
    _ps->SetPs(); // 픽셀셰이더 바인딩

    DC->Draw(_vertices.size(), 0); // 렌더링 명령 GPU에 전달
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
    Vector v = other->GetWorldCenter() - GetWorldCenter();
    return v.Length() < GetWorldRadius() + other->GetWorldRadius(); // 두 원사이의 거리가 두 원 반지름 합보다 작으면 충돌
}

void CircleCollider::SetRed()
{
    _colorBuffer->SetData(XMFLOAT4(1, 0, 0, 1));
}

void CircleCollider::SetGreen()
{
    _colorBuffer->SetData(XMFLOAT4(0, 1, 0, 1));
}

void CircleCollider::CreateMesh()
{
    int verticesCount = 36;
    float theta = 2 * PI / verticesCount; // 2PI / 36 = 10 -> 10도마다 정점 하나를 찍겠다. -> 총 36개의 정점

    for (int i = 0; i < verticesCount + 1; i++) // verticesCount + 1 인 이유는 마지막 점이 처음 점과 동일해야 원이 제대로 만들어지기 때문
    {
        Vertex v;
        v.pos.x = _radius * cosf(theta * i);
        v.pos.y = _radius * sinf(theta * i);
        v.pos.z = 0.0f;

        _vertices.push_back(v);
    }

    _vertexBuffer = make_shared<VertexBuffer>(&_vertices[0], sizeof(Vertex), _vertices.size(), 0);

}

void CircleCollider::CreateMaterial()
{
    _vs = make_shared<VertexShader>(L"Shader/ColVertexShader.hlsl");
    _ps = make_shared<PixelShader>(L"Shader/ColPixelShader.hlsl");

    _inputLayout = make_shared<InputLayout>(_vs);
}
