#include "framework.h"
#include "ConstantBuffer.h"

ConstantBuffer::ConstantBuffer(void* data, UINT dataSize)
    :_data(data), _dataSize(dataSize)
{
    D3D11_BUFFER_DESC bd = {}; // Direct3D의 버퍼 설명 구조체를 생성하고 0으로 초기화.
    bd.Usage = D3D11_USAGE_DEFAULT; // GPU가 주로 사용하는 버퍼
    bd.ByteWidth = dataSize; // 버퍼 크기 설정
    bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER; // 상수버퍼 초기값 설정, CPU에 있는 _data 내용을 초기 데이터로 사용

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = _data;

    DEVICE->CreateBuffer(&bd, &initData, _buffer.GetAddressOf());
}

ConstantBuffer::~ConstantBuffer()
{
}

void ConstantBuffer::Update() // 상수버퍼를 업데이트하여 gpu에 전달하는 역할 
{
    DC->UpdateSubresource(_buffer.Get(), 0, nullptr, _data, 0, 0);
}

void ConstantBuffer::SetVS(UINT slot) // 버텍스셰이더에 상수버퍼를 전달하는 역할
{
    DC->VSSetConstantBuffers(slot, 1, _buffer.GetAddressOf());
}

void ConstantBuffer::SetPS(UINT slot) // 픽셀셰이더에 상수버퍼를 전달하는 역할
{
    DC->PSSetConstantBuffers(slot, 1, _buffer.GetAddressOf());
}
