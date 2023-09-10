namespace scuui{
    class SPushButton{
    private:
        int *_cId = new int;
    public:
        SPushButton(){
            (*_cId) = (scuui::scusystem::AllControlIds ++);
            scuui::scusystem::Controls.insert(std::pair<int,scuui::scusystem::Control>((*_cId),(*(new scuui::scusystem::Control))));
        }
        SPushButton(const char* Caption,unsigned int X,unsigned int Y,unsigned int Width,unsigned int Height){
            (*_cId) = scuui::scusystem::AllControlIds;scuui::scusystem::AllControlIds += 1;
            scuui::scusystem::Controls.insert(std::pair<int,scuui::scusystem::Control>((*_cId),(*(new scuui::scusystem::Control))));
            scuui::scusystem::Controls[*_cId].Caption = const_cast<char*>(Caption);
            scuui::scusystem::Controls[*_cId].x = X;
            scuui::scusystem::Controls[*_cId].y = Y;
            scuui::scusystem::Controls[*_cId].width = Width;
            scuui::scusystem::Controls[*_cId].height = Height;
            scuui::scusystem::Controls[*_cId].eventid = *((HMENU*)_cId);
        }
        ~SPushButton(){
            DestroyWindow(scuui::scusystem::Controls[*_cId].handle);
        }
        bool PutOnMainWindow(){//在SMainWindow类AddControl()调用，不需要调用此函数。
            scuui::scusystem::Controls[*_cId].handle = CreateWindowEx(0,TEXT("BUTTON"),scuui::scusystem::Controls[*_cId].Caption,WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                                                                     scuui::scusystem::Controls[*_cId].x,scuui::scusystem::Controls[*_cId].y,scuui::scusystem::Controls[*_cId].width,scuui::scusystem::Controls[*_cId].height,
                                                                     scuui::scusystem::MainWindowHandle,scuui::scusystem::Controls[*_cId].eventid,scuui::scusystem::AppInstanceHandle,NULL);
            ShowWindow(scuui::scusystem::Controls[*_cId].handle,SW_SHOW);
            return (scuui::scusystem::Controls[*_cId].handle != NULL);
        }
        void SetEvents(scuui::SEvent EventId,void(* EventFunctionPtr)()){
            if(EventId == scuui::SEvent_Click){
                scuui::scusystem::Controls[*_cId].ClickEvent = EventFunctionPtr;
            }else{
                throw scuui::this_event_is_not_supported("This event is not supported");
            }
        }

        bool Show(){
            return (ShowWindow(scuui::scusystem::Controls[*_cId].handle,SW_SHOW) == TRUE);
        }
        bool Hide(){
            return (ShowWindow(scuui::scusystem::Controls[*_cId].handle,SW_HIDE) == TRUE);
        }
        bool SetVisiable(bool VisiableBool){
            if(VisiableBool){
                return (ShowWindow(scuui::scusystem::Controls[*_cId].handle,SW_SHOW) == TRUE);
            }else{
                return (ShowWindow(scuui::scusystem::Controls[*_cId].handle,SW_HIDE) == TRUE);
            }
        }
        char* Caption(int MaxDataSize){
            char* _rV = (char*)malloc(sizeof(char) * MaxDataSize);
            GetWindowText(scuui::scusystem::Controls[*_cId].handle,_rV,MaxDataSize);
            return _rV;
        }
        bool Caption(const char* NewCaption){
            return (SetWindowText(scuui::scusystem::Controls[*_cId].handle,const_cast<char*>(NewCaption)) == TRUE);
        }
        bool Reset(unsigned int X,unsigned int Y,unsigned int Width,unsigned int Height){
            return (MoveWindow(scuui::scusystem::Controls[*_cId].handle,X,Y,Width,Height,TRUE) == TRUE);
        }
        unsigned int X(){
            return scuui::scusystem::Controls[*_cId].x;
        }
        unsigned int Y(){
            return scuui::scusystem::Controls[*_cId].y;
        }
        unsigned int width(){
            return scuui::scusystem::Controls[*_cId].width;
        }
        unsigned int height(){
            return scuui::scusystem::Controls[*_cId].height;
        }
        bool X(unsigned int X){
            scuui::scusystem::Controls[*_cId].x = X;
            return (MoveWindow(scuui::scusystem::Controls[*_cId].handle,scuui::scusystem::Controls[*_cId].x,scuui::scusystem::Controls[*_cId].y,scuui::scusystem::Controls[*_cId].width,scuui::scusystem::Controls[*_cId].height,TRUE) == TRUE);
        }
        bool Y(unsigned int Y){
            scuui::scusystem::Controls[*_cId].y = Y;
            return (MoveWindow(scuui::scusystem::Controls[*_cId].handle,scuui::scusystem::Controls[*_cId].x,scuui::scusystem::Controls[*_cId].y,scuui::scusystem::Controls[*_cId].width,scuui::scusystem::Controls[*_cId].height,TRUE) == TRUE);
        }
        bool Width(unsigned int NewWidth){
            scuui::scusystem::Controls[*_cId].width = NewWidth;
            return (MoveWindow(scuui::scusystem::Controls[*_cId].handle,scuui::scusystem::Controls[*_cId].x,scuui::scusystem::Controls[*_cId].y,scuui::scusystem::Controls[*_cId].width,scuui::scusystem::Controls[*_cId].height,TRUE) == TRUE);
        }
        bool Height(unsigned int NewHeight){
            scuui::scusystem::Controls[*_cId].height = NewHeight;
            return (MoveWindow(scuui::scusystem::Controls[*_cId].handle,scuui::scusystem::Controls[*_cId].x,scuui::scusystem::Controls[*_cId].y,scuui::scusystem::Controls[*_cId].width,scuui::scusystem::Controls[*_cId].height,TRUE) == TRUE);
        }
        bool SetEnable(bool EnableBool){
            return (EnableWindow(scuui::scusystem::Controls[*_cId].handle,(EnableBool ? TRUE : FALSE)) == TRUE);
        }
    };
}
