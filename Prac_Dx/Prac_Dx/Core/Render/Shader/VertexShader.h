#pragma once
class VertexShader
{
public:

    VertexShader(wstring file);
    ~VertexShader();

    void SetVS();
    Microsoft::WRL::ComPtr<ID3DBlob> GetBlob() { return vertexBlob; }
    void CreateVertexShader();
private:
    void CreateBlob(wstring file);
    Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
    Microsoft::WRL::ComPtr<ID3DBlob> vertexBlob;
};

