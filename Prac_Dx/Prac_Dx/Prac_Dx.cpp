// Prac_Dx.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Prac_Dx.h"

#define MAX_LOADSTRING 100

// 영화촬영
// 총감독 / 프로그래머
// 영화사 / DirectX
// 카메라 / 카메라(view 행렬)
// 세트장 / World
// 배우 / Actor(정점들의 집합 Mesh, Material)
// 인력사무소장 / Device

// DirectX : Direct Access => 하드웨어(GPU)에 직접 접근하겠다.



// 연출감독
// 세트장을 실질적으로 꾸며주는 연출가
// 렌더링 대상을 결정(어디에 그릴지 결정)

// -------------------------------------------------
Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer; // 정점의 정보를 담아두는 공간
Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayOut; // 정점 데이터의 형식을 정의하는 설명서, 각 정점이 가진 데이터 형태(위치, 색상) 등을 GPU에게 설명, 얘를 통해 GPU가 무엇을 어떻게 그릴지 알 수 있음
Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader; // 정점 데이터를 처리하는 셰이더, GPU에서 실행되어 정점 데이터를 변환하거나 조작하는 셰이더 프로그램
Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader; // 픽셀 데이터를 처리하는 셰이더, GPU에서 실행되어 픽셀 색상을 계산하는 셰이더 프로그램

struct Vertex
{
    Vertex() : pos(XMFLOAT3()) {}
    Vertex(float x, float y) : pos(x, y, 0) {}

    XMFLOAT3 pos;
    XMFLOAT4 color = XMFLOAT4(1, 1, 1, 1);
};

void Init();
void Render();

// 전역 변수:

HWND hWnd; // <- 창 생성
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PRACDX, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    Device::Create();
   
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PRACDX));


    Init();
    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        
        else
        {
            Render();
        }
    }
    Device::Delete();
    return (int) msg.wParam;
}



void Init()
{
#pragma region Device, DC, SwapChain, RenderTarget
    
#pragma endregion

    // VertexInputLayOut -> VertexShader -> PixelShader

        // Vertex Shader에 들어갈 때, 데이터(Vertex, 색.. 등등)들의 설명서
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        {
            "POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,
            D3D11_INPUT_PER_VERTEX_DATA,0
        },

        {
            "COLOR",0,DXGI_FORMAT_R32G32B32A32_FLOAT,0,12,
            D3D11_INPUT_PER_VERTEX_DATA,0
        }

        
    };

    UINT layoutSize = ARRAYSIZE(layout);

    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    Microsoft::WRL::ComPtr<ID3DBlob> vertexBlob; // VertexShader를 만들 때 필요한 얘
    D3DCompileFromFile(L"Shader/VertexShader.hlsl", nullptr, nullptr,  /* 진입점 이름 */"VS", "vs_5_0", flags, 0, vertexBlob.GetAddressOf(), nullptr);

    DEVICE->CreateInputLayout(layout, layoutSize, vertexBlob->GetBufferPointer(), vertexBlob->GetBufferSize(), inputLayOut.GetAddressOf());
    DEVICE->CreateVertexShader(vertexBlob->GetBufferPointer(), vertexBlob->GetBufferSize(), nullptr, IN vertexShader.GetAddressOf());

    Microsoft::WRL::ComPtr<ID3DBlob> pixelBlob; // PixelShader를 만들 때 필요한 얘
    D3DCompileFromFile(L"Shader/PixelShader.hlsl", nullptr, nullptr, "PS", "ps_5_0", flags, 0, pixelBlob.GetAddressOf(), nullptr);
    DEVICE->CreatePixelShader(pixelBlob->GetBufferPointer(), pixelBlob->GetBufferSize(), nullptr, IN pixelShader.GetAddressOf());

    /* TODO */
    Vertex vertices[6] = { {-0.5f,0.5f}, {0.5f, -0.5f}, {-0.5f, -0.5f}, {-0.5f,0.5f}, {0.5f,0.5f }, { 0.5f,-0.5f } };
        
    vertices[0].color = { 1,0,0,1 };
    vertices[1].color = { 0,1,0,1 };
    vertices[2].color = { 0,0,1,1 };
    vertices[3].color = { 0,0,1,1 };
    vertices[4].color = { 0,1,0,1 };
    vertices[5].color = { 1,0,0,1 };
   
    // VertexBuffer 세팅
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(Vertex) * 6; // <- 버퍼를 할당할 때 필요한 메모리 크기를 설정, 버퍼에 저장할 데이터의 총 크기를 지정하고, 메모리를 올바르게 할당할 수 있도록 도와줍니다.
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = &vertices[0];

    DEVICE->CreateBuffer(&bd, &initData, vertexBuffer.GetAddressOf());
}

void Render()
{
    float clearColor[] = { 1.0f ,1.0f ,1.0f ,1.0f };

    DC->ClearRenderTargetView(Device::GetInstance()->GetRTV().Get(), clearColor);

    DC->VSSetShader(vertexShader.Get(), nullptr, 0);
    DC->PSSetShader(pixelShader.Get(), nullptr, 0);

    DC->IASetInputLayout(inputLayOut.Get());

    UINT stride = sizeof(Vertex);
    UINT offset = 0;
    DC->IASetVertexBuffers(0, 1, vertexBuffer.GetAddressOf(), &stride, &offset);

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    DC->Draw(6, 0);

    Device::GetInstance()->GetSwapChain()->Present(0, 0);
}


//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PRACDX));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PRACDX);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) // <- 윈도우 애플리케이션 초기화를 담당하는 함수, 주로 창 생성 초기 설정하는데 사용됨
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
