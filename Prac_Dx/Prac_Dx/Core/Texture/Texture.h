#pragma once
class Texture
{
public:
    Texture(wstring file);   // ���Ͽ��� �ؽ�ó �ε�
    ~Texture();

    void PSSet(UINT slot = 0);  // PixelShader�� �ؽ�ó & ���÷� ���ε�
    
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> GetSRV() { return _srv; }
    Microsoft::WRL::ComPtr<ID3D11SamplerState> GetSampler() { return _sampler; }

    Vector GetImageSize();
private:

    void CreateSRV(wstring file);
    void CreateSampler();

    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> _srv;   // ���� �ؽ�ó ������
    Microsoft::WRL::ComPtr<ID3D11SamplerState> _sampler;     // ���ø� ����
    ScratchImage image; // <- �̹��� �����͸� CPU �޸𸮿� �ӽ� ������ �� �ְ� �����ִ� ����� Ŭ����
    // GPU�� �ø��� ���� �̹��� ������ ����/�˻��� �� ����, �پ��� ����, ũ��, ä���� ���� �ؽ�ó�� �ӽ÷� ��� ����

    
};

