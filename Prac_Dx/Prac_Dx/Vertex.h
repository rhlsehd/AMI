#pragma once
#include "framework.h"

struct Vertex
{
    Vertex() : pos(XMFLOAT3()) {}
    Vertex(float x, float y) : pos(x, y, 0) {}

    XMFLOAT3 pos;
    XMFLOAT4 color = XMFLOAT4(1, 1, 1, 1);
};
