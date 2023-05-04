cmake_minimum_required(VERSION 3.0)

# Define el nombre del proyecto y el lenguaje de programación
project(MOTOR)

# Crea un ejecutable llamado "MOTOR" a partir de los archivos fuente y enlaza las librerías necesarias
add_executable(${PROJECT_NAME} 
    Motor/main.cpp 
    Motor/MainGame.h 
    Motor/MainGame.cpp 
    Motor/Error.h 
    Motor/Error.cpp 
    Motor/HLSLProgram.h 
    Motor/HLSLProgram.cpp
    Motor/Sprite.h 
    Motor/Sprite.cpp
    Motor/Vertex.h
)

# Agrega las bibliotecas requeridas
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

# Enlaza las bibliotecas requeridas al ejecutable
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        SDL2::SDL2 
        SDL2::SDL2main 
        GLEW::GLEW 
        OpenGL::GL 
)
