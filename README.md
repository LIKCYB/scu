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
```cpp
#include "scu.h"
int scuui::ScuMain(HINSTANCE AppInstanceHandle){
  scuui::SMainWindow.Reset("Hello",100,100,300,300);
  scuui::SMainWindow.Show();
  scuui::SApp.Execute();
  return 0;
}```
解释：
ScuMain是scu的主函数，在完成一些初始化操作后会从此函数的第一条语句执行
调用SMainWindow.Reset在内存中创建窗口
调用SMainWindow.Show显示此窗口
调用SApp.Execute进行消息处理并保持运行(调用SApp.Exit()会终止SApp.Execute()的运行)
SMainWindow定义在scuui/SMainWindow.h
