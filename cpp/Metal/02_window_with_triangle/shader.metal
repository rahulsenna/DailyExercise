#include <metal_stdlib>
using namespace metal;

struct VertexOut
{
  float4 position [[position]];
  float4 color;
};

vertex VertexOut VertFn(uint id [[vertex_id]])
{
  float2 positions[3] = {
    float2( 0.0,  0.8), // top
    float2(-0.8, -0.8), // bottom left
    float2( 0.8, -0.8), // bottom right
  };

  VertexOut res;
  float4 colors[4] = {
    float4(1,0,0,1),
    float4(0,1,0,1),
    float4(0,0,1,1)
  };

  res.position = float4(positions[id], 0, 1);
  res.color = colors[id];

  return res;
}

fragment float4 FragFn(VertexOut input [[stage_in]])
{
  return input.color;
}
