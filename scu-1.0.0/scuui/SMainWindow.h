
//#include"../scu.h"
namespace scuui{
    class SMainWindow_{

    public:
        bool Reset(const char* WindowTitle,unsigned X,unsigned Y,unsigned Width,unsigned int Height){
            //scuui::scusystem::ScuWindowClass.style = CS_HREDRAW | CS_VREDRAW;
            scuui::scusystem::ScuWindowClass.lpfnWndProc = scuui::scusystem::WndProc;
            scuui::scusystem::ScuWindowClass.cbClsExtra = 0;
            scuui::scusystem::ScuWindowClass.cbWndExtra = 0;
            scuui::scusystem::ScuWindowClass.hInstance = scuui::scusystem::AppInstanceHandle;
            scuui::scusystem::ScuWindowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
            scuui::scusystem::ScuWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
            scuui::scusystem::ScuWindowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
            scuui::scusystem::ScuWindowClass.lpszMenuName = NULL;
            scuui::scusystem::ScuWindowClass.lpszClassName = "ScuWindow";
            if(!RegisterClass(&scuui::scusystem::ScuWindowClass))return false;
            scuui::scusystem::MainWindowHandle = CreateWindowEx(0,"ScuWindow",WindowTitle,WS_OVERLAPPEDWINDOW,X,Y,Width,Height,NULL,NULL,scuui::scusystem::AppInstanceHandle,NULL);
            return (scuui::scusystem::MainWindowHandle != NULL);
        }
        bool Show(){
            return (ShowWindow(scuui::scusystem::MainWindowHandle,SW_SHOW) == TRUE);
        }
    }SMainWindow;
}
