#include "View.hpp"

View::View(int widtht, int heightt) {
    width = widtht;
    height = heightt;
   
}
View::~View() {
    
}

int View::initialise() {
    
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    
    // Open a window and create its OpenGL context
    window = glfwCreateWindow(width, height, "My Game", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile

	//Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to intialize GLEW\n");
		getchar();
		glfwTerminate();
	}
    
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// Hide the mouse and enable unlimited mouvement
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set the mouse at the center of the screen
    
    glfwPollEvents();
    //we set the cursor at the centre so that it always start on our origin (0,0,0)
    glfwSetCursorPos(window, width / 2, height / 2);
    
    
    // Red background
    glClearColor(0.4f, 0.0f, 0.0f, 0.0f);
    
	
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Read our .obj file
	bool res = loadOBJ("Floor.obj", vertices, uvs, normals);
	//bool res = loadAssImp("Floor.obj", indices, indexed_vertices, indexed_uvs, indexed_normals);
	//bool res1 = loadOBJ("Sphere.obj", vertices1, uvs1, normals1);
	
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, indexed_vertices.size() * sizeof(glm::vec3), &indexed_vertices[0], GL_STATIC_DRAW);

	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices.push_back(glm::vec3(1, 1, 1));
	}
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices.size() * sizeof(glm::vec3), &colorsforvertices[0], GL_STATIC_DRAW);

	bool res2 = loadOBJ("Wall1.obj", vertices2, uvs2, normals2);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer2);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
	glBufferData(GL_ARRAY_BUFFER, vertices2.size() * sizeof(glm::vec3), &vertices2[0], GL_STATIC_DRAW);
	
	for (int i = 0; i < vertices2.size(); i++) {
		colorsforvertices2.push_back(glm::vec3(0, 0, 1));
	}
	glGenBuffers(1, &colorbuffer2);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer2);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices2.size() * sizeof(glm::vec3), &colorsforvertices2[0], GL_STATIC_DRAW);

	bool res3 = loadOBJ("Wall2.obj", vertices3, uvs3, normals3);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer3);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer3);
	glBufferData(GL_ARRAY_BUFFER, vertices3.size() * sizeof(glm::vec3), &vertices3[0], GL_STATIC_DRAW);

	for (int i = 0; i < vertices3.size(); i++) {
		colorsforvertices3.push_back(glm::vec3(1, 0, 0));
	}
	glGenBuffers(1, &colorbuffer3);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer3);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices3.size() * sizeof(glm::vec3), &colorsforvertices3[0], GL_STATIC_DRAW);

	bool res4 = loadOBJ("Wall3.obj", vertices4, uvs4, normals4);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer4);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer4);
	glBufferData(GL_ARRAY_BUFFER, vertices4.size() * sizeof(glm::vec3), &vertices4[0], GL_STATIC_DRAW);
	
	for (int i = 0; i < vertices4.size(); i++) {
		colorsforvertices4.push_back(glm::vec3(1, 1, 0));
	}
	glGenBuffers(1, &colorbuffer4);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer4);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices4.size() * sizeof(glm::vec3), &colorsforvertices4[0], GL_STATIC_DRAW);

	bool res5 = loadOBJ("Wall4.obj", vertices5, uvs5, normals5);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer5);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer5);
	glBufferData(GL_ARRAY_BUFFER, vertices5.size() * sizeof(glm::vec3), &vertices5[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices5.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer5);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer5);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices5.size() * sizeof(glm::vec3), &colorsforvertices5[0], GL_STATIC_DRAW);

	bool res6 = loadOBJ("Wall5.obj", vertices6, uvs6, normals6);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer6);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer6);
	glBufferData(GL_ARRAY_BUFFER, vertices6.size() * sizeof(glm::vec3), &vertices6[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices6.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer6);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer6);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices6.size() * sizeof(glm::vec3), &colorsforvertices6[0], GL_STATIC_DRAW);

	bool res7 = loadOBJ("Wall6.obj", vertices7, uvs7, normals7);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer7);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer7);
	glBufferData(GL_ARRAY_BUFFER, vertices7.size() * sizeof(glm::vec3), &vertices7[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices7.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer7);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer7);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices7.size() * sizeof(glm::vec3), &colorsforvertices7[0], GL_STATIC_DRAW);

	bool res8 = loadOBJ("Wall7.obj", vertices8, uvs8, normals8);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer8);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer8);
	glBufferData(GL_ARRAY_BUFFER, vertices8.size() * sizeof(glm::vec3), &vertices8[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices8.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer8);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer8);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices8.size() * sizeof(glm::vec3), &colorsforvertices8[0], GL_STATIC_DRAW);

	bool res9 = loadOBJ("Wall8.obj", vertices9, uvs9, normals9);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer9);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer9);
	glBufferData(GL_ARRAY_BUFFER, vertices9.size() * sizeof(glm::vec3), &vertices9[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices9.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer9);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer9);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices9.size() * sizeof(glm::vec3), &colorsforvertices9[0], GL_STATIC_DRAW);

	bool res10 = loadOBJ("Wall9.obj", vertices10, uvs10, normals10);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer10);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer10);
	glBufferData(GL_ARRAY_BUFFER, vertices10.size() * sizeof(glm::vec3), &vertices10[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices10.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer10);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer10);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices10.size() * sizeof(glm::vec3), &colorsforvertices10[0], GL_STATIC_DRAW);

	bool res11 = loadOBJ("Wall10.obj", vertices11, uvs11, normals11);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer11);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer11);
	glBufferData(GL_ARRAY_BUFFER, vertices11.size() * sizeof(glm::vec3), &vertices11[0], GL_STATIC_DRAW);

	for (int i = 0; i < vertices11.size(); i++) {
		colorsforvertices11.push_back(glm::vec3(0, 0, 1));
	}
	glGenBuffers(1, &colorbuffer11);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer11);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices11.size() * sizeof(glm::vec3), &colorsforvertices11[0], GL_STATIC_DRAW);

	bool res12 = loadOBJ("Wall11.obj", vertices12, uvs12, normals12);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer12);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer12);
	glBufferData(GL_ARRAY_BUFFER, vertices12.size() * sizeof(glm::vec3), &vertices12[0], GL_STATIC_DRAW);

	for (int i = 0; i < vertices12.size(); i++) {
		colorsforvertices12.push_back(glm::vec3(1, 0, 0));
	}
	glGenBuffers(1, &colorbuffer12);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer12);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices12.size() * sizeof(glm::vec3), &colorsforvertices12[0], GL_STATIC_DRAW);

	bool res13 = loadOBJ("Wall12.obj", vertices13, uvs13, normals13);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer13);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer13);
	glBufferData(GL_ARRAY_BUFFER, vertices13.size() * sizeof(glm::vec3), &vertices13[0], GL_STATIC_DRAW);

	for (int i = 0; i < vertices13.size(); i++) {
		colorsforvertices13.push_back(glm::vec3(1, 1, 0));
	}
	glGenBuffers(1, &colorbuffer13);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer13);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices13.size() * sizeof(glm::vec3), &colorsforvertices13[0], GL_STATIC_DRAW);

	bool res14 = loadOBJ("Wall13.obj", vertices14, uvs14, normals14);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer14);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer14);
	glBufferData(GL_ARRAY_BUFFER, vertices14.size() * sizeof(glm::vec3), &vertices14[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices14.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer14);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer14);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices14.size() * sizeof(glm::vec3), &colorsforvertices14[0], GL_STATIC_DRAW);

	bool res15 = loadOBJ("Wall14.obj", vertices15, uvs15, normals15);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer15);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer15);
	glBufferData(GL_ARRAY_BUFFER, vertices15.size() * sizeof(glm::vec3), &vertices15[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices15.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer15);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer15);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices15.size() * sizeof(glm::vec3), &colorsforvertices15[0], GL_STATIC_DRAW);

	bool res16 = loadOBJ("Wall15.obj", vertices16, uvs16, normals16);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer16);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer16);
	glBufferData(GL_ARRAY_BUFFER, vertices16.size() * sizeof(glm::vec3), &vertices16[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices16.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer16);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer16);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices16.size() * sizeof(glm::vec3), &colorsforvertices16[0], GL_STATIC_DRAW);

	bool res17 = loadOBJ("Wall16.obj", vertices17, uvs17, normals17);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer17);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer17);
	glBufferData(GL_ARRAY_BUFFER, vertices17.size() * sizeof(glm::vec3), &vertices17[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices17.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer17);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer17);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices17.size() * sizeof(glm::vec3), &colorsforvertices17[0], GL_STATIC_DRAW);

	bool res18 = loadOBJ("Wall7.obj", vertices18, uvs18, normals18);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer18);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer18);
	glBufferData(GL_ARRAY_BUFFER, vertices18.size() * sizeof(glm::vec3), &vertices18[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices18.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer18);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer18);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices18.size() * sizeof(glm::vec3), &colorsforvertices18[0], GL_STATIC_DRAW);

	bool res19 = loadOBJ("Wall18.obj", vertices19, uvs19, normals19);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer19);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer19);
	glBufferData(GL_ARRAY_BUFFER, vertices19.size() * sizeof(glm::vec3), &vertices19[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices19.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer19);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer19);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices19.size() * sizeof(glm::vec3), &colorsforvertices19[0], GL_STATIC_DRAW);

	bool res20 = loadOBJ("Wall19.obj", vertices20, uvs20, normals20);
	//bool res2 = loadAssImp("Wall1.obj", indices2, vertices2, uvs2, normals2);
	glGenBuffers(1, &vertexbuffer20);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer20);
	glBufferData(GL_ARRAY_BUFFER, vertices20.size() * sizeof(glm::vec3), &vertices20[0], GL_STATIC_DRAW);
	for (int i = 0; i < vertices.size(); i++) {
		colorsforvertices20.push_back(glm::vec3(1, 0, 1));
	}
	glGenBuffers(1, &colorbuffer20);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer20);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices20.size() * sizeof(glm::vec3), &colorsforvertices20[0], GL_STATIC_DRAW);

	//bool res1 = loadAssImp("Sphere.obj", indices1, vertices1, uvs1, normals1);
	bool res1 = loadOBJ("Sphere.obj", vertices1, uvs1, normals1);
	glGenBuffers(1, &vertexbuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
	glBufferData(GL_ARRAY_BUFFER, vertices1.size() * sizeof(glm::vec3), &vertices1[0], GL_STATIC_DRAW);

	for (int i = 0; i < vertices1.size(); i++) {
		colorsforvertices1.push_back(glm::vec3(0, 1, 0));
	}
	glGenBuffers(1, &colorbuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer1);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices1.size() * sizeof(glm::vec3), &colorsforvertices1[0], GL_STATIC_DRAW);

	/*
	static const GLfloat g_color_buffer_data[] = {
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.2f, 0.4f, 0.6f,
		0.5f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.2f, 0.4f, 0.6f,
		0.5f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.2f, 0.4f, 0.6f,
		0.5f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.2f, 0.4f, 0.6f,
		0.5f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.2f, 0.4f, 0.6f,
		0.5f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.2f, 0.4f, 0.6f,
		0.5f, 1.0f, 0.0f
	};

	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
    */

	programID = LoadShaders("SimpleVertexShader.hlsl", "SimpleFragmentShader.hlsl");
	MatrixID1 = glGetUniformLocation(programID, "MVP");
    return 1;
}

glm::mat4 getMVPMatrix(glm::mat4 ProjectionMatrix, glm::mat4 ViewMatrix, glm::mat4 ModelMatrix) {

	glm::mat4 Projection = ProjectionMatrix;

	glm::mat4 View = ViewMatrix;

	glm::mat4 Model = ModelMatrix;

	glm::mat4 mvp = Projection * View * Model; // Remember, matrix multiplication is the other way around

	return mvp;

}

/*
glm::mat4 getMVPMatrix() {
	glm::mat4 Projection = glm::perspective(
		glm::radians(50.0f), // The vertical Field of View, usually between 90°(extra wide) and 30°(quite zoomed in)
		4.0f/3.0f, // Aspect Ratio. Depends on the size of your window.
		0.1f, // Near clipping plane. Keep as big as possible, or you'll get precision issues.
		100.0f // Far clipping plane. Keep as little as possible.
	);
	glm::mat4 View = glm::lookAt(
		glm::vec3(-10, 8, -10), // Camera is at (4,3,-3), in World Space
		glm::vec3(-20, 0, 10), // and looks at the origin
		glm::vec3(0, 1, 0) // Head is up (set to 0,-1,0 to look upside - down)
		);
	glm::mat4 Model = glm::mat4(1.0f); // keep an identity matrix so the geometry stays where it was placed originally
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 mvp = Projection * View * Model; // Remember, matrix multiplication is the other way around
	return mvp;
}
 */

void View::update() {
    do{
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear( GL_COLOR_BUFFER_BIT );
        
		computeMatricesFromInputs(window, width, height);

		// Use our shader
		glUseProgram(programID);

		//--
		glm::mat4 mvp1 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f)
		);
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp1[0][0]);
		
		
		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);
		
		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);
		
		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		
		//--
		
		//--
		glm::mat4 mvp3 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp3[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer2);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--
		
		//--
		glm::mat4 mvp4 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f)
		);
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp4[0][0]);


		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer3);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer3);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices3.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		//--
		
		//--
		glm::mat4 mvp5 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f)
		);
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp5[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer4);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer4);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices4.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		
		//--

		//--
		glm::mat4 mvp6 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f)
		);
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp6[0][0]);


		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer5);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer5);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices5.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		//--
		//--
		glm::mat4 mvp7 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp7[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer6);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer6);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--
		//--
		glm::mat4 mvp8 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp8[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer7);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer7);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--
		//--
		glm::mat4 mvp9 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp9[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer8);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer8);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--
		//--
		glm::mat4 mvp10 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp10[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer9);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer9);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--
		//--
		glm::mat4 mvp11 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp11[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer10);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer10);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--

		//--
		glm::mat4 mvp12 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f)
		);
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp12[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer11);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);
		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer11);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--

		//--
		glm::mat4 mvp13 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp13[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer12);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer12);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--

		//--
		glm::mat4 mvp14 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f)
		);
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp14[0][0]);


		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer13);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer13);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices3.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		//--

		//--
		glm::mat4 mvp15 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f)
		);
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp15[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer14);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer14);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices4.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		//--

		//--
		glm::mat4 mvp16 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f)
		);
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp16[0][0]);


		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer15);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer15);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices5.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		//--
		//--
		glm::mat4 mvp17 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp17[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer16);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer16);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--
		//--
		glm::mat4 mvp18 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp18[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer17);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer17);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--
		//--
		glm::mat4 mvp19 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp19[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer18);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer18);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--
		//--
		glm::mat4 mvp20 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp20[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer19);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer19);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--
		//--
		glm::mat4 mvp21 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f));
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp21[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer20);
		glVertexAttribPointer(
			0,                //attribute 0, no particular reason for 0, but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer20);
		glVertexAttribPointer(
			1,					//attribute. No particular reason for 1, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		// The following code draws a triangle using the function void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); //vertices2.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//--

		glm::mat4 mvp2 = getMVPMatrix(
			getProjectionMatrix(),
			getViewMatrix(),
			glm::mat4(1.0f)
		);
		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp2[0][0]);

		//1st attribute buffer: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                //attribute 2, no particular reason for 2 , but must match the layout in the vertex shader
			3,				  //size
			GL_FLOAT,		  //type
			GL_FALSE,		  //normalized?
			0,				  //stride
			(void*)0		  //array buffer offset
		);

		//2nd attribute buffer: colours
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer1);
		glVertexAttribPointer(
			1,					//attribute 3. No particular reason for 3, but must match the layout in the shader.
			3,					//size
			GL_FLOAT,			//type
			GL_FALSE,			//normalized?
			0,					//stride
			(void*)0			//array buffer offset
		);

		glDrawArrays(GL_TRIANGLES, 0, 960); //vertices1.size() * sizeof(glm::vec3)); //first vertex: 0, count: 2 triangles are drawn. 2 triangles * 3 vertices = 6
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);


        // Swap buffers	
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0 );
    
	
	//CLeanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &colorbuffer);
	glDeleteBuffers(1, &vertexbuffer1);
	glDeleteBuffers(1, &colorbuffer1);
	glDeleteBuffers(1, &vertexbuffer2);
	glDeleteBuffers(1, &colorbuffer2); 
	glDeleteBuffers(1, &vertexbuffer3);
	glDeleteBuffers(1, &colorbuffer3); 
	glDeleteBuffers(1, &vertexbuffer4);
	glDeleteBuffers(1, &colorbuffer4);
	glDeleteBuffers(1, &vertexbuffer5);
	glDeleteBuffers(1, &colorbuffer5);
	glDeleteBuffers(1, &vertexbuffer6);
	glDeleteBuffers(1, &colorbuffer6);
	glDeleteBuffers(1, &vertexbuffer7);
	glDeleteBuffers(1, &colorbuffer7);
	glDeleteBuffers(1, &vertexbuffer8);
	glDeleteBuffers(1, &colorbuffer8);
	glDeleteBuffers(1, &vertexbuffer9);
	glDeleteBuffers(1, &colorbuffer9);
	glDeleteBuffers(1, &vertexbuffer10);
	glDeleteBuffers(1, &colorbuffer10);
	glDeleteBuffers(1, &vertexbuffer11);
	glDeleteBuffers(1, &colorbuffer11);
	glDeleteBuffers(1, &vertexbuffer12);
	glDeleteBuffers(1, &colorbuffer12);
	glDeleteBuffers(1, &vertexbuffer13);
	glDeleteBuffers(1, &colorbuffer13);
	glDeleteBuffers(1, &vertexbuffer14);
	glDeleteBuffers(1, &colorbuffer14);
	glDeleteBuffers(1, &vertexbuffer15);
	glDeleteBuffers(1, &colorbuffer15);
	glDeleteBuffers(1, &vertexbuffer16);
	glDeleteBuffers(1, &colorbuffer16);
	glDeleteBuffers(1, &vertexbuffer17);
	glDeleteBuffers(1, &colorbuffer17);
	glDeleteBuffers(1, &vertexbuffer18);
	glDeleteBuffers(1, &colorbuffer18);
	glDeleteBuffers(1, &vertexbuffer19);
	glDeleteBuffers(1, &colorbuffer19);
	glDeleteBuffers(1, &vertexbuffer20);
	glDeleteBuffers(1, &colorbuffer20);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    
}

