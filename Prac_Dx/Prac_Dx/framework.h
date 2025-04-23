// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <iostream>
#include <wrl/client.h>
#include <memory>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>



#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib,"dxguid.lib")


using namespace std;
using namespace DirectX;

#include "Core/Device/Device.h"
#include "Program/GameManager.h"

// Macro
#include "Macro.h"


extern HWND hWnd;
