#pragma once

#include "Vertex.h"

class VertexBuffer
{
public:
    VertexBuffer(void* data, UINT stride, UINT count, UINT offset = 0);
    ~VertexBuffer();

    void CreateVertexBuffer(); 
    void IASet(int slot);

private:
    Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer; // ������ ������ ��Ƶδ� ����

    void*       _data; // ���� ������ ������ (� ����ü�� ���� �� �ְ� void*�� ����)
    UINT		_count; // ���� �ϳ��� ũ�� (����Ʈ ����)
    UINT		_stride; // ���� ���� (�� �� ���� ������ �ִ���)
    UINT		_offset; // ������ ���� ��ġ (�⺻�� 0)
};

