#include <graphics.h>
#include<iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <windows.h> 



#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define KEY_UP(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 0:1)
std::vector<std::string> imagePaths;



//-leasyx -lgdi32 -lole32


IMAGE image[110], bg, stopimage, ow;
int currentImageIndex = 0;

void input(char c){
	
	keybd_event(c, (BYTE)0, 0, 0);
	keybd_event(c, (BYTE)0, KEYEVENTF_KEYUP, 0);
	
}

void simulateKeyInput(int key)
{
    // 构造 INPUT 结构体
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;

    // 发送输入
    SendInput(1, &input, sizeof(input));
}

void refresh(void){
	
	cleardevice();
	putimage(0, 0, &bg); 
	putimage(0, 0, &image[currentImageIndex]); 
	if (currentImageIndex == 10) 
	    putimage(64, 0, &image[0]);
	else 
	    putimage(64, 0, &image[currentImageIndex + 1]);
	
}

int main()
{
    // 初始化图形环境
    initgraph(128, 64);
	//HWND hWnd = GetHWnd();
	//SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_CAPTION);
    
    loadimage(&stopimage, _T("image/stop.png"), 128, 64, true);
    loadimage(&bg, _T("image/bgimage.png"), 128, 64, true);
    loadimage(&ow, _T("image/onwork.png"), 128, 64, true);
    loadimage(&image[1], _T("image/image1.png"), 64, 64, true);
	loadimage(&image[2], _T("image/image2.png"), 64, 64, true);
	loadimage(&image[3], _T("image/image3.png"), 64, 64, true);
    loadimage(&image[4], _T("image/image4.png"), 64, 64, true);
	loadimage(&image[5], _T("image/image5.png"), 64, 64, true);
	loadimage(&image[6], _T("image/image6.png"), 64, 64, true);
    loadimage(&image[7], _T("image/image7.png"), 64, 64, true);
	loadimage(&image[8], _T("image/image8.png"), 64, 64, true);
	loadimage(&image[9], _T("image/image9.png"), 64, 64, true);
	loadimage(&image[10], _T("image/image10.png"), 64, 64, true);//加载图片
	
        // 获取当前窗口句柄
    HWND hwnd = GetForegroundWindow();

    // 将窗口置顶
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    // 准备图片路径
    //imagePaths.push_back("image1.png");
    //imagePaths.push_back("image2.png");
    //imagePaths.push_back("image3.png");
    
     //显示图片
	//cleardevice();
    // 当前显示的图片索引
    
    
    putimage(0, 0, &ow); 
    bool stop = false;

    // 是否正在按住 Ctrl 键
    bool isCtrlPressed = false;

    while (true)
    {

		if(KEY_DOWN(112))
		{
			stop = !stop;
			cleardevice(); 
			putimage(0, 0, &stopimage);
			Sleep(200);
		}
		while(stop)
		{
			if(KEY_DOWN(112))
			{
				stop = false;
				cleardevice();
				putimage(0, 0, &ow);
				Sleep(200);
			}
		}

        // 如果用户按下 Ctrl 键
        if (KEY_DOWN(17))
        {
            isCtrlPressed = true;
            refresh();
        }
        // 如果用户按下 F 键
        if (KEY_DOWN('D') && isCtrlPressed)
        {
            // 切换到上一张图片
            currentImageIndex--;
            if (currentImageIndex < 0)
            {
                currentImageIndex = 10;
            }
            refresh();
            Sleep(150);
        }
        // 如果用户按下 J 键
        if (KEY_DOWN('J') && isCtrlPressed)
        {
            // 切换到下一张图片
            currentImageIndex++;
            if (currentImageIndex > 10)
            {
                currentImageIndex = 0;
            }
            refresh();
            Sleep(150);
        }
        // 如果用户松开 Ctrl 键
        if (KEY_UP(17) && isCtrlPressed)
        {
            isCtrlPressed = false;
			// 执行当前图片对应的操作
			if (currentImageIndex == 1)
			{
			    // 模拟输入 [微笑]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(83, 0x1F, 0, 0);
			    keybd_event(83, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(77, 0x1F, 0, 0);
			    keybd_event(77, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(73, 0x1F, 0, 0);
			    keybd_event(73, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(76, 0x1F, 0, 0);
			    keybd_event(76, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(69, 0x1F, 0, 0);
			    keybd_event(69, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			}
			else if (currentImageIndex == 2)
			{
			    // 模拟输入 [Doge]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
				//Capital
			    keybd_event(68, 0x1F, 0, 0);
			    keybd_event(68, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(79, 0x1F, 0, 0);
			    keybd_event(79, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(71, 0x1F, 0, 0);
			    keybd_event(71, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(69, 0x1F, 0, 0);
			    keybd_event(69, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    
			}
			else if (currentImageIndex == 3)
			{
			    // 模拟输入 [ThumbsUp]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
				//Capital
			    keybd_event(84, 0x1F, 0, 0);
			    keybd_event(84, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(72, 0x1F, 0, 0);
			    keybd_event(72, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(85, 0x1F, 0, 0);
			    keybd_event(85, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(77, 0x1F, 0, 0);
			    keybd_event(77, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(66, 0x1F, 0, 0);
			    keybd_event(66, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(83, 0x1F, 0, 0);
			    keybd_event(83, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
			    //capital
			    keybd_event(85, 0x1F, 0, 0);
			    keybd_event(85, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(80, 0x1F, 0, 0);
			    keybd_event(80, 0x1F, KEYEVENTF_KEYUP, 0);
			    
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			}
			else if (currentImageIndex == 4)
			{
			    // 模拟输入 [Hurt]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
				//Capital
				keybd_event(72, 0x1F, 0, 0);
			    keybd_event(72, 0x1F, KEYEVENTF_KEYUP, 0); 
				//end
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(85, 0x1F, 0, 0);
			    keybd_event(85, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(82, 0x1F, 0, 0);
			    keybd_event(82, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(84, 0x1F, 0, 0);
			    keybd_event(84, 0x1F, KEYEVENTF_KEYUP, 0); 
			    //end
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    
			}
			else if (currentImageIndex == 5)
			{
			    // 模拟输入 [Smirk]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
				//Capital
				keybd_event(83, 0x1F, 0, 0);
			    keybd_event(83, 0x1F, KEYEVENTF_KEYUP, 0); 
				//end
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(77, 0x1F, 0, 0);
			    keybd_event(77, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(73, 0x1F, 0, 0);
			    keybd_event(73, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(82, 0x1F, 0, 0);
			    keybd_event(82, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(75, 0x1F, 0, 0);
			    keybd_event(75, 0x1F, KEYEVENTF_KEYUP, 0); 
			    //end
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    
			}
			else if (currentImageIndex == 6)
			{
			    // 模拟输入 [Concerned]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
				//Capital
				keybd_event(67, 0x1F, 0, 0);
			    keybd_event(67, 0x1F, KEYEVENTF_KEYUP, 0);
				//end
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(79, 0x1F, 0, 0);
			    keybd_event(79, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(78, 0x1F, 0, 0);
			    keybd_event(78, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(67, 0x1F, 0, 0);
			    keybd_event(67, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(69, 0x1F, 0, 0);
			    keybd_event(69, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(82, 0x1F, 0, 0);
			    keybd_event(82, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(78, 0x1F, 0, 0);
			    keybd_event(78, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(69, 0x1F, 0, 0);
			    keybd_event(69, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(68, 0x1F, 0, 0);
			    keybd_event(68, 0x1F, KEYEVENTF_KEYUP, 0);
			    //end
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    
			}
			else if (currentImageIndex == 7)
			{
			    // 模拟输入 [Broken]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
				//Capital
				keybd_event(66, 0x1F, 0, 0);
			    keybd_event(66, 0x1F, KEYEVENTF_KEYUP, 0);
				//end
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(82, 0x1F, 0, 0);
			    keybd_event(82, 0x1F, KEYEVENTF_KEYUP, 0);
				keybd_event(79, 0x1F, 0, 0);
			    keybd_event(79, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(75, 0x1F, 0, 0);
			    keybd_event(75, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(69, 0x1F, 0, 0);
			    keybd_event(69, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(78, 0x1F, 0, 0);
			    keybd_event(78, 0x1F, KEYEVENTF_KEYUP, 0);
			    //end
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    
			}
			else if (currentImageIndex == 8)
			{
			    // 模拟输入 [Sigh]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
				//Capital
				keybd_event(83, 0x1F, 0, 0);
			    keybd_event(83, 0x1F, KEYEVENTF_KEYUP, 0);
				//end
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(73, 0x1F, 0, 0);
			    keybd_event(73, 0x1F, KEYEVENTF_KEYUP, 0);
				keybd_event(71, 0x1F, 0, 0);
			    keybd_event(71, 0x1F, KEYEVENTF_KEYUP, 0);
				keybd_event(72, 0x1F, 0, 0);
			    keybd_event(72, 0x1F, KEYEVENTF_KEYUP, 0);
			    //end
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    
			}
			else if (currentImageIndex == 9)
			{
			    // 模拟输入 [Awkward]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
				//Capital
				keybd_event(65, 0x1F, 0, 0);
			    keybd_event(65, 0x1F, KEYEVENTF_KEYUP, 0);
				//end
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(87, 0x1F, 0, 0);
			    keybd_event(87, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(75, 0x1F, 0, 0);
			    keybd_event(75, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(87, 0x1F, 0, 0);
			    keybd_event(87, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(65, 0x1F, 0, 0);
			    keybd_event(65, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(82, 0x1F, 0, 0);
			    keybd_event(82, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(68, 0x1F, 0, 0);
			    keybd_event(68, 0x1F, KEYEVENTF_KEYUP, 0);
			    //end
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    
			}
			else if (currentImageIndex == 10)
			{
			    // 模拟输入 [Lol]
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(219, 0x1F, 0, 0);
			    keybd_event(219, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(16, 0x1F, 0, 0);
				//Capital
				keybd_event(76, 0x1F, 0, 0);
			    keybd_event(76, 0x1F, KEYEVENTF_KEYUP, 0);
				//end
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    //normal
			    keybd_event(79, 0x1F, 0, 0);
			    keybd_event(79, 0x1F, KEYEVENTF_KEYUP, 0);
			    keybd_event(76, 0x1F, 0, 0);
			    keybd_event(76, 0x1F, KEYEVENTF_KEYUP, 0);
			    //end
			    keybd_event(221, 0x1F, 0, 0);
			    keybd_event(221, 0x1F, KEYEVENTF_KEYUP, 0); 
			    keybd_event(16, 0x1F, 0, 0);
			    keybd_event(16, 0x1F, KEYEVENTF_KEYUP, 0);
			    
			}
            // 执行当前图片对应的操作
            // ...

            // 清除屏幕上的图片
            cleardevice();
            putimage(0, 0, &ow); 
        }
    } 
} 

/*
#include <easyx.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// 定义图片路径数组
vector<string> imagePaths = {"image1.jpg", "image2.jpg", "image3.jpg"};

// 当前显示的图片索引
int currentImageIndex = 0;

// 判断按键是否按下
bool isKeyPressed(int keyCode)
{
    return GetAsyncKeyState(keyCode) & 0x8000;
}

int main()
{
    // 初始化图形界面
    initgraph(640, 480);

    // 显示第一张图片
    currentImageIndex = 0;
    IMAGE image;
    loadimage(image, imagePaths[currentImageIndex].c_str());
    putimage(0, 0, &image);

    // 主循环
    while (true)
    {
        // 如果按下 Ctrl 键
        if (isKeyPressed(VK_CONTROL))
        {
            // 循环处理键盘输入
            while (true)
            {
                // 如果按下 F 键，则显示上一张图片
                if (isKeyPressed(VK_F))
                {
                    currentImageIndex = (currentImageIndex + imagePaths.size() - 1) % imagePaths.size();
                    loadimage(image, imagePaths[currentImageIndex].c_str());
                    putimage(0, 0, &image);
                }
                // 如果按下 J 键，则显示下一张图片
                else if (isKeyPressed(VK_J))
                {
                    currentImageIndex = (currentImageIndex + 1) % imagePaths.size();
                    loadimage(image, imagePaths[currentImageIndex].c_str());
                    putimage(0, 0, &image);
                }
                // 如果松开 Ctrl 键，则退出循环
                else if (!isKeyPressed(VK_CONTROL))
                {
                    break;
                }
                Sleep(100);  // 延时 100 毫秒
            }
        }
    }

    return 0;
}
*/
