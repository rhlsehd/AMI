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
    Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader; // �ȼ� �����͸� ó���ϴ� ���̴�, GPU���� ����Ǿ� �ȼ� ������ ����ϴ� ���̴� ���α׷�
    Microsoft::WRL::ComPtr<ID3DBlob> pixelBlob;

    shared_ptr<class Texture> texture;
};

