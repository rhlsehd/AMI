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
    DC->IASetVertexBuffers(slot, 1, vertexBuffer.GetAddressOf(), &_stride, &_offset); // <- ����(Vertex) �����͸� GPU�� �����ͼ�, ���� ���̴��� �Ѱ��ִ� ������ ��.
    //  DC->IASetVertexBuffers(���۸� ������ ���� ��ȣ (���� 0), ������ ���� ����, ���� ���� ������, �� ������ ũ�� (stride), ���� ���� ������)
}

void VertexBuffer::CreateVertexBuffer()
{
    // VertexBuffer ����
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(Vertex) * _count; // <- ���۸� �Ҵ��� �� �ʿ��� �޸� ũ�⸦ ����, ���ۿ� ������ �������� �� ũ�⸦ �����ϰ�, �޸𸮸� �ùٸ��� �Ҵ��� �� �ֵ��� �����ݴϴ�.
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = _data;

    DEVICE->CreateBuffer(&bd, &initData, vertexBuffer.GetAddressOf());
}


