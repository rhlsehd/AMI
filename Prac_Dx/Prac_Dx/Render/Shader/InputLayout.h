#pragma once

#include "Vertex.h"

class InputLayout
{
public:
    InputLayout(shared_ptr<class VertexShader> vertexShader);
    ~InputLayout();

    void IASetInputLayout();

private:
    Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayOut; // ���� �������� ������ �����ϴ� ����, �� ������ ���� ������ ����(��ġ, ����) ���� GPU���� ����, �긦 ���� GPU�� ������ ��� �׸��� �� �� ����
    shared_ptr<class VertexShader> vertex;
};

