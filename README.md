# scu
SCU(Simple C++ UI)，是一个能让你使用win32 api创建UI时更简便的C++工具库

### [!]使用时的注意事项 ###
1.不应该修改命名空间"scuui::scusystem"内的任何变量，这会导致程序出现严重异常  
2.不应该调用控件类的"PutOnMainWindow()"函数，此函数会将控件添加到主窗口，此函数由"SMainWindow::AddControl()"调用

#### 1.实现 ####
这个库只是将win32 api的gui部分封装为类以实现简便创建gui

#### 2.示例 ####
示例1，在x坐标100和y坐标100处创建一个标题为Hello的300*300大小的窗口  
```c++
#include "scu.h"
int scuui::ScuMain(HINSTANCE AppInstanceHandle){
  scuui::SMainWindow.Reset("Hello",100,100,300,300);
  scuui::SMainWindow.Show();
  scuui::SApp.Execute();
  return 0;
}
//解释：
//ScuMain是scu的主函数，在完成一些初始化操作后会从此函数的第一条语句执行
//调用SMainWindow.Reset在内存中创建窗口
//调用SMainWindow.Show显示此窗口
//调用SApp.Execute进行消息处理并保持运行(调用SApp.Exit()会终止SApp.Execute()的运行)
//SMainWindow定义在scuui/SMainWindow.h
```  
示例2，创建一个带有退出按钮的窗口(需要使用scu 1.5.0及以上的版本)  
```c++
#include"scu.h"
void ExitApp(){
  scuui::SApp.Exit();
}
int scuui::ScuMain(HINSTANCE AppInstanceHandle){
  scuui::SMainWindow.Reset("Hello",100,100,300,300);
  scuui::SPushButton ExitButton("退出程序",0,0,100,40);
  ExitButton.SetEvents(scuui::SEvent_Click,ExitApp);
  scuui::SMainWindow.AddControl(ExitButton);
  scuui::SMainWindow.Show();
  scuui::SApp.Execute();
  return 0;
}
//调用SetEvents将ExitButton的Event_Click(单击)事件响应函数设置为ExitApp()
//调用AddControl将ExitButton添加到主窗口上
```  
#### 3.更新日志 ####
> 1.0.0 · 2023-9-9-8:30
 >> scu的第一个版本

> 1.5.0 · 2023-9-9-11:25
 >> 添加了SPushButton类  
 >> 添加了this_event_is_not_supported异常(设置不可以的行为时抛出)

> 1.6.0 · 2023-9-9-22:50
 >> 为scuui::SMainWindow类和所有控件类添加了Show()、Hide()、SetVisiable()函数设置可见性  
 >> 为scuui::SMainWindow类添加了Title()函数修改和获取窗口标题，为大部分控件类类添加了Caption()函数修改和获取控件上的文字  
 >> 为scuui::SMainWindow类和所有控件类添加了Reset()函数设置长、宽、X坐标、Y坐标

> 2.0.5  · 2023-9-10-10:40
 >> 为scuui::SMainWindow类和全部控件类添加了X()、Y()、Width()、Height()函数单独设置或获取X坐标，Y坐标，宽，高  
 >> 添加STextEdit类(输入框)  
 >> 为全部控件类添加了SetEnable()函数设置是否禁用   
