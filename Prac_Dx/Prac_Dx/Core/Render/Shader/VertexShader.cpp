#include "framework.h"
#include "VertexShader.h"

VertexShader::VertexShader(wstring file)
{
    CreateBlob(file);
    CreateVertexShader();
}

VertexShader::~VertexShader()
{
}

void VertexShader::SetVS()
{
    DC->VSSetShader(vertexShader.Get(), nullptr, 0);
}

void VertexShader::CreateVertexShader()
{
    DEVICE->CreateVertexShader(vertexBlob->GetBufferPointer(), vertexBlob->GetBufferSize(), nullptr, IN vertexShader.GetAddressOf());
}

void VertexShader::CreateBlob(wstring file)
{
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
    D3DCompileFromFile(file.c_str(), nullptr, nullptr,  /* 진입점 이름 */"VS", "vs_5_0", flags, 0, vertexBlob.GetAddressOf(), nullptr);
}
