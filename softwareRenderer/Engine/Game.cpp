/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "ScreenSpaceTransformer.h"
#include "Mat4.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{

	ScreenSpaceTransformer screen;

	Vec3 p1(-0.2f, -0.2f, 0.0f);
	Vec3 p2(0.2f, -0.2f, 0.0f);
	Vec3 p3(0.2f, 0.2f, 0.0f);
	Vec3 p4(-0.2f, 0.2f, 0.0f);



	Vec4 pv1 = Mat4::Rotate(20, Vec3(0, 0, 1)) * Vec4(p1);
	Vec4 pv2 = Mat4::Rotate(20, Vec3(0, 0, 1)) * Vec4(p2);
	Vec4 pv3 = Mat4::Rotate(20, Vec3(0, 0, 1)) * Vec4(p3);
	Vec4 pv4 = Mat4::Rotate(20, Vec3(0, 0, 1)) * Vec4(p4);

	p1 = Vec3(pv1.x, pv1.y, pv1.z);
	p2 = Vec3(pv2.x, pv2.y, pv2.z);
	p3 = Vec3(pv3.x, pv3.y, pv3.z);
	p4 = Vec3(pv4.x, pv4.y, pv4.z);	
	
	screen.Transform(p1);
	screen.Transform(p2);
	screen.Transform(p3);
	screen.Transform(p4);

	gfx.DrawLine(Vec2(p1.x,p1.y), Vec2(p2.x,p2.y), Colors::White);
	gfx.DrawLine(Vec2(p2.x, p2.y), Vec2(p3.x, p3.y), Colors::White);
	gfx.DrawLine(Vec2(p3.x, p3.y), Vec2(p4.x, p4.y), Colors::White);
	gfx.DrawLine(Vec2(p4.x, p4.y), Vec2(p1.x, p1.y), Colors::White);
	
}
