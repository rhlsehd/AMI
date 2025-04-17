struct VertexInput // ���� ���ۿ��� GPU�� ������ �����͸� �޴� �Է� ����ü
{
    float4 pos : POSITION; // <- 4D ����, ������ ��ġ (x,y,z,w)
    float4 color : COLOR; // - > ������ ���� RGB ���� ����
};

struct VertexOutput // ���� ���̴��� ó���� ����� �����Ͷ������� �ȼ� ���̴��� �Ѱ��� ��� ����ü
{
    float4 pos : SV_Position; // -> �������� ���� ��ġ SV_POSITION -> GPU�� �̰� ��ũ�� �������� ������ �ϱ����� ���
    float4 color : COLOR; // -> �״�� �ȼ� ���̴��� ���޵� ����
};


VertexOutput VS(VertexInput input)
{
    VertexOutput result;
    result.pos = input.pos;
    result.color = input.color;
    return result;
}