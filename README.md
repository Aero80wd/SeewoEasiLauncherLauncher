# 希沃启动器
## 简介
本软件基于**C++ Qt6**编写而成，使用本软件，请先安装希沃白板，否则将无法使用。
## 安装方法
1、先进入[Release](https://github.com/Aero80wd/SeewoEasiNoteLauncher/Release)界面，下载最新版本的软件。<br/>
2、打开安装程序，点击安装。
## ![image](https://github.com/Aero80wd/SeewoEasiNoteLauncher/assets/98873438/3b46a55f-364d-4934-811f-e802cef59a92)
3、进入**C:\Program Files (x86)\Seewo\EasiNote5\swenlauncher**目录，打开**config.json**文件<br/>
您会看到以下json文本:<br/>
``` json
{
    "background": "",
    "cap": "Launcher By Aero8m\n抵制不良作风，拒绝摆烂心态，注意自我保护，谨防受骗上当，适度教学益脑，拖堂教学伤身，合理安排时间，享受快乐学习。\nCopyright © 2011-2024 Guangzhou Shirui. All Rights Reserved",
    "exec": "C:\\Program Files (x86)\\Seewo\\EasiNote5\\swenlauncher\\backup\\swenlauncher.exe",
    "title": "希沃白板"
}
```
如果您想要设置背景图片（默认是透明），请修改background字段，填入图片路径，如:
``` json
{
    "background": "C:/Program Files (x86)/Seewo/EasiNote5/swenlauncher/381.jpg",
    "cap": "Launcher By Aero8m\n抵制不良作风，拒绝摆烂心态，注意自我保护，谨防受骗上当，适度教学益脑，拖堂教学伤身，合理安排时间，享受快乐学习。\nCopyright © 2011-2024 Guangzhou Shirui. All Rights Reserved",
    "exec": "C:\\Program Files (x86)\\Seewo\\EasiNote5\\swenlauncher\\backup\\swenlauncher.exe",
    "title": "希沃白板"
}
```
然后，您就可以在真正的希沃大屏上~~装逼~~了。
