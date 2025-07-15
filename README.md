# 网络音箱校准软件

这是一个简单的示例脚本，用于演示如何对多台网络音箱进行校准。脚本会依次向指定的音箱发送测试音，并模拟测量返回的延迟和音量等级。

## 使用方法

1. 确保已在 Python 环境中安装所需的音频播放与录制库（例如 `sounddevice`）。
2. 运行脚本并在命令行参数中提供音箱 IP 地址：

```bash
python network_speaker_calibration.py 192.168.1.10 192.168.1.11
```

脚本会输出每个音箱的测量结果，真实场景下可根据测量数据调整音箱设置。

此脚本仅为示例，具体实现需要结合实际硬件和音频处理库。 

## Ubus 同步播放示例

项目中还包含 `speaker_sync.c`，演示如何通过 Ubus 提供 `start_sweep` 接口。
程序在 Buildroot 交叉编译工具链下编译，编译方法：

```bash
make CROSS=<toolchain-prefix>
```

运行后会注册 `speaker.sync` 对象，可使用 `ubus call speaker.sync start_sweep` 来启动四个音箱的扫频播放与录制流程（示例中仅输出提示信息）。

真实应用中需要根据具体硬件实现播放与录音功能。
