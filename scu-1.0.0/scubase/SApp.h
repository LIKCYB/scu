namespace scuui{
    class SApp_{
    private:
        bool _run = true;
    public:
        void Execute(){
            while(GetMessage(&scuui::scusystem::Message, NULL, 0, 0) && _run){
                TranslateMessage(&scuui::scusystem::Message);
                DispatchMessage(&scuui::scusystem::Message);
            }
        }
        void Exit(){
            _run = false;
        }
    }SApp;
}
