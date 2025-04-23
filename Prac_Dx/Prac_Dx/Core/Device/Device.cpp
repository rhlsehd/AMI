#include "framework.h"
#include "Device.h"

Device* Device::_instance = nullptr;

Device::Device()
{
    RECT rect;
    GetClientRect(hWnd, &rect);
    UINT width = rect.right - rect.left;
    UINT height = rect.bottom - rect.top;

    D3D_FEATURE_LEVEL featureLevels[] = // dx�� ���������� ��� ����
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };

    UINT featureSize = ARRAYSIZE(featureLevels); // �� �迭�� ũ�� ��� ���� ����

    DXGI_SWAP_CHAIN_DESC sd = {}; //DXGI ���� ü�� ���� ���� �ʱ�ȭ,  ���� ü���� ����� < ->����Ʈ���۸� ��ȯ���ִ� ����

    sd.BufferCount = 1; // ����� ����
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60; // ȭ�� �ֻ���, 60Hz
    sd.BufferDesc.RefreshRate.Denominator = 1;
    // Numerator / Denominator = ȭ�� ������ ���� �ְ� �ӵ�

    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // ����ۿ뵵 : ����Ÿ������ ��� 
    sd.OutputWindow = hWnd; // ����� â
    sd.SampleDesc.Count = 1; // ��Ƽ���ø� ����
    sd.SampleDesc.Quality = 0;
    sd.Windowed = true; // â���� ���� 

    auto hResult = D3D11CreateDeviceAndSwapChain
    (
        nullptr, // ����� (nullptr�̸� �⺻ GPU)
        D3D_DRIVER_TYPE_HARDWARE, // �ϵ���� ���� ���
        0, // ����Ʈ���� ����̹� �� ��
        D3D11_CREATE_DEVICE_DEBUG, // ����� ���� ���� (���߿�)
        featureLevels, // ���� ��� ���� ���
        featureSize, // �� ���� 
        D3D11_SDK_VERSION, // SDK ����
        &sd,// ����ü�� ����
        IN swapChain.GetAddressOf(), // ����� swapChain ����
        IN device.GetAddressOf(), // device ����
        nullptr, // ���� ���õ� feature level�� ����
        IN dc.GetAddressOf() // device context ����
    );

    Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer;

    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf()); // ����� (texture2d ����) �޾ƿ���
    device->CreateRenderTargetView(backBuffer.Get(), nullptr, renderTargetView.GetAddressOf()); // �װ� ������� ����Ÿ�� �� ����

    dc->OMSetRenderTargets(1, renderTargetView.GetAddressOf(), nullptr); // ���� Ÿ�� �並 OM �ܰ迡 ���� (����� �׸��� ��)
    // OM(Output-Merger) �ܰ�� ������ ������ ���� ������ �ܰ�, ��ȭ���� ���������� ��ĥ�ϴ� �ܰ�, renderTargetView = �� ��ȭ�� 

    D3D11_VIEWPORT vp; // Viewport = ���� �׸��� ȭ�� ���� (ī�޶� â ���� ����)
    vp.Width = width;
    vp.Height = height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    dc->RSSetViewports(1, &vp);

}

Device::~Device()
{
}
