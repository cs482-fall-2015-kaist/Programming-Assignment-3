#include "SystemContext.h"
#include <sstream>
#include "Mesh.h"
#include "DeviceMesh.h"

std::string SystemContext::LoadObj(char *path)
{
	std::string header, data, err;
	std::istringstream liness(path);
	getline(liness, header, '='); getline(liness, data, '=');
	if (strcmp(header.c_str(), "mesh") == 0)
	{
		int found = data.find_last_of("/\\");
		std::string path = data.substr(0, found + 1);
		//std::cout << "Loading: " << data << std::endl;
		err = tinyobj::LoadObj(shapes, data.c_str(), path.c_str());
	}
	return err;
}

void SystemContext::initMesh()
{
	for (const auto &shape : shapes)
	{
		drawMeshes.push_back(DeviceMesh::deviceMeshFromMesh(Mesh::meshFromShape(shape)));
		if (shape.material.name == "light")
		{
			// process light
		}
	}
}
