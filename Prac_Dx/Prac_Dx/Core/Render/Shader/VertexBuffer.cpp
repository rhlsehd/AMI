#include "framework.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(void* data, UINT stride, UINT count, UINT offset)
: _data(data)
, _stride(stride)
, _count(count)
, _offset(offset)
{
    CreateVertexBuffer();
}

VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::IASet(int slot)
{
    DC->IASetVertexBuffers(slot, 1, vertexBuffer.GetAddressOf(), &_stride, &_offset); // <- 정점(Vertex) 데이터를 GPU로 가져와서, 정점 셰이더로 넘겨주는 역할을 함.
    //  DC->IASetVertexBuffers(버퍼를 시작할 슬롯 번호 (보통 0), 설정할 버퍼 개수, 정점 버퍼 포인터, 각 정점의 크기 (stride), 버퍼 시작 오프셋)
}

void VertexBuffer::CreateVertexBuffer()
{
    // VertexBuffer 세팅
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(Vertex) * _count; // <- 버퍼를 할당할 때 필요한 메모리 크기를 설정, 버퍼에 저장할 데이터의 총 크기를 지정하고, 메모리를 올바르게 할당할 수 있도록 도와줍니다.
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = _data;

    DEVICE->CreateBuffer(&bd, &initData, vertexBuffer.GetAddressOf());
}


