#pragma once

#include "Vertex.h"

class InputLayout
{
public:
    InputLayout(shared_ptr<class VertexShader> vertexShader);
    ~InputLayout();

    void IASetInputLayout();

private:
    Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayOut; // 정점 데이터의 형식을 정의하는 설명서, 각 정점이 가진 데이터 형태(위치, 색상) 등을 GPU에게 설명, 얘를 통해 GPU가 무엇을 어떻게 그릴지 알 수 있음
    shared_ptr<class VertexShader> vertex;
};

