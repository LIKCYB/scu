namespace scuui{
    namespace scusystem{
        HINSTANCE AppInstanceHandle;

        struct Control{
            void (*ClickEvent)();
            char* Caption;
            unsigned int x,y,width,height;
            HMENU eventid;
            HWND handle;
            bool enabled = true;
        };
        std::map<int,Control> Controls;

        HWND MainWindowHandle;

        WNDCLASS ScuWindowClass;

        MSG Message;

        int AllControlIds = 100;

        LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
            if(message == WM_CREATE){
                return 0;
            }
            if(message == WM_SIZE){
                return 0;
            }
            /*if(message == WM_PAINT){
                return 0;
            }*/
            if(message == WM_DESTROY){
                PostQuitMessage(0);
                return 0;
            }
            if(message == WM_COMMAND){
                if(scuui::scusystem::Controls[(int)wParam].ClickEvent){
                    (*scuui::scusystem::Controls[(int)wParam].ClickEvent)();
                }
            }
            if(message == WM_UPDATEUISTATE){
                return 0;
            }
            //将不需要处理的消息传递给系统作默认处理
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
    }
}
