#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec3 color;
// Inputs the texture coordinates from the Vertex Shader
in vec2 texCoord;
in float depth;

// Gets the Texture Unit from the main function
uniform sampler2D tex0;


void main()
{
	float fogAmount = smoothstep(1.0f, 5.0f, depth);

	vec4 background = vec4(0.0f, 0.3f, 0.3f, 0.5f);
	FragColor = texture(tex0, texCoord) + (background - texture(tex0, texCoord)) * fogAmount;
}