#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
    :_radius(radius)
{
}

void CircleCollider::Update()
{
}

void CircleCollider::Render()
{
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
    return false;
}

void CircleCollider::SetRed()
{
}

void CircleCollider::SetGreen()
{
}

void CircleCollider::CreateMesh()
{
}

void CircleCollider::CreateMaterial()
{
}
