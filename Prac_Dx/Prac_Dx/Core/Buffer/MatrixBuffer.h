#pragma once

class MatrixBuffer : public ConstantBuffer
{
public:
    struct Data
    {
        XMMATRIX matrix = XMMatrixIdentity();
    };

    MatrixBuffer() : ConstantBuffer(&_data, sizeof(Data)) {}
    ~MatrixBuffer() {}

    void SetData(XMMATRIX value)
    {
        // DirectX�� ��İ�� ������
        _data.matrix = XMMatrixTranspose(value);
    }

private:
    Data _data;
};