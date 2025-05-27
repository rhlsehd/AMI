#pragma once
#include "framework.h"

class ColorBuffer : public ConstantBuffer
{
public:
    struct Data
    {
        XMFLOAT4 color;
    };

    ColorBuffer() : ConstantBuffer(&_data, sizeof(Data)) {}
    ~ColorBuffer() {}

    void SetData(XMFLOAT4 color)
    {
        _data.color = color;
    }

private:
    Data _data;
};