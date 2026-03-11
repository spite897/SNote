# buildLog
- program: **sharedfolder_by_samba**
- status: **done**

-----------------------------------------------------------------------------

> 通过 *samba* 在 Arch Linux 上创建共享文件夹 然后在 Windows 上访问

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

在默认配置后添加

```conf
#/etc/samba/smb/conf
...
[ArchShare]
    comment = Arch Shared Folder
    path = <path>
    browseable = yes
    read only = no
    valid users = <usr_name>
```

赋予文件夹权限 并添加用户密码 启动服务

```bash
chmod 777 <path>
sudo smbpasswd -a <usr_name>
systemctl start smb nmb
```

在 Windows 10 访问 Arch 的局域网IP后登陆即可

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

> 后记
> - 不知道为什么访问速度很慢 大概是运营商的网络不稳
> - 我完成凭借 Gemini 3.1 Pro 
> - - Bing 搜寻博客 不准确 没有时效
> - - 查阅 Archwiki 效率低 花费时间

-----------------------------------------------------------------------------
