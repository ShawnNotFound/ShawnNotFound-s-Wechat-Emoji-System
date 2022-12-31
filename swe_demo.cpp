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
    // ���� INPUT �ṹ��
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;

    // ��������
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
    // ��ʼ��ͼ�λ���
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
	loadimage(&image[10], _T("image/image10.png"), 64, 64, true);//����ͼƬ
	
        // ��ȡ��ǰ���ھ��
    HWND hwnd = GetForegroundWindow();

    // �������ö�
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    // ׼��ͼƬ·��
    //imagePaths.push_back("image1.png");
    //imagePaths.push_back("image2.png");
    //imagePaths.push_back("image3.png");
    
     //��ʾͼƬ
	//cleardevice();
    // ��ǰ��ʾ��ͼƬ����
    
    
    putimage(0, 0, &ow); 
    bool stop = false;

    // �Ƿ����ڰ�ס Ctrl ��
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

        // ����û����� Ctrl ��
        if (KEY_DOWN(17))
        {
            isCtrlPressed = true;
            refresh();
        }
        // ����û����� F ��
        if (KEY_DOWN('D') && isCtrlPressed)
        {
            // �л�����һ��ͼƬ
            currentImageIndex--;
            if (currentImageIndex < 0)
            {
                currentImageIndex = 10;
            }
            refresh();
            Sleep(150);
        }
        // ����û����� J ��
        if (KEY_DOWN('J') && isCtrlPressed)
        {
            // �л�����һ��ͼƬ
            currentImageIndex++;
            if (currentImageIndex > 10)
            {
                currentImageIndex = 0;
            }
            refresh();
            Sleep(150);
        }
        // ����û��ɿ� Ctrl ��
        if (KEY_UP(17) && isCtrlPressed)
        {
            isCtrlPressed = false;
			// ִ�е�ǰͼƬ��Ӧ�Ĳ���
			if (currentImageIndex == 1)
			{
			    // ģ������ [΢Ц]
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
			    // ģ������ [Doge]
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
			    // ģ������ [ThumbsUp]
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
			    // ģ������ [Hurt]
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
			    // ģ������ [Smirk]
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
			    // ģ������ [Concerned]
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
			    // ģ������ [Broken]
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
			    // ģ������ [Sigh]
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
			    // ģ������ [Awkward]
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
			    // ģ������ [Lol]
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
            // ִ�е�ǰͼƬ��Ӧ�Ĳ���
            // ...

            // �����Ļ�ϵ�ͼƬ
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

// ����ͼƬ·������
vector<string> imagePaths = {"image1.jpg", "image2.jpg", "image3.jpg"};

// ��ǰ��ʾ��ͼƬ����
int currentImageIndex = 0;

// �жϰ����Ƿ���
bool isKeyPressed(int keyCode)
{
    return GetAsyncKeyState(keyCode) & 0x8000;
}

int main()
{
    // ��ʼ��ͼ�ν���
    initgraph(640, 480);

    // ��ʾ��һ��ͼƬ
    currentImageIndex = 0;
    IMAGE image;
    loadimage(image, imagePaths[currentImageIndex].c_str());
    putimage(0, 0, &image);

    // ��ѭ��
    while (true)
    {
        // ������� Ctrl ��
        if (isKeyPressed(VK_CONTROL))
        {
            // ѭ�������������
            while (true)
            {
                // ������� F ��������ʾ��һ��ͼƬ
                if (isKeyPressed(VK_F))
                {
                    currentImageIndex = (currentImageIndex + imagePaths.size() - 1) % imagePaths.size();
                    loadimage(image, imagePaths[currentImageIndex].c_str());
                    putimage(0, 0, &image);
                }
                // ������� J ��������ʾ��һ��ͼƬ
                else if (isKeyPressed(VK_J))
                {
                    currentImageIndex = (currentImageIndex + 1) % imagePaths.size();
                    loadimage(image, imagePaths[currentImageIndex].c_str());
                    putimage(0, 0, &image);
                }
                // ����ɿ� Ctrl �������˳�ѭ��
                else if (!isKeyPressed(VK_CONTROL))
                {
                    break;
                }
                Sleep(100);  // ��ʱ 100 ����
            }
        }
    }

    return 0;
}
*/
