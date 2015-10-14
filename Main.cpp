#include <Windows.h>
#include "GdkDx9.h"

using namespace std;
using namespace gdk::dx9;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	GdkDx9 gdk;

	Cursor::Lock = true;

	Camera camera(D3DXVECTOR3(0.0f, 2.25f, -2.5f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	Mesh mesh("Models/Block.x", "Textures/Dirt.png");

	while (Screen::Message())
	{
		if (Input::GetKey(DIK_W))
		{
			camera.position.x += sin(camera.rotation.y) * 0.05f;
			camera.position.z += cos(camera.rotation.y) * 0.05f;
		}

		if (Input::GetKey(DIK_S))
		{
			camera.position.x -= sin(camera.rotation.y) * 0.05f;
			camera.position.z -= cos(camera.rotation.y) * 0.05f;
		}

		if (Input::GetKey(DIK_A))
		{
			camera.position.x += sin(camera.rotation.y - (D3DX_PI / 2.0f)) * 0.05f;
			camera.position.z += cos(camera.rotation.y - (D3DX_PI / 2.0f)) * 0.05f;
		}

		if (Input::GetKey(DIK_D))
		{
			camera.position.x += sin(camera.rotation.y + (D3DX_PI / 2.0f)) * 0.05f;
			camera.position.z += cos(camera.rotation.y + (D3DX_PI / 2.0f)) * 0.05f;
		}

		camera.rotation -= D3DXVECTOR3(Input::GetMouseDeltaPosition().y, Input::GetMouseDeltaPosition().x, 0.0f) * 0.001f;

		camera.View();

		for (int y = 0; y < 1; ++y)
		{
			for (int z = 0; z < 100; ++z)
			{
				for (int x = 0; x < 100; ++x)
				{
					mesh.position.x = x;
					mesh.position.y = -y;
					mesh.position.z = z;
					mesh.Draw();
				}
			}
		}
	}

	return 0;
}
