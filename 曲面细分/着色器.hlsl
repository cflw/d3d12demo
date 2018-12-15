struct S曲面细分v {
	float2 m位置 : POSITION0;
};
struct S曲面细分h {
	float2 m位置 : POSITION;
};
struct S曲面细分hc {
	float m边镶嵌[4] : SV_TessFactor;
	float m内镶嵌[2] : SV_InsideTessFactor;
};
struct S曲面细分d {
	float2 m位置 : POSITION;
};
struct S曲面细分p {
	float4 m位置 : SV_POSITION;
};

S曲面细分h f曲面细分v(S曲面细分v a输入) {
	return a输入;
}

static const uint c控制点数 = 4;
S曲面细分hc f曲面细分hc(
	InputPatch<S曲面细分h, c控制点数> a输入, 
	uint a图元 : SV_PrimitiveID) {
	S曲面细分hc v输出;
	v输出.m边镶嵌[0] = 4;
	v输出.m边镶嵌[1] = 4;
	v输出.m边镶嵌[2] = 4;
	v输出.m边镶嵌[3] = 4;
	v输出.m内镶嵌[0] = 4;
	v输出.m内镶嵌[1] = 4;
	return v输出;
}

[domain("quad")]
[partitioning("integer")]
[outputtopology("triangle_cw")]
[outputcontrolpoints(c控制点数)]
[patchconstantfunc("f曲面细分hc")]
S曲面细分d f曲面细分h(InputPatch<S曲面细分h, c控制点数> a输入,
	uint i : SV_OutputControlPointID,
	uint a图元 : SV_PrimitiveID) {

	return a输入[i];
}

[domain("quad")]
S曲面细分p f曲面细分d(S曲面细分hc a常量,
	float2 a域 : SV_DomainLocation,
	const OutputPatch<S曲面细分d, c控制点数> a输入) {

	float2 v1 = lerp(a输入[0].m位置, a输入[1].m位置, a域.x);
	float2 v2 = lerp(a输入[2].m位置, a输入[3].m位置, a域.x);
	float2 p = lerp(v1, v2, a域.y);

	S曲面细分p v输出;
	v输出.m位置 = float4(p, 0, 1);
	return v输出;
}

float4 f曲面细分p(S曲面细分p a输入) : SV_TARGET {
	return float4(1, 1, 1, 1);
}