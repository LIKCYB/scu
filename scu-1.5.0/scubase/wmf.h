namespace scuui{
    int ScuMain(HINSTANCE AppInstanceHandle);
}
int WINAPI WinMain (HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow){
    scuui::scusystem::AppInstanceHandle = hThisInstance;
    return scuui::ScuMain(hThisInstance);
}
