#pragma once
class GameObject
{
public:
    GameObject(wstring file);
    ~GameObject();

    void Update();
    void Render();

    void CreateVertices();
    void CreateMeterial(wstring file);
    
    shared_ptr<class Transform> GetTransform() { return _transform; }
private:
    shared_ptr<VertexShader> _vertexShader;
    shared_ptr<VertexBuffer> _vertexBuffer;
    shared_ptr<InputLayout> _inputLayout;
    shared_ptr<PixelShader> _pixelShader;
    shared_ptr<Texture> _texture;
    shared_ptr<class Transform> _transform;
    vector<Vertex> _vertices;
};

