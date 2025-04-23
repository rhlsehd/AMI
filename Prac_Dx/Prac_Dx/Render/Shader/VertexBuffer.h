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
    Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer; // 정점의 정보를 담아두는 공간

    void*       _data; // 정점 데이터 포인터 (어떤 구조체든 받을 수 있게 void*로 만듦)
    UINT		_count; // 정점 하나의 크기 (바이트 단위)
    UINT		_stride; // 정점 개수 (총 몇 개의 정점이 있는지)
    UINT		_offset; // 버퍼의 시작 위치 (기본값 0)
};

