#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include<iostream>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glewInit();

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error!" << std::endl;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	float positions[6] = {
		-0.5f, -0.5f,
		0.0f, 0.0f,
		0.5f, -0.5f
	};
	unsigned int bufferID; // ID of the generated buffer
	glGenBuffers(1, &bufferID); // generate a buffer
	glBindBuffer(GL_ARRAY_BUFFER, bufferID); //Selecting a target buffer
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float)); // creates and initializes a buffer object's data store

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.5f, -0.5f);
		glEnd();


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}