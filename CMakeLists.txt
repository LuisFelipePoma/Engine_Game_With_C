cmake_minimum_required(VERSION 3.0)

# Define el nombre del proyecto y el lenguaje de programación
project(MOTOR)

# Crea un ejecutable llamado "MOTOR" a partir de los archivos fuente y enlaza las librerías necesarias
add_executable(${PROJECT_NAME} 
    Motor/main.cpp 
    
    Motor/Error.cpp 
    Motor/Error.h 
    
    Motor/GLTexture.h

    Motor/HLSLProgram.cpp
    Motor/HLSLProgram.h 
    
    Motor/IOManager.cpp
    Motor/IOManager.h

    Motor/ImageLoader.cpp
    Motor/ImageLoader.h

    Motor/MainGame.cpp 
    Motor/MainGame.h 
    
    Motor/ResourceManager.cpp
    Motor/ResourceManager.h

    Motor/Sprite.cpp
    Motor/Sprite.h 

    Motor/TextureCache.cpp
    Motor/TextureCache.h

    Motor/Vertex.h

    Motor/Window.cpp
    Motor/Window.h

    Motor/picoPNG.cpp
    Motor/picoPNG.h
)

# Copiar la imagen y el archivo de texto al directorio de compilación
file(COPY ${CMAKE_SOURCE_DIR}/ DESTINATION ${CMAKE_BINARY_DIR})
configure_file(${CMAKE_SOURCE_DIR}/my_text.txt ${CMAKE_BINARY_DIR} COPYONLY)


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
