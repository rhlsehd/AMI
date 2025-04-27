

struct PixelInput
{
    float4 pos : SV_Position; // SystemValue
    float2 uv : TEXCOORD;
    float4 color : COLOR;
};

Texture2D tex : register(t0); // <- �ؽ�ó�� t0 ���Կ� ���ε��ؼ� ���̴����� ����� �� �ְ� �Ѵ�.
SamplerState samp : register(s0); // <- ���÷��� s0 ���Կ� ���ε��ؼ� ���̴����� ����� �� �ְ� �Ѵ�.

float4 PS(PixelInput input) : SV_TARGET
{ 
    float4 texColor = tex.Sample(samp, input.uv);
    
    if (texColor.a < 0.1f)
    {
        discard; // ���� ���� ������ �ȼ��� ���� (���� ó��)
    }
    
    return texColor;
}