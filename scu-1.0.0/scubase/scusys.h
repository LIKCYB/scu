namespace scuui{
    namespace scusystem{
        HINSTANCE AppInstanceHandle;

        struct Control{
            void (*ClickEvent)();
            char* Caption;
            unsigned int x,y,width,height;
            HMENU eventid;
            HWND handle;
        };
        std::map<int,Control> Controls;

        HWND MainWindowHandle;

        WNDCLASS ScuWindowClass;

        MSG Message;

        int AllControlIds = 10000;

        LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
            if(message == WM_CREATE){
                return 0;
            }
            if(message == WM_SIZE){
                return 0;
            }
            if(message == WM_PAINT){
                return 0;
            }
            if(message == WM_DESTROY){
                PostQuitMessage(0);
                return 0;
            }
            //������Ҫ�������Ϣ���ݸ�ϵͳ��Ĭ�ϴ���
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
    }
}
