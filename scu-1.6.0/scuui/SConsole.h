namespace scuui{
    class SConsole_{
    public:
        void Hide(){
            HWND CmdHwnd;
            CmdHwnd = FindWindow("ConsoleWindowClass",NULL);
            if(CmdHwnd){
                ShowWindow(CmdHwnd,SW_HIDE);
            }
        }
        void Show(){
            HWND CmdHwnd;
            CmdHwnd = FindWindow("ConsoleWindowClass",NULL);
            if(CmdHwnd){
                ShowWindow(CmdHwnd,SW_SHOW);
            }
        }
    }SConsole;
}
