#pragma once
class CircleCollider
{
public:
    CircleCollider(Vector center, float radius);
    ~CircleCollider() {}

    void Update();
    void Render();

    shared_ptr<Transform> GetTransform() { return _transform; }

    Vector GetWorldCenter() { return _transform->GetWorldPos(); }
    float GetWorldRadius() { return _radius * _transform->GetWorldScale().x; }

    bool IsCollision(shared_ptr<CircleCollider> other);

    void SetRed();
    void SetGreen();

private:
    float _radius;

    void CreateMesh();
    void CreateMaterial();

    
    shared_ptr<VertexBuffer> _vertexBuffer;

    shared_ptr<VertexShader> _vs;
    shared_ptr<PixelShader> _ps;

    shared_ptr<Transform> _transform;
};

