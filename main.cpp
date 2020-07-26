#include "mygraphics.h"
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <iostream>
using namespace std;
void maximizeWindow()
{ //This function is defined to Maximize window
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
int main()
{
	// Initialising
	bool play = true;
	while (play)
	{
		int w = 0, h = 0;
		maximizeWindow(); //This function calls to Maximizes window
		getConsoleWindowDimensions(w, h);
		maximizeWindow();
		getConsoleWindowDimensions(w, h);
		//w += 275;
		//h += 100;
		cls();

		SetConsoleTitle("Space Invaders");
		showConsoleCursor(false); //This disables the cursers
		// main event loop
		int x1[11] = {20};
		int y1[5] = {80};
		int x2[11] = {};
		int y2[5] = {};
		bool bullet = false, win = false, enbullet = false;
		bool ene[55] = {};
		int b = 5, bx = 1000, by = 1000, enbx = 0, enby = 0; //
		int a = w / 2, g = h - 50, z = 5, score = 0, yl = 4, rl = 10, ll = 0, count = 10, ebwt = 20, ebw = 0, life = 3;
		char d = '\0';
		for (int q = 1; q < 11; q++)
		{
			x1[q] = x1[q - 1] + 105;
		}
		for (int q = 0; q < 11; q++)
		{
			x2[q] = x1[q] + 35;
		}
		for (int q = 1; q < 5; q++)
		{
			y1[q] = y1[q - 1] + 75;
		}
		for (int q = 0; q < 5; q++)
		{
			y2[q] = y1[q] + 35;
		}
		for (int q = 0; q < 55; q++)
		{
			ene[q] = true;
		}
		system("cls");
		system("color 0f");
		while (true)
		{
			//drawRectangle(0,0,w,h,0,0,0,0,0,0);
			drawLine(0, 5, w, 5, 255); //These draw borders for the game
			drawLine(w, 5, w, h, 255);
			drawLine(0, h, w, h, 255);
			drawLine(0, 5, 0, h, 255);
			//drawRectangle(0,0,w,h,0,0,0,0,0,0);
			if (z == 10)
			{
				for (int q = 0; q < 11; q++)
				{ //This clears previous drawen graphics of enemies
					drawRectangle(x1[q], y1[0], x2[q], y2[0], 12, 12, 12, 12, 12, 12);
					drawRectangle(x1[q], y1[1], x2[q], y2[1], 12, 12, 12, 12, 12, 12);
					drawRectangle(x1[q], y1[2], x2[q], y2[2], 12, 12, 12, 12, 12, 12);
					drawRectangle(x1[q], y1[3], x2[q], y2[3], 12, 12, 12, 12, 12, 12);
					drawRectangle(x1[q], y1[4], x2[q], y2[4], 12, 12, 12, 12, 12, 12);
				}
				if (x2[rl] > w - 2 || x1[ll] < 1)
				{
					b *= -1;
					for (int q = 0; q < 5; q++)
					{
						y1[q] += h / 40;
						y2[q] += h / 40;
					}
				}
				for (int q = 0; q < 11; q++)
				{
					x1[q] += b;
					x2[q] += b;
				}
				for (int q = 0; q < 11; q++)
				{ //This block draws all enemies
					if (ene[q] == true)
						drawRectangle(x1[q], y1[0], x2[q], y2[0], 0, 255, 0, 0, 0, 0);
					if (ene[q + 11] == true)
						drawRectangle(x1[q], y1[1], x2[q], y2[1], 0, 255, 0, 0, 0, 0);
					if (ene[q + 22] == true)
						drawRectangle(x1[q], y1[2], x2[q], y2[2], 0, 255, 0, 0, 0, 0);
					if (ene[q + 33] == true)
						drawRectangle(x1[q], y1[3], x2[q], y2[3], 0, 255, 0, 0, 0, 0);
					if (ene[q + 44] == true)
						drawRectangle(x1[q], y1[4], x2[q], y2[4], 0, 255, 0, 0, 0, 0);
				}
				z = 0;
				if (enbullet == false)
				{
					int temp;
					do
					{
						temp = rand() % 11;
					} while (ene[11 * yl + temp] == false);
					enbx = x2[temp];
					enby = y2[yl];
					enbullet = true;
				}
				drawRectangle(enbx - 3, enby - 15, enbx + 3, enby + 15, 12, 12, 12, 12, 12, 12); //clear previouse image of bullet
				if (enbullet)
				{
					enby += 5;
					if (enby > h + 30)
					{
						enbullet = false;
					}
				}
				drawRectangle(enbx - 3, enby - 15, enbx + 3, enby + 15, 0, 0, 0, 255, 255, 150); //enemy bullet erase
			}
			drawRectangle(100, h + 10, w, h + 47, 12, 12, 12, 12, 12, 12); //enemy bullet
			z++;
			count++;
			drawRectangle(a - 25, g, a + 25, g + 25, 255, 0, 0, 255, 0, 0); //Player
			drawRectangle(a - 5, g - 15, a + 5, g, 255, 0, 0, 255, 0, 0);
			drawRectangle(a + 25, g - 15, a + 50, g + 25, 12, 12, 12, 12, 12, 12); //Player cleaner right
			drawRectangle(a + 5, g - 15, a + 25, g, 12, 12, 12, 12, 12, 12);
			drawRectangle(a - 50, g - 15, a - 25, g + 25, 12, 12, 12, 12, 12, 12); //Player cleaner left
			drawRectangle(a - 25, g - 15, a - 5, g, 12, 12, 12, 12, 12, 12);
			for (int k = 0; k < 10; k++)
			{				//player bullet movement as a whole
				if (bullet) //player bullet movement with single increment
				{
					by -= 1;
					for (int q = 0; q < 11; q++)
					{
						if (bx >= x1[q] && bx <= x2[q])
						{ //checks for collision b/w any enemy and player bullet and eliminates enemy if any
							if (by >= y1[4] && by <= y2[4] && ene[q + 44])
							{
								ene[q + 44] = false;
								by = -10;
								bullet = false;
							}
							if (by >= y1[3] && by <= y2[3] && ene[q + 33])
							{
								ene[q + 33] = false;
								by = -10;
								bullet = false;
							}
							if (by >= y1[2] && by <= y2[2] && ene[q + 22])
							{
								ene[q + 22] = false;
								by = -10;
								bullet = false;
							}
							if ((by >= y1[1] && by <= y2[1]) && ene[q + 11])
							{
								ene[q + 11] = false;
								by = -10;
								bullet = false;
							}
							if (by >= y1[0] && by <= y2[0])
							{
								ene[q] = false;
								by = -10;
								bullet = false;
							}
							if (bullet == false)
							{
								score += 100;
								break;
							}
						}
					}
				}
				drawEllipse(bx - 3, by - 5, bx + 3, by + 5, 150, 150, 0, 255, 250, 150);
				drawEllipse(bx - 6, by - 6, bx + 5, by + 8, 12, 12, 12);
			}
			if (enbx >= a - 25 && enbx <= a + 25 && enby >= g && enby <= g + 25 && enbullet)
			{ //checks for colision b/w player and enemy bullet
				life--;
				enbullet = false;
				enby += 10;
			}
			if (by < 0)
			{
				bullet = false;
			}
			if (y2[yl] > h - 50)
			{
				win = false;
				break;
			}
			if (kbhit())
				d = getch();
			//d=getKey();
			if (d == 75 || d == 'A' || d == 'a')
			{
				a -= 25; //player move left
				if (a - 25 < 0)
					a = 25;
			}
			if (d == 77 || d == 'D' || d == 'd')
			{
				a += 25; //player move right
				if (a + 25 > w)
					a = w - 25;
			}
			if ((d == 32) && (!bullet))
			{ //player shoots bullet
				bullet = true;
				bx = a;
				by = g;
				count = 0;
			}
			if (d == 'i')
				b = 0; //Cheats
			if (d == 'o')
				b = 5; //Cheats
			d = '\0';
			bool allFalse = true;
			for (int q = 0; q < 55; q++)
			{				//checks weather all enemes are eliminated or not
				if (ene[q]) //wining statment
					allFalse = false;
			}
			if (allFalse)
			{ //game exits if all values with win statment
				win = true;
				break;
			}
			if (bullet)
			{
				drawEllipse(bx - 3, by - 3, bx + 3, by + 3, 150, 150, 0); //bullet drawing
				drawEllipse(bx - 5, by, bx + 5, by + 8, 12, 12, 12);
			} //bullet eraser

			if (ene[10] == false && ene[21] == false && ene[32] == false && ene[43] == false && ene[54] == false)
			{
				rl = 9;
				if (ene[9] == false && ene[20] == false && ene[31] == false && ene[42] == false && ene[53] == false)
				{
					rl = 8;
					if (ene[8] == false && ene[19] == false && ene[30] == false && ene[41] == false && ene[52] == false)
					{
						rl = 7;
						if (ene[7] == false && ene[18] == false && ene[29] == false && ene[40] == false && ene[51] == false)
						{
							rl = 6;
							if (ene[6] == false && ene[17] == false && ene[28] == false && ene[39] == false && ene[50] == false)
							{
								rl = 5;
								if (ene[5] == false && ene[16] == false && ene[27] == false && ene[38] == false && ene[49] == false)
								{
									rl = 4;
									if (ene[4] == false && ene[15] == false && ene[26] == false && ene[37] == false && ene[48] == false)
									{
										rl = 3;
										if (ene[3] == false && ene[14] == false && ene[25] == false && ene[36] == false && ene[47] == false)
										{
											rl = 2;
											if (ene[2] == false && ene[13] == false && ene[24] == false && ene[35] == false && ene[46] == false)
											{
												rl = 1;
												if (ene[1] == false && ene[12] == false && ene[23] == false && ene[34] == false && ene[45] == false)
												{
													rl = 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if (ene[0] == false && ene[11] == false && ene[22] == false && ene[33] == false && ene[44] == false)
			{
				ll = 1;
				if (ene[1] == false && ene[12] == false && ene[23] == false && ene[34] == false && ene[45] == false)
				{
					ll = 2;
					if (ene[2] == false && ene[13] == false && ene[24] == false && ene[35] == false && ene[46] == false)
					{
						ll = 3;
						if (ene[3] == false && ene[14] == false && ene[25] == false && ene[36] == false && ene[47] == false)
						{
							ll = 4;
							if (ene[4] == false && ene[15] == false && ene[26] == false && ene[37] == false && ene[48] == false)
							{
								ll = 5;
								if (ene[5] == false && ene[16] == false && ene[27] == false && ene[38] == false && ene[49] == false)
								{
									ll = 6;
									if (ene[6] == false && ene[17] == false && ene[28] == false && ene[39] == false && ene[50] == false)
									{
										ll = 7;
										if (ene[7] == false && ene[18] == false && ene[29] == false && ene[40] == false && ene[51] == false)
										{
											ll = 8;
											if (ene[8] == false && ene[19] == false && ene[30] == false && ene[41] == false && ene[52] == false)
											{
												ll = 9;
												if (ene[9] == false && ene[20] == false && ene[31] == false && ene[42] == false && ene[53] == false)
												{
													ll = 10;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if (ene[44] == false && ene[45] == false && ene[46] == false && ene[47] == false && ene[48] == false && ene[49] == false && ene[50] == false && ene[51] == false && ene[52] == false && ene[53] == false && ene[54] == false)
			{
				yl = 3;
				if (ene[33] == false && ene[34] == false && ene[35] == false && ene[36] == false && ene[38] == false && ene[39] == false && ene[40] == false && ene[41] == false && ene[42] == false && ene[43] == false && ene[44] == false)
				{
					yl = 2;
					if (ene[22] == false && ene[23] == false && ene[24] == false && ene[25] == false && ene[26] == false && ene[27] == false && ene[28] == false && ene[29] == false && ene[30] == false && ene[31] == false && ene[32] == false)
					{
						yl = 1;
						if (ene[11] == false && ene[12] == false && ene[13] == false && ene[14] == false && ene[15] == false && ene[16] == false && ene[17] == false && ene[18] == false && ene[19] == false && ene[20] == false && ene[21] == false)
						{
							yl = 0;
						}
					}
				}
			}
			if (life == 0)
			{
				win = false;
				break;
			}
			gotoxy(0, h + 30);
			cout << "score: " << score << "\tLife: " << life << "   ";
		}
		// cleaning
		drawLine(0, 5, w, 5, 0);
		cls();
		showConsoleCursor(true);
		gotoxy(0, h + 30);
		if (win)
			cout << "You won\tYour score: " << score << "\nPress anything except 0 to play again.";
		else
			cout << "You lost\nPress anything except 0 to play again.";
		cout << endl;
		cout << w << "\t" << h << "a";
		getWindowDimensions(w, h);
		cout << w << "\t" << h << "a";
		getch();
		cin >> play;
		if (play == 0)
			break;
	}
	return 0;
}