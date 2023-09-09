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
    };
}
