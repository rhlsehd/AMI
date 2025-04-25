#pragma once
class PixelShader
{
public:
    PixelShader(wstring file);
    ~PixelShader();

    void SetPs();
    Microsoft::WRL::ComPtr<ID3DBlob> GetBlob() { return pixelBlob; }
    void CreatePixelShader();
private:
    void CreateBlob(wstring file);
    Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader; // 픽셀 데이터를 처리하는 셰이더, GPU에서 실행되어 픽셀 색상을 계산하는 셰이더 프로그램
    Microsoft::WRL::ComPtr<ID3DBlob> pixelBlob;

    shared_ptr<class Texture> texture;
};

