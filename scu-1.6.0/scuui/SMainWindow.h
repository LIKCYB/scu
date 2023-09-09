
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
        bool Hide(){
            return (ShowWindow(scuui::scusystem::MainWindowHandle,SW_HIDE) == TRUE);
        }
        bool SetVisiable(bool VisiableBool){
            if(VisiableBool){
                return (ShowWindow(scuui::scusystem::MainWindowHandle,SW_SHOW) == TRUE);
            }else{
                return (ShowWindow(scuui::scusystem::MainWindowHandle,SW_HIDE) == TRUE);
            }
        }
        char* Title(int MaxDataSize){
            char* _rV = (char*)malloc(sizeof(char) * MaxDataSize);
            GetWindowText(scuui::scusystem::MainWindowHandle,_rV,MaxDataSize);
            return _rV;
        }
        bool Title(const char* NewWindowTitle){
            return (SetWindowText(scuui::scusystem::MainWindowHandle,const_cast<char*>(NewWindowTitle)) == TRUE);
        }
        bool Reset(unsigned int X,unsigned int Y,unsigned int Width,unsigned int Height){
            return (MoveWindow(scuui::scusystem::MainWindowHandle,X,Y,Width,Height,TRUE) == TRUE);
        }
        bool AddControl(scuui::SPushButton &AddControl){
            return AddControl.PutOnMainWindow();
            UpdateWindow(scuui::scusystem::MainWindowHandle);
        }
    }SMainWindow;
}
