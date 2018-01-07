#version 330 core

out vec4 color;

in vec2 TexCoords;

uniform sampler2D scene;

uniform bool edge;

uniform vec2 offsets[9];
uniform float edge_kernel[9];

void main() {
	color = vec4(0.0, 0.0, 0.0, 1.0);
	vec3 sampleTex[9];

	if(edge) {
		for(int i = 0; i < 9; i++) {
			sampleTex[i] = vec3(texture(scene, TexCoords.st + offsets[i]));
		}

		for(int i = 0; i < 9; i++) {
			color += vec4(sampleTex[i] * edge_kernel[i], 0.0f);
		}

		color.a = 1.0f;
	}
	else {
		color = texture(scene, TexCoords);
	}
}