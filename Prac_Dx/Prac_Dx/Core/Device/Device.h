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
    // 인력사무소장
    // 외주를 맡길 얘들을 싹 다 고용
    // 컴퓨터의 하드웨어 점검, 리소스 할당, GPU에 접근할 수 있도록 도와주는 얘
    Microsoft::WRL::ComPtr<ID3D11Device> device; // <- GPU에 그리라고 명령 하는 애
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> dc; // => 리소스를 '그래픽 파이프라인'에 바인딩하고, GPU의 명령을 따르는 애
    // Init() 함수 163줄 보면 Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer; 있는데 backBuffer는 swapchain이랑 같이 써야함!!
    // swapchain은 화면에 출력하기 위한 여러개의 버퍼를 담아두는 공간, backbuffer는 현재 뒤에서 그려지고 있고 보여지지 않은 부분
    // backbuffer가 그리고 swapchain->Present() 함수를 통하여 backbuffer에 그린 애를 보여주기위해 swap
    Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain; // 화면에 그려지는 과정 여러개 버퍼를 이용하여 화면에 출력, 화면 깜빡임 방지
    // 후면버퍼를 가리킬 포인터
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView; // <- 그래픽 작업의 결과가 어디에 저장될지를 결정하는 "출력 대상"
};

