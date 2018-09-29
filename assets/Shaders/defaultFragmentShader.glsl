#version 330 core

out vec4 FragColor;

in vec3 normal;
in vec3 position;

uniform vec3 lightPos;

void main()
{
    vec3 _normal = normalize(normal);
    vec3 lightDir = normalize(lightPos - position);

    float _diffuse = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec4(0, 0, 0, 1);

    vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4(result, 1.0);
}