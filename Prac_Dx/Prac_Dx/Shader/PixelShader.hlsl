

struct PixelInput
{
    float4 pos : SV_Position; // SystemValue
    float2 uv : TEXCOORD;
    float4 color : COLOR;
};

Texture2D tex : register(t0); // <- 텍스처를 t0 슬롯에 바인딩해서 셰이더에서 사용할 수 있게 한다.
SamplerState samp : register(s0); // <- 샘플러를 s0 슬롯에 바인딩해서 셰이더에서 사용할 수 있게 한다.

float4 PS(PixelInput input) : SV_TARGET
{ 
    float4 texColor = tex.Sample(samp, input.uv);
    
    if (texColor.a < 0.1f)
    {
        discard; // 알파 값이 낮으면 픽셀을 버림 (투명 처리)
    }
    
    return texColor;
}