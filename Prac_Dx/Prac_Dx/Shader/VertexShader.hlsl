struct VertexInput // 정점 버퍼에서 GPU로 들어오는 데이터를 받는 입력 구조체
{
    float4 pos : POSITION; // <- 4D 벡터, 정점의 위치 (x,y,z,w)
    float4 color : COLOR; // - > 정점에 대한 RGB 색상 정보
    float2 uv : TEXCOORD;
};

struct VertexOutput // 정점 셰이더가 처리한 결과를 레스터라이저나 픽셀 셰이더에 넘겨줄 출력 구조체
{
    float4 pos : SV_Position; // -> 꼭짓점의 최종 위치 SV_POSITION -> GPU가 이걸 스크린 공간으로 렌더링 하기위해 사용
    float4 color : COLOR; // -> 그대로 픽셀 셰이더에 전달될 정보
    float2 uv : TEXCOORD;
};


VertexOutput VS(VertexInput input)
{
    VertexOutput result;
    result.pos = input.pos;
    result.color = input.color;
    result.uv = input.uv;
    return result;
}