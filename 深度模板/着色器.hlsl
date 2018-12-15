cbuffer cb0 : register(b0) {
	matrix g世界;
	matrix g视图;
	matrix g投影;
}
struct S空间v {
	float3 m位置 : POSITION0;
	float4 m颜色 : COLOR0;
};
struct S空间s {
	float4 m位置 : SV_POSITION;
	float4 m颜色 : COLOR0;
};
S空间s f空间v(S空间v a) {
	S空间s v;
	v.m位置 = float4(a.m位置, 1);
	v.m位置 = mul(v.m位置, g世界);
	v.m位置 = mul(v.m位置, g视图);
	v.m位置 = mul(v.m位置, g投影);
	v.m颜色 = a.m颜色;
	return v;
}
float4 f空间p(S空间s a) : SV_TARGET {
	return a.m颜色;
}