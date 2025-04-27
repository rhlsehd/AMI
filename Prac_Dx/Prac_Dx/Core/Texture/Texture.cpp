#include "framework.h"
#include "Texture.h"
#include "Core/Math/Vector.h"
Texture::Texture(wstring file)
{
    CreateSRV(file);
    CreateSampler();
}

Texture::~Texture()
{
}

void Texture::PSSet(UINT slot)
{
    DC->PSSetShaderResources(slot, 1, _srv.GetAddressOf()); // 이 코드는 텍스처를 픽셀 셰이더의 특정 슬롯(예: t0)에 바인딩
    //_srv =  Shader Resource View (셰이더에서 사용할 수 있도록 만든 텍스처 뷰)
    DC->PSSetSamplers(slot, 1, _sampler.GetAddressOf()); // 샘플러 상태를 연결해주는 곳. 예를 들어 POINT 방식으로 픽셀을 샘플링할지, LINEAR로 부드럽게 보간할지 등을 결정
}



void Texture::CreateSRV(wstring path)
{
    HRESULT hr = LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE, nullptr, image);
    if (FAILED(hr)) {
        // 이미지 로드 실패시 처리
        MessageBox(nullptr, L"Failed to load image.", L"Error", MB_OK);
        return;
    }

    // 이미지가 정상적으로 로드되었을 경우
    hr = CreateShaderResourceView(DEVICE.Get(), image.GetImages(), image.GetImageCount(), image.GetMetadata(), _srv.GetAddressOf());
    if (FAILED(hr)) {
        // SRV 생성 실패시 처리
        MessageBox(nullptr, L"Failed to create Shader Resource View.", L"Error", MB_OK);
    }
}

void Texture::CreateSampler()
{
    D3D11_SAMPLER_DESC sampDesc = {};
    sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR; // 텍스텨 샘플링 방식. MIN: 텍스처가 축소될 때 (멀리서 볼 때) ,MAG: 텍스처가 확대될 때 (가까이서 볼 때)
    // MIP: Mipmap 사용 시 어떤 레벨을 가져올지, 현재 선언은 포인트 샘플링 상태 가장 가까운 텍셀 하나만 가져옴 (픽셀 단위 느낌, 도트 느낌)
    sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP; // AddressW 까지 텍스처 좌표(U, V, W)가 0~1 범위를 벗어났을 때 어떻게 처리할지를 지정하는 곳.
    sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    // WRAP은 텍스처를 반복해서 이어주는 방식
    sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    sampDesc.MinLOD = 0;
    sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

    DEVICE->CreateSamplerState(&sampDesc, _sampler.GetAddressOf());
}

Vector Texture::GetImageSize()
{
    return Vector(image.GetMetadata().width, image.GetMetadata().height);
}
