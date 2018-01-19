#include "Renderer/Shader.h"

#include <iostream>

Shader &Shader::use() {
	glUseProgram(getShaderID());
	return *this;
}

void Shader::compile(const GLchar *vertexSource, const GLchar *fragmentSource, const GLchar *geometrySource) {
	GLuint sVertex, sFragment, sGeometry;

	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexSource, NULL);
	glCompileShader(sVertex);
	checkCompileErrors(sVertex, "VERTEX");

	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, NULL);
	glCompileShader(sFragment);
	checkCompileErrors(sFragment, "FRAGMENT");

	if (geometrySource != nullptr) {
		sGeometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(sGeometry, 1, &geometrySource, NULL);
		glCompileShader(sGeometry);
		checkCompileErrors(sGeometry, "GEOMETRY");
	}

	this->setShaderID(glCreateProgram());
	glAttachShader(getShaderID(), sVertex);
	glAttachShader(getShaderID(), sFragment);
	if (geometrySource != nullptr) {
		glAttachShader(getShaderID(), sGeometry);
	}
	glLinkProgram(getShaderID());
	checkCompileErrors(getShaderID(), "PROGRAM");

	glDeleteShader(sVertex);
	glDeleteShader(sFragment);
	if (geometrySource != nullptr) {
		glDeleteShader(sGeometry);
	}
}

void Shader::setFloat(const GLchar *name, GLfloat value, GLboolean useShader) {
	if (useShader) {
		this->use();
	}
	glUniform1f(glGetUniformLocation(getShaderID(), name), value);
}

void Shader::setInteger(const GLchar *name, GLint value, GLboolean useShader) {
	if (useShader) {
		this->use();
	}
	glUniform1i(glGetUniformLocation(getShaderID(), name), value);
}

void Shader::setVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader) {
	if (useShader) {
		this->use();
	}
	glUniform2f(glGetUniformLocation(getShaderID(), name), x, y);
}

void Shader::setVector2f(const GLchar *name, const glm::vec2 &value, GLboolean useShader) {
	if (useShader) {
		this->use();
	}
	glUniform2f(glGetUniformLocation(getShaderID(), name), value.x, value.y);
}

void Shader::setVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader) {
	if (useShader) {
		this->use();
	}
	glUniform3f(glGetUniformLocation(getShaderID(), name), x, y, z);
}

void Shader::setVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader) {
	if (useShader) {
		this->use();
	}
	glUniform3f(glGetUniformLocation(getShaderID(), name), value.x, value.y, value.z);
}

void Shader::setVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader) {
	if (useShader) {
		this->use();
	}
	glUniform4f(glGetUniformLocation(getShaderID(), name), x, y, z, w);
}

void Shader::setVector4f(const GLchar *name, const glm::vec4 &value, GLboolean useShader) {
	if (useShader) {
		this->use();
	}
	glUniform4f(glGetUniformLocation(getShaderID(), name), value.x, value.y, value.z, value.w);
}

void Shader::setMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader) {
	if (useShader) {
		this->use();
	}
	glUniformMatrix4fv(glGetUniformLocation(getShaderID(), name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::checkCompileErrors(GLuint object, std::string type) {
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM") {
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- --"
				<< std::endl;
		}
	}
	else {
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Link-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- --"
				<< std::endl;
		}
	}
}

GLuint Shader::getShaderID() const {
	return ID;
}

void Shader::setShaderID(GLuint ID) {
	this->ID = ID;
}