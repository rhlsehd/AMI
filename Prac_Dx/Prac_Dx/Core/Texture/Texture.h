#pragma once
class Texture
{
public:
    Texture(wstring file);   // 파일에서 텍스처 로드
    ~Texture();

    void PSSet(UINT slot = 0);  // PixelShader에 텍스처 & 샘플러 바인딩
    
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> GetSRV() { return _srv; }
    Microsoft::WRL::ComPtr<ID3D11SamplerState> GetSampler() { return _sampler; }

    Vector GetImageSize();
private:

    void CreateSRV(wstring file);
    void CreateSampler();

    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> _srv;   // 실제 텍스처 데이터
    Microsoft::WRL::ComPtr<ID3D11SamplerState> _sampler;     // 샘플링 상태
    ScratchImage image; // <- 이미지 데이터를 CPU 메모리에 임시 저장할 수 있게 도와주는 도우미 클래스
    // GPU에 올리기 전에 이미지 데이터 가공/검사할 때 유용, 다양한 포맷, 크기, 채널을 가진 텍스처를 임시로 들고 있음

    
};

