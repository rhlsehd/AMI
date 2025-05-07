#pragma once

#define DEVICE	Device::GetInstance()->GetDevice()
#define DC		Device::GetInstance()->GetDC()

#define WIN_WIDTH		1200
#define WIN_HEIGHT		720

#define KEY_DOWN(k)		InputManager::GetInstance()->Down(k)
#define KEY_UP(k)		InputManager::GetInstance()->Up(k)
#define KEY_PRESS(k)	InputManager::GetInstance()->Press(k)

#define DELTA_TIME		TimeManager::GetInstance()->DeltaTime()
#define RUN_TIME		TimeManager::GetInstance()->RunTime()