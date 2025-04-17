#pragma once
class Device
{
public:
    static void Create()
    {
        if (_instance == nullptr)
        {
            _instance = new Device();
        }
    }

    static void Delete()
    {
        if (_instance != nullptr)
        {
            delete _instance;
        }
    }

    static Device* GetInstance() { return _instance; }

    Microsoft::WRL::ComPtr<ID3D11Device> GetDevice() { return device; }
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> GetDC() { return dc; }
    Microsoft::WRL::ComPtr<IDXGISwapChain> GetSwapChain() { return swapChain; }
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> GetRTV() { return renderTargetView; }
private:

    Device();
    ~Device();

    static Device* _instance;
    // �η»繫����
    // ���ָ� �ñ� ����� �� �� ���
    // ��ǻ���� �ϵ���� ����, ���ҽ� �Ҵ�, GPU�� ������ �� �ֵ��� �����ִ� ��
    Microsoft::WRL::ComPtr<ID3D11Device> device; // <- GPU�� �׸���� ��� �ϴ� ��
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> dc; // => ���ҽ��� '�׷��� ����������'�� ���ε��ϰ�, GPU�� ����� ������ ��
    // Init() �Լ� 163�� ���� Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer; �ִµ� backBuffer�� swapchain�̶� ���� �����!!
    // swapchain�� ȭ�鿡 ����ϱ� ���� �������� ���۸� ��Ƶδ� ����, backbuffer�� ���� �ڿ��� �׷����� �ְ� �������� ���� �κ�
    // backbuffer�� �׸��� swapchain->Present() �Լ��� ���Ͽ� backbuffer�� �׸� �ָ� �����ֱ����� swap
    Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain; // ȭ�鿡 �׷����� ���� ������ ���۸� �̿��Ͽ� ȭ�鿡 ���, ȭ�� ������ ����
    // �ĸ���۸� ����ų ������
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView; // <- �׷��� �۾��� ����� ��� ��������� �����ϴ� "��� ���"
};

