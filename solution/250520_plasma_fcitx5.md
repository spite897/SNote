# buildLog
- program: **arch-kde-plasma_fcitx5_solution**
- from: [csdn/IcyLightDream](https://blog.csdn.net/orangebench11/article/details/139381701 )
- status: **done**

--------
> AUR packs
> - ~~plasma6-wallpapers-wallpaper-engine-git~~
> - fcitx5-input-support

> pacman packs
> - fcitx5-im fcitx5-rime
--------
## Add archlinuxcn source & multilib source
edit config file
```
#/etc/pacman.conf

[archlinuxcn]
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch

[multilib]
Include = /etc/pacman.d/mirrorlist

```
Then command
```zsh
#terminal
$ sudo pacman-key --lsign-key "farseerfc@archlinux.org"
$ pacman -Sy archlinuxcn-keyring
```
expected output :
![expection1](/imgs/250520_plasma_fcitx5_solution/expection1.png)
![expection2](/imgs/250520_plasma_fcitx5_solution/expection2.png)

## Input method installation
After installing all **required packs** , `settings -> virtual keyboard` (plasma DesktopManaher) turn on **Fcitx 5 Wayland Laucher(expriment)** . 

Reboot then it will be available.


