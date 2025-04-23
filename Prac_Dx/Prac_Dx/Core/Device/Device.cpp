#include "framework.h"
#include "Device.h"

Device* Device::_instance = nullptr;

Device::Device()
{
    RECT rect;
    GetClientRect(hWnd, &rect);
    UINT width = rect.right - rect.left;
    UINT height = rect.bottom - rect.top;

    D3D_FEATURE_LEVEL featureLevels[] = // dx가 지원가능한 기능 수준
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };

    UINT featureSize = ARRAYSIZE(featureLevels); // 위 배열의 크기 기능 수준 개수

    DXGI_SWAP_CHAIN_DESC sd = {}; //DXGI 스왑 체인 설정 구조 초기화,  스왑 체인은 백버퍼 < ->프론트버퍼를 교환해주는 구조

    sd.BufferCount = 1; // 백버퍼 갯수
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60; // 화면 주사율, 60Hz
    sd.BufferDesc.RefreshRate.Denominator = 1;
    // Numerator / Denominator = 화면 프레임 갱신 최고 속도

    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // 백버퍼용도 : 렌더타겟으로 출력 
    sd.OutputWindow = hWnd; // 출력할 창
    sd.SampleDesc.Count = 1; // 멀티샘플링 없음
    sd.SampleDesc.Quality = 0;
    sd.Windowed = true; // 창모드로 실행 

    auto hResult = D3D11CreateDeviceAndSwapChain
    (
        nullptr, // 어댑터 (nullptr이면 기본 GPU)
        D3D_DRIVER_TYPE_HARDWARE, // 하드웨어 가속 사용
        0, // 소프트웨어 드라이버 안 씀
        D3D11_CREATE_DEVICE_DEBUG, // 디버그 정보 포함 (개발용)
        featureLevels, // 지원 기능 수준 목록
        featureSize, // 그 개수 
        D3D11_SDK_VERSION, // SDK 버전
        &sd,// 스왑체인 설정
        IN swapChain.GetAddressOf(), // 결과로 swapChain 생성
        IN device.GetAddressOf(), // device 생성
        nullptr, // 실제 선택된 feature level은 무시
        IN dc.GetAddressOf() // device context 생성
    );

    Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer;

    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf()); // 백버퍼 (texture2d 형태) 받아오기
    device->CreateRenderTargetView(backBuffer.Get(), nullptr, renderTargetView.GetAddressOf()); // 그걸 기반으로 렌더타겟 뷰 설정

    dc->OMSetRenderTargets(1, renderTargetView.GetAddressOf(), nullptr); // 렌더 타겟 뷰를 OM 단계에 연결 (여기다 그리게 됨)
    // OM(Output-Merger) 단계란 렌더링 파이프 라인 마지막 단계, 도화지에 최종적으로 색칠하는 단계, renderTargetView = 그 도화지 

    D3D11_VIEWPORT vp; // Viewport = 실제 그리는 화면 영역 (카메라 창 같은 개념)
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
