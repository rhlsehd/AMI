#include "framework.h"
#include "PixelShader.h"

PixelShader::PixelShader(wstring file)
{
    CreateBlob(file);
    CreatePixelShader();

}

PixelShader::~PixelShader()
{
}

void PixelShader::SetPs()
{
    DC->PSSetShader(pixelShader.Get(), nullptr, 0); 
}

void PixelShader::CreatePixelShader()
{
    DEVICE->CreatePixelShader(pixelBlob->GetBufferPointer(), pixelBlob->GetBufferSize(), nullptr, IN pixelShader.GetAddressOf());
}

void PixelShader::CreateBlob(wstring file)
{
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
    D3DCompileFromFile(L"Shader/PixelShader.hlsl", nullptr, nullptr, "PS", "ps_5_0", flags, 0, pixelBlob.GetAddressOf(), nullptr);
}
