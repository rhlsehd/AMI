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
    
    void Input();
    void AddColor(XMFLOAT4 color) { _colorbuffer->SetData(color); _colorbuffer->Update(); }
    Vector GetImageSize() { return _texture->GetImageSize(); }

    shared_ptr<Transform> GetTransform() { return _transform; }

    void SetLeftRight(int value) { _leftRightBuffer->SetData(value); _leftRightBuffer->Update(); }
private:
    shared_ptr<VertexShader> _vertexShader;
    shared_ptr<VertexBuffer> _vertexBuffer;
    shared_ptr<InputLayout> _inputLayout;
    shared_ptr<PixelShader> _pixelShader;

    shared_ptr<Texture> _texture;

    shared_ptr<Transform> _transform;

    vector<Vertex> _vertices;
    shared_ptr<ColorBuffer> _colorbuffer;
    shared_ptr<LeftRightBuffer> _leftRightBuffer;
};

