# BIT2024软工大三小学期QT项目 车载中控系统 #
## 简介 ##
主界面UI如下，该项目的语音模块调用百度云智能语音识别api。
![image](https://github.com/user-attachments/assets/e388b394-b4b5-4802-a1a3-a5fedb4aae5b)
## 运行环境 ##
> QtCreator 6.7 
## 项目模块介绍 ## 
- 即时通讯模块；
使用Postgresql存储用户数据实现登录功能。这意味着如果你下载了这个项目，想要成功使用该模块，必须连接上自己的Postgresql本地数据库，否则无法登录。。该模块采用TCP/IP协议和Socket通讯。并使用了线程池技术编写服务器端。用户能够发送emoji表情，支持语音转文字，可以保存聊天历史记录
![image](https://github.com/user-attachments/assets/ac14b864-a67a-4a1e-bb16-841977f1521c)
![image](https://github.com/user-attachments/assets/b3446502-0997-4e18-8d9c-bb8c13580500)


- 音乐播放模块：
播放器界面歌曲添加/删除按钮，可以实现歌曲的自由选择添加/删除。播放/暂停按钮，播放模式切换。提供三种播放模式供选择切换，单曲循环、顺序播放、随机播放。
![image](https://github.com/user-attachments/assets/d3e36b38-0f79-4f7f-a29e-c11423c2690b)

- 天气预报模块：
模块提供七日的气象信息，及当日注意提醒。可以搜索全国范围内某城市天气信息。支持语音查询天气信息。
![image](https://github.com/user-attachments/assets/f42c5553-970f-47aa-b2ba-582d7a7514e4)

- 视频播放模块：
有自主选择播放视频，实现播放、暂停、关闭、音量调节，进度调节等功能。
![image](https://github.com/user-attachments/assets/2d5e9a22-deb7-48a8-9496-80f126a4a718)


- 图片浏览模块：
能够浏览图片，以及单图放大浏览。单图浏览时实现上一张、下一张、放大、缩小、左旋、右旋等功能。

- 定位导航：
通过 API 静态获取百度地图，显示地图功能，地图拖动功能。
![image](https://github.com/user-attachments/assets/229eacb1-82cb-4102-8b2a-9d6bb4a5e2c6)

