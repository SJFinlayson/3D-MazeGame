#pragma once
// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>
#include <vector>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;
#include "common/objloader.hpp"
#include "common/vboindexer.hpp"
#include <glm/gtx/transform.hpp>
#include "common/shader.hpp"
#include "common/controls.hpp"
#include "common/text2D.hpp"

class View {
private:
    
    GLFWwindow* window;
    
    GLuint programID;
	GLuint MatrixID1;

	GLuint vertexbuffer;
	GLuint vertexbuffer1;
	GLuint vertexbuffer2;
	GLuint vertexbuffer3;
	GLuint vertexbuffer4;
	GLuint vertexbuffer5;
	GLuint vertexbuffer6;
	GLuint vertexbuffer7;
	GLuint vertexbuffer8;
	GLuint vertexbuffer9;
	GLuint vertexbuffer10;
	GLuint vertexbuffer11;
	GLuint vertexbuffer12;
	GLuint vertexbuffer13;
	GLuint vertexbuffer14;
	GLuint vertexbuffer15;
	GLuint vertexbuffer16;
	GLuint vertexbuffer17;
	GLuint vertexbuffer18;
	GLuint vertexbuffer19;
	GLuint vertexbuffer20;

    GLuint VertexArrayID;

	GLuint colorbuffer;
	GLuint colorbuffer1;
	GLuint colorbuffer2;
	GLuint colorbuffer3;
	GLuint colorbuffer4;
	GLuint colorbuffer5;
	GLuint colorbuffer6;
	GLuint colorbuffer7;
	GLuint colorbuffer8;
	GLuint colorbuffer9;
	GLuint colorbuffer10;
	GLuint colorbuffer11;
	GLuint colorbuffer12;
	GLuint colorbuffer13;
	GLuint colorbuffer14;
	GLuint colorbuffer15;
	GLuint colorbuffer16;
	GLuint colorbuffer17;
	GLuint colorbuffer18;
	GLuint colorbuffer19;
	GLuint colorbuffer20;

	std::vector<glm::vec3> colorsforvertices;
	std::vector<glm::vec3> colorsforvertices1;
	std::vector<glm::vec3> colorsforvertices2;
	std::vector<glm::vec3> colorsforvertices3;
	std::vector<glm::vec3> colorsforvertices4;
	std::vector<glm::vec3> colorsforvertices5;
	std::vector<glm::vec3> colorsforvertices6;
	std::vector<glm::vec3> colorsforvertices7;
	std::vector<glm::vec3> colorsforvertices8;
	std::vector<glm::vec3> colorsforvertices9;
	std::vector<glm::vec3> colorsforvertices10;
	std::vector<glm::vec3> colorsforvertices11;
	std::vector<glm::vec3> colorsforvertices12;
	std::vector<glm::vec3> colorsforvertices13;
	std::vector<glm::vec3> colorsforvertices14;
	std::vector<glm::vec3> colorsforvertices15;
	std::vector<glm::vec3> colorsforvertices16;
	std::vector<glm::vec3> colorsforvertices17;
	std::vector<glm::vec3> colorsforvertices18;
	std::vector<glm::vec3> colorsforvertices19;
	std::vector<glm::vec3> colorsforvertices20;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs; // Won't be used at the moment.
	std::vector<glm::vec3> normals; // Won't be used at the moment.
	std::vector<glm::vec3> indexed_vertices;
	std::vector<glm::vec2> indexed_uvs;
	std::vector<glm::vec3> indexed_normals;
	std::vector<glm::vec3> vertices1;
	std::vector<glm::vec2> uvs1;
	std::vector<glm::vec3> normals1;
	std::vector<glm::vec3> vertices2;
	std::vector<glm::vec2> uvs2;
	std::vector<glm::vec3> normals2;
	std::vector<glm::vec3> vertices3;
	std::vector<glm::vec2> uvs3;
	std::vector<glm::vec3> normals3;
	std::vector<glm::vec3> vertices4;
	std::vector<glm::vec2> uvs4;
	std::vector<glm::vec3> normals4;
	std::vector<glm::vec3> vertices5;
	std::vector<glm::vec2> uvs5;
	std::vector<glm::vec3> normals5;
	std::vector<glm::vec3> vertices6;
	std::vector<glm::vec2> uvs6;
	std::vector<glm::vec3> normals6;
	std::vector<glm::vec3> vertices7;
	std::vector<glm::vec2> uvs7;
	std::vector<glm::vec3> normals7;
	std::vector<glm::vec3> vertices8;
	std::vector<glm::vec2> uvs8;
	std::vector<glm::vec3> normals8;
	std::vector<glm::vec3> vertices9;
	std::vector<glm::vec2> uvs9;
	std::vector<glm::vec3> normals9;
	std::vector<glm::vec3> vertices10;
	std::vector<glm::vec2> uvs10;
	std::vector<glm::vec3> normals10;
	std::vector<glm::vec3> vertices11;
	std::vector<glm::vec2> uvs11;
	std::vector<glm::vec3> normals11;
	std::vector<glm::vec3> vertices12;
	std::vector<glm::vec2> uvs12;
	std::vector<glm::vec3> normals12;
	std::vector<glm::vec3> vertices13;
	std::vector<glm::vec2> uvs13;
	std::vector<glm::vec3> normals13;
	std::vector<glm::vec3> vertices14;
	std::vector<glm::vec2> uvs14;
	std::vector<glm::vec3> normals14;
	std::vector<glm::vec3> vertices15;
	std::vector<glm::vec2> uvs15;
	std::vector<glm::vec3> normals15;
	std::vector<glm::vec3> vertices16;
	std::vector<glm::vec2> uvs16;
	std::vector<glm::vec3> normals16;
	std::vector<glm::vec3> vertices17;
	std::vector<glm::vec2> uvs17;
	std::vector<glm::vec3> normals17;
	std::vector<glm::vec3> vertices18;
	std::vector<glm::vec2> uvs18;
	std::vector<glm::vec3> normals18;
	std::vector<glm::vec3> vertices19;
	std::vector<glm::vec2> uvs19;
	std::vector<glm::vec3> normals19;
	std::vector<glm::vec3> vertices20;
	std::vector<glm::vec2> uvs20;
	std::vector<glm::vec3> normals20;

	std::vector<unsigned short> indices;
	std::vector<unsigned short> indices1;
	std::vector<unsigned short> indices2;

    //screen size
    int width;
    int height;
  
    
public:
    View(int widtht, int heightt);
    ~View();
    int initialise();
    void update();

    
};

