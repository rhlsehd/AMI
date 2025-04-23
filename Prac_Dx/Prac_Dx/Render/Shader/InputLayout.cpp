#include "framework.h"
#include "InputLayout.h"

InputLayout::InputLayout(shared_ptr<class VertexShader> vertexShader)
{
    this->vertex = vertexShader;
    
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        {
            "POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,
            D3D11_INPUT_PER_VERTEX_DATA,0
        },

        {
            "COLOR",0,DXGI_FORMAT_R32G32B32A32_FLOAT,0,12,
            D3D11_INPUT_PER_VERTEX_DATA,0
        }
    };

    UINT layoutSize = ARRAYSIZE(layout);

    if (vertex)
    {
        DEVICE->CreateInputLayout(layout, layoutSize, vertex->GetBlob()->GetBufferPointer(), vertex->GetBlob()->GetBufferSize(), inputLayOut.GetAddressOf());
    }

    IASetInputLayout(); // <- �Է� ���̾ƿ� ������ gpu�� �����͸� ��� �ؼ����� �˷��ִ� �ܰ� 
    // �׷��� ������ CreateInputLayout ��������� gpu�� ������ �������!!!!
}

InputLayout::~InputLayout()
{
}

void InputLayout::IASetInputLayout()
{
    DC->IASetInputLayout(inputLayOut.Get());
}
