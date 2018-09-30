#version 330 core

out vec4 FragColor;

in vec3 normal;
in vec3 fragPos;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;

void main()
{
    vec3 lightPos = vec3(1, 2, 0);
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 viewPos = vec3(0.0, 0.0, 300.0);

    vec3 ambient = material.ambient * lightColor;

    vec3 _normal = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragPos);

    float _diffuse = max(dot(_normal, lightDir), 0.0);
    vec3 diffuse = _diffuse * lightColor;

    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, _normal);
    float _specular = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = material.specular * _specular * lightColor;

    vec3 result = (ambient + diffuse + specular) * vec3(0.2, 0.3, 0.5);
    FragColor = vec4(result, 1.0);
}