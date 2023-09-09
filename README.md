# scu
SCU(Simple C++ UI)是一个基于win32 api实现的C++ UI工具库  
此库正在开发中，因此有一些功能可能不完整  

#### 1.源代码 ####
源代码基于MIT协议发布  

#### 2.优点 ####
无依赖，包含"scu.h"头文件即可使用(请确保scu没有缺失的头文件)  
简易，不需要进行消息处理，可以直接使用SetEvents设置控件事件  

#### 3.缺点 ####
仅支持windows系统  
UI风格较旧  

#### 4.示例 ####
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
示例2，创建一个带有退出按钮的窗口  
```c++
#include"scu.h"
void ExitApp(){
  scuui::SApp.Exit();
}
int scuui::ScuMain(HINSTANCE AppInstanceHandle){
  scuui::SMainWindow.Reset("Hello",100,100,300,300);
  scuui::SPushButton ExitButton("退出程序",0,0,100,40);
  ExitButton.SetEvents(scuui::Event_Click,ExitApp);
  scuui::SMainWindow.AddControl(ExitButton);
  scuui::SMainWindow.Show();
  scuui::SApp.Execute();
  return 0;
}
//调用SetEvents将ExitButton的Event_Click(单击)事件响应函数设置为ExitApp()
//调用AddControl将ExitButton添加到主窗口上
```  
#### 5.更新日志 ####
> 1.0.0 发布于2023-9-9-8:30
 >> scu的第一个版本

> 1.5.0 发布于2023-9-9-11:25
 >> 添加了SPushButton类
 >> 添加了this_event_is_not_supported异常(设置不可以的行为时抛出)

#### 6.附属包 ####
附属包为额外的工具，并不属于GUI范畴，可以帮助你制作更好的软件  
附属包大部分有dll文件，其源代码可在对应包目录的DllFileSrc文件夹找到

#### 7.帮助 ####
> SetEvents函数  
 >> SetEvents定义在大多数控件类里
 >> 函数原型是`void SetEvents(scuui::SEvent EventId,void(* EventFunctionPtr)())`
 >> 第一个参数需要传入事件ID号，相应的ID号在scuevent/se.h定义，第二个参数需要传入一个返回值为void的无参数函数指针，在事件触发时会调用此函数

> AddControl函数
 >> AddControl函数定义在窗口类中，使用AddControl可以将一个控件添加到窗口里，将此控件对象传入函数即可

> this_event_is_not_supported异常  
 >> 在使用SetEvents()时可能抛出
 >> 具体原因：设置了不支持的事件
  
  
不会写README.md....
