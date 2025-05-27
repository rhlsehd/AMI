#pragma once

#include "framework.h"

class LeftRightBuffer : public ConstantBuffer
{
public:
    // 상수버퍼로 넘길 때는 16바이트 배수
    struct Data
    {
        int leftRight = 0;
        int padding[3];
    };

    LeftRightBuffer() : ConstantBuffer(&_data, sizeof(Data)) {}
    ~LeftRightBuffer() {}

    void SetData(int leftRight)
    {
        _data.leftRight = leftRight;
    }

private:
    Data _data;
};