#include "libs.h"
#include <ostream>


// The dimensions of the window
const int WIDTH = 600;
const int HEIGHT = 600;


int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "bruh", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);

    /*
    // shader
    // create shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //attach shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //fragment shader
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);


    //linking fragment shader and vertex shader into program shader
    GLuint shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    // Check for linking errors

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    //activate program
    glUseProgram(shaderProgram);

    //delete the shaders objets once linked
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    */
    
    Shader shaderProgram("vertex", "frag");


    // cube
    GLfloat vertices[] =
    { //     COORDINATES     /        COLORS      /   TexCoord  //
       /*0*/ -0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
       /*1*/ -0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
       /*2*/   0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
       /*3*/   0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 5.0f,
       /*4*/  -0.5f, 1.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 5.0f,
       /*5*/  -0.5f, 1.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 5.0f,
       /*6*/   0.5f, 1.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 5.0f,
       /*7*/  0.5f, 1.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,

       /*0*/ -0.5f, 0.0f,  -4.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
       /*1*/ -0.5f, 0.0f, -5.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
       /*2*/   0.5f, 0.0f, -5.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
       /*3*/   0.5f, 0.0f,  -4.5f,     0.83f, 0.70f, 0.44f,	0.0f, 5.0f,
       /*4*/  -0.5f, 1.0f,  -4.5f,     0.83f, 0.70f, 0.44f,	5.0f, 5.0f,
       /*5*/  -0.5f, 1.0f, -5.5f,     0.83f, 0.70f, 0.44f,	0.0f, 5.0f,
       /*6*/   0.5f, 1.0f, -5.5f,     0.83f, 0.70f, 0.44f,	5.0f, 5.0f,
       /*7*/  0.5f, 1.0f,  -4.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,

       /*0*/ 0.5f, 0.0f,  -9.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
       /*1*/ 0.5f, 0.0f, -10.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
       /*2*/   1.5f, 0.0f, -10.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
       /*3*/   1.5f, 0.0f,  -9.5f,     0.83f, 0.70f, 0.44f,	0.0f, 5.0f,
       /*4*/  0.5f, 1.0f,  -9.5f,     0.83f, 0.70f, 0.44f,	5.0f, 5.0f,
       /*5*/  0.5f, 1.0f, -10.5f,     0.83f, 0.70f, 0.44f,	0.0f, 5.0f,
       /*6*/   1.5f, 1.0f, -10.5f,     0.83f, 0.70f, 0.44f,	5.0f, 5.0f,
       /*7*/  1.5f, 1.0f,  -9.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,

       /*0*/ 2.0f, 0.0f,  -14.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
       /*1*/ 2.0f, 0.0f, -15.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
       /*2*/   3.0f, 0.0f, -15.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
       /*3*/   3.0f, 0.0f,  -14.5f,     0.83f, 0.70f, 0.44f,	0.0f, 5.0f,
       /*4*/  2.0f, 1.0f,  -14.5f,     0.83f, 0.70f, 0.44f,	5.0f, 5.0f,
       /*5*/  2.0f, 1.0f, -15.5f,     0.83f, 0.70f, 0.44f,	0.0f, 5.0f,
       /*6*/   3.0f, 1.0f, -15.5f,     0.83f, 0.70f, 0.44f,	5.0f, 5.0f,
       /*7*/  3.0f, 1.0f,  -14.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,

       /*8*/ -1000.0f, 0.0f,  -1000.0f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
       /*9*/       1000.0f, 0.0f, 0.0f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
       /*10*/    500.0f, 0.0f, 1000.0f,     0.83f, 0.70f, 0.44f,	2.5f, 2.5f,
    };

    // Indices for vertices order
    GLuint indices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 4, 7,
        0, 3, 7,
        4, 5, 6,
        4, 6, 7,
        2, 3, 7,
        2, 6, 7,
        0, 1, 4,
        1, 4, 5,
        1, 5, 6, 
        1, 2, 6,

        8,9,10,
        8,10,11,
        8,12,15,
        8,11,15,
        12,13,14,
        12,14,15,
        10,11,15,
        10,14,15,
        8,9,12,
        9,12,13,
        9,13,14,
        9,10,14,

        16,17,18,
        16,18,19,
        16,20,23,
        16,19,23,
        20,21,22,
        20,22,23,
        18,19,23,
        18,22,23,
        16,17,20,
        17,20,21,
        17,21,22,
        17,18,22,

        24,25,26,
        24,26,27,
        24,28,31,
        24,27,31,
        28,29,30,
        28,30,31,
        26,27,31,
        26,30,31,
        24,25,28,
        25,28,29,
        25,29,30,
        25,26,30,

        32,33,34
    };

    
    

    /*
    // vertex buffer objects (VBO) is used to give the vertex data to the GPU
    GLuint VBO;
    GLuint VAO;
    GLuint EBO;

    auto buffer_ID = 1;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(buffer_ID, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);


    //Bind the buffer to the vbo
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    */

    // Generates Vertex Array Object and binds it

    //cube
    VAO VAO1;
    VAO1.Bind();
    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));
    // Links VBO attributes such as coordinates and colors to VAO
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();
    // Gets ID of uniform called "scale"
    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

  


    //Texture
    int widthImg;
    int heightImg;
    int channels;
    
    unsigned char* bytes = SOIL_load_image("brick.png", &widthImg, &heightImg, &channels, 0);
    GLuint texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);

    

    GLuint uniform1 = glGetUniformLocation(shaderProgram.ID, "tex0");
    glUseProgram(shaderProgram.ID);
    glUniform1i(uniform1, 0);

    
    // Enables the Depth Buffer
    glEnable(GL_DEPTH_TEST);

    Camera camera(WIDTH, HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f));


    // loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
       

        glClearColor(0.0f, 0.3f, 0.3f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram.ID);


        camera.Inputs(window);
        camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

        /*
        // Simple timer
        double crntTime = glfwGetTime();
        if (crntTime - prevTime >= 1 / 60)
        {
            rotation += 0.5f;
            prevTime = crntTime;
        }

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 proj = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(rotation), glm::vec3(1.0f, 0.0f, 0.5f));
        view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
        proj = glm::perspective(glm::radians(45.0f), (float)(WIDTH / HEIGHT), 0.1f, 100.0f);

        int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
        */

        

        glUniform1f(uniID, 0.5f);
        glBindTexture(GL_TEXTURE_2D, texture);


        VAO1.Bind();

       
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

        /*
        for (int i = 0; i < 10; i++) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(1.0f, 0.0f, 1.0f) * (float)i);
            int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(model));
            glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        }
        */
        
        //glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        //glBindVertexArray(0);

        glBindVertexArray(0);



        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    glDeleteTextures(1, &texture);

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    //free image
    SOIL_free_image_data(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);
    glDeleteProgram(shaderProgram.ID);
  

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}




