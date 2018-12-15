cbuffer cb0 : register(b0) {
	float2 g窗口;
}
float4 f遮罩v(float2 a : POSITION) : SV_POSITION {
	float4 v = float4(a, 0, 1);
	v.x /= g窗口.x;
	v.y /= g窗口.y;
	return v;
}
float4 f遮罩p(float4 a : SV_POSITION) : SV_TARGET {
	return float4(1, 1, 1, 1);
}