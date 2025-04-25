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
    return tex.Sample(samp, input.uv);
}