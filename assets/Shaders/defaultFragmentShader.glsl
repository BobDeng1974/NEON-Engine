#version 330 core

out vec4 FragColor;

in vec3 normal;
in vec3 position;

uniform vec3 lightPos;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;

void main()
{
    vec3 _normal = normalize(normal);
    vec3 lightDir = normalize(lightPos - position);

    float _diffuse = max(dot(_normal, lightDir), 0.0);
    vec3 diffuse = _diffuse * vec3(0, 0, 0);

    vec3 result = (material.ambient + diffuse) * vec3(0.2, 0.3, 0.5);
    FragColor = vec4(result, 1.0);
}