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
    DC->PSSetShaderResources(slot, 1, _srv.GetAddressOf()); // �� �ڵ�� �ؽ�ó�� �ȼ� ���̴��� Ư�� ����(��: t0)�� ���ε�
    //_srv =  Shader Resource View (���̴����� ����� �� �ֵ��� ���� �ؽ�ó ��)
    DC->PSSetSamplers(slot, 1, _sampler.GetAddressOf()); // ���÷� ���¸� �������ִ� ��. ���� ��� POINT ������� �ȼ��� ���ø�����, LINEAR�� �ε巴�� �������� ���� ����
}



void Texture::CreateSRV(wstring path)
{
    HRESULT hr = LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE, nullptr, image);
    if (FAILED(hr)) {
        // �̹��� �ε� ���н� ó��
        MessageBox(nullptr, L"Failed to load image.", L"Error", MB_OK);
        return;
    }

    // �̹����� ���������� �ε�Ǿ��� ���
    hr = CreateShaderResourceView(DEVICE.Get(), image.GetImages(), image.GetImageCount(), image.GetMetadata(), _srv.GetAddressOf());
    if (FAILED(hr)) {
        // SRV ���� ���н� ó��
        MessageBox(nullptr, L"Failed to create Shader Resource View.", L"Error", MB_OK);
    }
}

void Texture::CreateSampler()
{
    D3D11_SAMPLER_DESC sampDesc = {};
    sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR; // �ؽ��� ���ø� ���. MIN: �ؽ�ó�� ��ҵ� �� (�ָ��� �� ��) ,MAG: �ؽ�ó�� Ȯ��� �� (�����̼� �� ��)
    // MIP: Mipmap ��� �� � ������ ��������, ���� ������ ����Ʈ ���ø� ���� ���� ����� �ؼ� �ϳ��� ������ (�ȼ� ���� ����, ��Ʈ ����)
    sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP; // AddressW ���� �ؽ�ó ��ǥ(U, V, W)�� 0~1 ������ ����� �� ��� ó�������� �����ϴ� ��.
    sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    // WRAP�� �ؽ�ó�� �ݺ��ؼ� �̾��ִ� ���
    sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    sampDesc.MinLOD = 0;
    sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

    DEVICE->CreateSamplerState(&sampDesc, _sampler.GetAddressOf());
}

Vector Texture::GetImageSize()
{
    return Vector(image.GetMetadata().width, image.GetMetadata().height);
}
