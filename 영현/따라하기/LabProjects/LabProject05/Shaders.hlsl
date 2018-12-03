float4 VSMain(uint nVertexID : SV_VertexID) : SV_POSITION
{
	float4 output;

	// ������Ƽ��(�ﰢ��)�� �����ϴ� ������ �ε���(SV_VertexID)�� ���� ������ ��ȯ�Ѵ�.
	// ������ ��ġ ��ǥ�� ��ȯ�� �� ��ǥ(SV_POSITION)�̴�. ��, ���� ��ǥ���� ��ǥ�̴�.
	if (nVertexID == 0) output = float4(0.0, 0.5, 0.5, 1.0);
	else if (nVertexID == 1) output = float4(0.5, -0.5, 0.5, 1.0);
	else if (nVertexID == 2) output = float4(-0.5, -0.5, 0.5, 1.0);

	return output;
}

float4 PSMain(float4 input : SV_POSITION) : SV_TARGET
{
	// ������Ƽ���� ��� �ȼ��� ������ ������� ��ȯ�Ѵ�.
	return float4(1.0f, 1.0f, 0.0f, 1.0f);		// Yellow
}
/*
struct GSOutput
{
	float4 pos : SV_POSITION;
};

[maxvertexcount(3)]
void main(
	triangle float4 input[3] : SV_POSITION, 
	inout TriangleStream< GSOutput > output
)
{
	for (uint i = 0; i < 3; i++)
	{
		GSOutput element;
		element.pos = input[i];
		output.Append(element);
	}
}
*/